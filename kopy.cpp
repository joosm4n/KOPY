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
#include "texturehandler.h"
#include "eventhandler.h"

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

// Filepaths
static std::string SCRIPT_PATH;
static const std::string ASSETS_PATH = "/bin/assets/";

// Testing
static maths::vec2 _vec = { 69, 420 };
static KOPY::Vec2 _retVec;

bool InitKOPY() {
    ERR_HANDLE(KOPYInitalized, "KOPY already initalized", return false);
    ERR_HANDLE(SDLInitalized, "SDL already initalized", return false);
    KOPYInitalized = true;
    return true;
}

bool SetScriptPath(char* path) {
    SCRIPT_PATH = path;
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
    KOPYInitalized = true;
    SDLInitalized = true;
    StartFrame();
    return true;
}

bool CloseKOPYWindow() {
    ERR_HANDLE(!KOPYInitalized, "KOPY NOT INITALIZED", return false);
    ERR_SDLINIT;
    tHandler.~TextureHandler();

    if (_renderer != nullptr)
        SDL_DestroyRenderer(_renderer);

    if (_window != nullptr)
        SDL_DestroyWindow(_window);

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

bool DrawFilledCircle(const int pt_x, const int pt_y, const int radius) 
{
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
    ERR_SDLINIT;
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
    ERR_SDLINIT;
    bool success = true;
    success &= SDL_SetRenderDrawColor(_renderer, SCREEN_CLR.r, SCREEN_CLR.g, SCREEN_CLR.b, SCREEN_CLR.a);
    success &= SDL_RenderClear(_renderer);
    return success;
}

bool RenderFrame() {
    ERR_SDLINIT;
    tHandler.RenderAll();
    eHandler.EventPoll();
    return SDL_RenderPresent(_renderer);
}

int LoadTexture(char* file_name) {
    ERR_SDLINIT;
    const std::string path_str = SCRIPT_PATH + ASSETS_PATH + file_name;
    LOG2("FilePath : ", path_str);
    return tHandler.LoadTexture(path_str);
}

bool ShowTexture(unsigned int index) {
    ERR_SDLINIT;
    return tHandler.ShowTexture(index);
}

bool HideTexture(unsigned int index) {
    ERR_SDLINIT;
    return tHandler.HideTexture(index);
}

bool PlaceTexture(unsigned int index, float pointx, float pointy, float width, float height) {
    ERR_SDLINIT;
    bool goodRet;
    goodRet = tHandler.ResizeTexture(index, width, height);
    goodRet &= tHandler.MoveTexture(index, pointx, pointy);
    goodRet &= tHandler.ShowTexture(index);
    return goodRet;
}

bool MoveTexture(unsigned int index, float pointx, float pointy) {
    ERR_SDLINIT;
    return tHandler.MoveTexture(index, pointx, pointy);
}

bool PushTexture(unsigned int index, float push_x, float push_y) {
    ERR_SDLINIT;
    return tHandler.PushTexture(index, push_x, push_y);
}

bool RotateTexture(unsigned int index, float degrees) {
    ERR_SDLINIT;
    return tHandler.RotateTexture(index, degrees);
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
    ERR_SDLINIT;
    return eHandler.EventPoll();
}

bool KeyPressed(unsigned int key_in) {    
    ERR_SDLINIT;
    KOPY::KO_KEY key = static_cast<KOPY::KO_KEY>(key_in);
    return eHandler.IsKeyPressed(key);
}

bool WaitForKeypress(unsigned int key_in) {
    ERR_SDLINIT;
    KOPY::KO_KEY key = static_cast<KOPY::KO_KEY>(key_in);
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

bool DelayS(int s) {
    ERR_SDLINIT;
    SDL_Delay(s * 1000);
    return true;
}

bool DelayMS(int ms) {
    ERR_SDLINIT;
    SDL_Delay(ms);
    return true;
}

bool PassingVec2(KOPY::Vec2 vec) {
    LOG(KOPY::KopyToMaths(vec));
    return true;
}

KOPY::Vec2 ReturnVec2(KOPY::Vec2 vecIn) {
    _vec = KOPY::KopyToMaths(vecIn);
    LOG2("Sending : ", _vec);
    return KOPY::MathsToKopy(_vec);
}