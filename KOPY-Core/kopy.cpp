// kopy.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <limits.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

#include <SDL3/SDL.h>

#include "kopy.h"
#include "timer.h"
#include "texturehandler.h"
#include "eventhandler.h"
#include "collisionhandler.h"
#include "objecthandler.h"
#include "ui/texthandler.h"


// Inits
static bool KOPYInitalized = false;
static bool SDLInitalized = false;

// SDL
static SDL_Window* _window = nullptr;
static SDL_Renderer* _renderer = nullptr;
static SDL_Color SCREEN_CLR = { 0, 0, 0, 255 };
static SDL_Color DRAW_CLR = { 255, 255, 255, 255 };
static const SDL_Color NULL_CLR = { 255, 105, 180, 255 };

// Handlers
static KOPY::TextureHandler tHandler;
static KOPY::EventHandler eHandler;
static KOPY::CollisionHandler cHandler;
static KOPY::ObjectHandler objHandler;
static KOPY::TextHandler txtHandler;

// Timing
static int _FPS = 60;
static KOPY::Timer _timer(60);
static float _deltaTime = 1.0f;

// Filepaths
static std::string SCRIPT_PATH;
static std::string ASSETS_PATH = "/assets/";
static std::string FONTS_PATH = ASSETS_PATH + "fonts/";

// Testing
static KOPY::Vec2 _retVec(2, 6);
static const char* _asteroidName = "Asteroid_small.png";
static bool _astInit = false;
static bool _DebugView = true;
static int _ErrorCode = 0;

bool InitKOPY() {
    ERR_HANDLE(KOPYInitalized, "KOPY already initalized", return false);
    ERR_HANDLE(SDLInitalized, "SDL already initalized", return false);
    KOPYInitalized = true;
    return true;
}

bool SetScriptPath(const char* path) {
    SCRIPT_PATH = path;
    return true;
}
bool SetAssetsPath(const char* path) {
    ASSETS_PATH = path;
    FONTS_PATH = ASSETS_PATH + "fonts/";
    return true;
}
bool SetDebugView(bool state) {
    _DebugView = state;
    return true;
}

bool OpenKOPYWindow(int width, int height) {
    ERR_HANDLE(SDLInitalized, "SDL already initalized", return false);
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return false;
    }

    _window = SDL_CreateWindow("SDL_Window", width, height, NULL);
    if (!_window) {
        LOG2(" SDL_CreateWindow error : ", SDL_GetError());
        SDL_Quit();
        return false;
    }
    
    _renderer = SDL_CreateRenderer(_window, NULL);
    if (!_renderer) {
        LOG2(" SDL_CreateRenderer error : ", SDL_GetError());
        SDL_DestroyWindow(_window);
        SDL_Quit();
        return false;
    }
    SDL_SetRenderDrawColor(_renderer, SCREEN_CLR.r, SCREEN_CLR.g, SCREEN_CLR.b, SCREEN_CLR.a);
    
    if (!tHandler.SetRenderer(_renderer)) {
        LOG(" TextureHandler.SetRenderer() error ");
        return false;
    }

    if (!TTF_Init()) {
        LOG2("TTF_Init error : ", SDL_GetError());
        txtHandler.m_Initalized = false;
    }
    else {
        txtHandler.m_Initalized = true;
        txtHandler.CreateTextEngine(_renderer);
        txtHandler.UseFont((SCRIPT_PATH + FONTS_PATH + "test_font.ttf").c_str());
        LOG("TTF Initalized");
    }

    KOPYInitalized = true;
    SDLInitalized = true;
    StartFrame();
    return true;
}

bool CloseKOPYWindow() {
    ERR_HANDLE(!KOPYInitalized, "KOPY NOT INITALIZED", return false);
    ERR_SDLINIT;

    if (_renderer != nullptr)
        SDL_DestroyRenderer(_renderer);

    if (_window != nullptr)
        SDL_DestroyWindow(_window);

    TTF_Quit();
    SDL_Quit();
    return true;
}

bool SetDrawColor(const int r, const int g, const int b, const int a) {
    ERR_SDLINIT;
    SDL_Color clr = { r, g, b, a };
    if (SAME_CLR(DRAW_CLR, clr)) return true;

    else
        return SDL_SetRenderDrawColor(_renderer, SDL_clamp(r, 0, 255),
                                                SDL_clamp(g, 0, 255),
                                                SDL_clamp(b, 0, 255),
                                                SDL_clamp(a, 0, 255));
}

bool SetScreenColor(const int r, const int g, const int b, const int a) {
    SCREEN_CLR.r = SDL_clamp(r, 0, 255);
    SCREEN_CLR.g = SDL_clamp(g, 0, 255);
    SCREEN_CLR.b = SDL_clamp(b, 0, 255);
    SCREEN_CLR.a = SDL_clamp(a, 0, 255);
    return true;
}

bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y) {
    ERR_SDLINIT;
    return SDL_RenderLine(_renderer, pt1_x, pt1_y, pt2_x, pt2_y);
}

