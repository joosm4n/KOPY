// kopy.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <limits.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include "kopy.h"
#include <SDL3/SDL.h>
#include "macros.h"
#include "texturehandler.h"

// Internal DLL vars
static bool KOPYInitalized = false;
static bool SDLInitalized = false;
static SDL_Window* _window = nullptr;
static SDL_Renderer* _renderer = nullptr;
static SDL_Color SCREEN_CLR = { 0, 0, 0, 255 };
static const SDL_Color NULL_CLR = { 255, 105, 180, 255 };

// File path stuff
static KOPY::TextureHandler tHandler;
static std::string SCRIPT_PATH;
static const std::string ASSETS_PATH = "/bin/assets/";

bool InitKOPY()
{
    ERR_HANDLE(KOPYInitalized, "KOPY already initalized", return false);
    ERR_HANDLE(SDLInitalized, "SDL already initalized", return false);

    KOPYInitalized = true;
    SDLInitalized = false;
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    SDL_Color SCREEN_CLR = { 0, 0, 0, 255 };
    SDL_Color NULL_CLR = { 255, 105, 180, 255 }; // pink
    return true;
}

bool SetScriptPath(char* path)
{
    SCRIPT_PATH = path;
    return true;
}

bool OpenKOPYWindow(int width, int height)
{
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
    return true;
}


bool CloseKOPYWindow()
{
    if (!SDLInitalized) return false;

    tHandler.~TextureHandler();

    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
    }

    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
    }

    SDL_Quit();
    return true;
}

bool SetDrawColor(const int r, const int g, const int b, const int a) {
    ERR_HANDLE(!SDLInitalized, "SDL not Initalized", return false);
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

bool RenderFrame() {
    ERR_HANDLE(!SDLInitalized, "SDL not Initalized", return false);
    SDL_SetRenderDrawColor(_renderer, SCREEN_CLR.r, SCREEN_CLR.g, SCREEN_CLR.b, SCREEN_CLR.a);
    SDL_RenderClear(_renderer);
    tHandler.RenderAll();
    return SDL_RenderPresent(_renderer);
}

int LoadTexture(char* file_name) {
    const std::string path_str = SCRIPT_PATH + ASSETS_PATH + file_name;
    LOG2("FilePath : ", path_str);
    return tHandler.LoadTexture(path_str);
}

bool PlaceTexture(int index, int pointx, int pointy, int width, int height) 
{
    LOG2("Placing Texture : ", index);
    bool goodRet;
    goodRet = tHandler.ResizeTexture(index, (float) width, (float) height);
    goodRet &= tHandler.MoveTexture(index, (float) pointx, (float) pointy);
    return goodRet;
}

bool MoveTexture(int index, int pointx, int pointy)
{
    ERR_HANDLE(!SDLInitalized, "SDL not initalized", return false);
    return tHandler.MoveTexture(index, (float)pointx, (float)pointy);
}

bool ImportString(char* contents)
{
    const std::string str_in = contents;
    LOG2("Imported String : ", contents);
    if (strcmp(str_in.c_str(), contents))
        return true;    
    else
        return false;
}

bool ButtonPressed(KEYBOARD_BUTTON key)
{    
    ERR_HANDLE(!SDLInitalized, "SDL not Initalized", return false);

    // Events
    SDL_Event key_press;
    while (SDL_PollEvent(&key_press))
    {
        if (key_press.type == SDL_EVENT_QUIT) {
            return false;
            break;
        }
        else if (key_press.type == SDL_EVENT_KEY_DOWN) {
            switch (key_press.key.key)
            {
            case SDLK_ESCAPE:
                if (key == ESC)
                    return true;
                break;
            case SDLK_E:
                if (key == E)
                    return true;
                break;
            }
        }
    }
    return false;
}

bool WaitForKeypress(KEYBOARD_BUTTON key)
{
    ERR_HANDLE(!SDLInitalized, "SDL not Initalized", return false);

    // Events
    SDL_Event key_press;
    size_t loop = 0;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&key_press)) {
            if (key_press.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }
            else if (key_press.type == SDL_EVENT_KEY_DOWN) {
                switch (key_press.key.key)
                {
                case SDLK_ESCAPE:
                    if (key == ESC)
                        running = false;
                    break;
                case SDLK_E:
                    if (key == E)
                        running = false;
                    break;
                }
            }
        }
        SDL_Delay(48);
        loop++;
        if (loop > 10000) return false;
    }
    return true;
}

bool DelayS(int s) {
    ERR_HANDLE(!SDLInitalized, "SDL Not Initalized", return false);
    SDL_Delay(s * 1000);
    return true;
}

bool DelayMS(int ms) {
    ERR_HANDLE(!SDLInitalized, "SDL Not Initalized", return false);
    SDL_Delay(ms);
    return true;
}