bool DrawCircle(const int pt_x, const int pt_y, const int radius) {
    ERR_SDLINIT;
    int numPts = radius * maths::KO_PI;
    float inc =  maths::KO_PI / numPts;
    int x, y;
    maths::vec2 centre = { (float) pt_x, (float)pt_y };

    for (float theta = 0; theta < maths::KO_PI; theta += inc) {
        SDL_RenderPoint(_renderer, centre.x + (radius * cos(theta)),
                                    centre.y + (radius * sin(theta)));

        SDL_RenderPoint(_renderer, centre.x - (radius * cos(theta)),
                                    centre.y - (radius * sin(theta)));
    }
    return true;
}

bool DrawFilledCircle(const int pt_x, const int pt_y, const int radius) {
    ERR_SDLINIT;
    int xMin = pt_x - radius;
    int xMax = pt_x + radius;
    int yMin = pt_y - radius;
    int yMax = pt_y + radius;

    maths::vec2 centre = { (float) pt_x, (float) pt_y };
    maths::vec2 point;
    maths::vec2 diff;
    std::vector<maths::vec2> drawPts;
    drawPts.reserve((xMax - xMin) * (yMax - yMin));

    for (int x = xMin; x < xMax; x++) {
        for (int y = yMin; y < yMax; y++) {
            point = { (float) x, (float) y };
            diff = centre - point;
            if (length(diff) < radius)
                SDL_RenderPoint(_renderer, x, y);
        }
    }
    return true;
}

bool DrawRect(const int pt_x, const int pt_y, const int width, const int height, const int rotation) {
    ERR_INITS;
    SDL_FRect frect = { pt_x, pt_y, width, height };
    if (rotation == 0) {
        SDL_RenderRect(_renderer, &frect);
        return true;
    }

    KOPY::Transform transform( frect , rotation );
    std::array<int, 8> pts;
    transform.GetRotatedRectPts(&pts);

    SDL_RenderLine(_renderer, pts.at(0), pts.at(1), pts.at(2), pts.at(3));
    SDL_RenderLine(_renderer, pts.at(2), pts.at(3), pts.at(4), pts.at(5));
    SDL_RenderLine(_renderer, pts.at(4), pts.at(5), pts.at(6), pts.at(7));
    SDL_RenderLine(_renderer, pts.at(6), pts.at(7), pts.at(0), pts.at(1));
    return true;
}

bool StartFrame() {
    ERR_INITS;
    tHandler.m_DebugView = _DebugView;
    _timer.SetStart();
    _deltaTime = _timer.deltaTime();
    bool success = true;
    success &= SDL_SetRenderDrawColor(_renderer, SCREEN_CLR.r, SCREEN_CLR.g, SCREEN_CLR.b, SCREEN_CLR.a);
    success &= SDL_RenderClear(_renderer);
    return success;
}

bool RenderFrame() {
    ERR_INITS;
    bool success = true;
    tHandler.RenderAll(objHandler);
    txtHandler.RenderAll();
    success &= eHandler.EventPoll();
    success &= SDL_RenderPresent(_renderer);
    _timer.FrameDelay();
    std::string title = "FPS : " + std::to_string(_timer.GetFPS());
    SDL_SetWindowTitle(_window, title.c_str());
    return success;
}

int LoadTexture(const char* file_name) {
    ERR_INITS;
    const std::string path_str = SCRIPT_PATH + ASSETS_PATH + file_name;
    return tHandler.LoadTexture(path_str);
}

int NewObjType(const char* type_name, const char* texture_path) {
    ERR_INITS;
    const std::string texturePathStr = SCRIPT_PATH + ASSETS_PATH + texture_path;
    idx_t textureIndex = tHandler.LoadTexture(texturePathStr);
    ERR_HANDLE(textureIndex < 0, "TextureIndex < 0, Unable to create new obj type", return -1);
    return objHandler.NewType(type_name, textureIndex);
}

int AddObj(const char* type_name, float _x, float _y, float width, float height) {
    ERR_INITS;
    return objHandler.AddObj(type_name, {_x, _y, width, height});
}

bool ShowTexture(idx_t tformIndex) {
    ERR_INITS;
    return objHandler.ShowTexture(tformIndex);
}

bool HideTexture(idx_t tformIndex) {
    ERR_INITS;
    return objHandler.HideTexture(tformIndex);
}

bool PlaceTexture(idx_t tformIndex, float pointx, float pointy, float width, float height) {
    ERR_INITS;
    bool goodRet;
    goodRet = objHandler.ResizeTexture(tformIndex, width, height);
    goodRet &= objHandler.MoveTexture(tformIndex, pointx, pointy);
    goodRet &= objHandler.ShowTexture(tformIndex);
    return goodRet;
}

bool MoveTexture(idx_t index, float pointx, float pointy) {
    ERR_INITS;
    return objHandler.MoveTexture(index, pointx, pointy);
}

bool PushTexture(idx_t index, float push_x, float push_y) {
    ERR_INITS;
    return objHandler.PushTexture(index, push_x, push_y);
}

bool RotateTexture(idx_t index, float degrees) {
    ERR_INITS;
    return objHandler.RotateTexture(index, degrees);
}

bool SetVel(idx_t index, KOPY::Vec2 vel) {
    ERR_INITS;
    return objHandler.SetVel(index, vel);
}

bool AddVel(idx_t index, KOPY::Vec2 vel) {
    ERR_INITS;
    return objHandler.AddVel(index, vel);
}

bool SetRotVel(idx_t index, float rotVel) {
    ERR_INITS;
    return objHandler.SetRotVel(index, rotVel);
}

bool SetMaxVel(idx_t index, float maxVel) {
    ERR_INITS;
    return objHandler.SetMaxVel(index, maxVel);
}

bool SetMaxAcel(idx_t index, float maxAcel) {
    ERR_INITS;
    return objHandler.SetMaxAcel(index, maxAcel);
}

bool ImportString(char* contents) {
    const std::string str_in = contents;
    LOG2("Imported String : ", contents);
    if (strcmp(str_in.c_str(), contents))
        return true;
    else
        return false;
}

bool PollEvents() {
    ERR_INITS;
    return eHandler.EventPoll();
}

bool KeyPressed(KOPY::KOPY_KEY key) {
    ERR_INITS;
    return eHandler.IsKeyPressed(key);
}

bool WaitForKeypress(KOPY::KOPY_KEY key) {
    ERR_INITS;
    size_t loop = 0;
    bool running = true;    
    while (running) {
        eHandler.EventPoll();
        running = !eHandler.IsKeyPressed(key);
        SDL_Delay(8);
        loop++;
        if (loop > 100000) return false;
    }
    return true;
}

int GetMouseX() {
    ERR_INITS;
    return eHandler.GetMouseX();
}

int GetMouseY() { 
    ERR_INITS;
    return eHandler.GetMouseY();
}

KOPY::Vec2 GetMousePos() {
    ERR_INITS;
    return eHandler.GetMousePos();
}

bool MouseButtonPressed(KOPY::KOPY_MOUSE_BUTTON button) {
    ERR_INITS;
    return eHandler.MouseButtonPressed(button);
}

bool DelayS(int s) {
    ERR_INITS;
    SDL_Delay(s * 1000);
    return true;
}

bool DelayMS(int ms) {
    ERR_INITS;
    SDL_Delay(ms);
    return true;
}

bool PassingVec2(KOPY::Vec2 vec) {
    LOG2("Recieved : ", OLVec2(vec));
    return true;
}

KOPY::Vec2 ReturnVec2() {
    return _retVec;
}

int CreateAsteroid(KOPY::Vec2 pos, KOPY::Vec2 size) {
    ERR_INITS;

    if (!_astInit) {
        _astInit = true;
        const std::string path_str = SCRIPT_PATH + ASSETS_PATH + _asteroidName;
        idx_t textureIndex = tHandler.LoadTexture(path_str);
        objHandler.NewType("Asteroid", textureIndex);
        idx_t tformIndex = objHandler.AddObj(textureIndex, { pos.x, pos.y, size.x, size.y });
        cHandler.AddCollider(tformIndex);
        return tformIndex;
    }
    else {
        idx_t tformIndex =  objHandler.AddObj("Asteroid", { pos.x, pos.y, size.x, size.y });
        cHandler.AddCollider(tformIndex);
        return tformIndex;
    }
}

bool UpdatePhysics() {
    ERR_INITS;
    bool result = true;
    result &= cHandler.Detect(objHandler);
    result &= cHandler.Solve(_deltaTime);
    objHandler.UpdatePhys(_deltaTime);
    return result;
}

bool AddCollider(idx_t tformIndex) {
    ERR_INITS;
    return cHandler.AddCollider(tformIndex);
}

int AddText(const char* content, float x, float y) {
    ERR_INITS;
    const std::string str = content;
    return txtHandler.AddText(str, {x, y});
}

bool ResizeText(idx_t textIndex, unsigned int size) {
    ERR_INITS;
    return txtHandler.Resize(textIndex, size);
}

bool SetTextPos(idx_t textIndex, KOPY::Vec2 pos) {
    ERR_INITS;
    return txtHandler.SetPos(textIndex, KOPY::KopyToMaths(pos));
}

bool SetTextColorRGBA(idx_t textIndex, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    ERR_INITS;
    return txtHandler.SetColor(textIndex, r, g, b, a);
}
bool SetTextColorKOPY(idx_t textIndex, KOPY_Color clr) {
    ERR_INITS;
    return txtHandler.SetColor(textIndex, clr.r, clr.g, clr.b, clr.a);
}

bool SetTextContent(idx_t textIndex, const char* content) {
    ERR_INITS;
    return txtHandler.SetContent(textIndex, content);
}

