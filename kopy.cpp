// kopy.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <limits.h>
#include <cstdint>
#include <cstdio>
#include "kopy.h"
#include <SDL3/SDL.h>

// DLL internal state variables:
static unsigned long long sum_;  // Previous value, if any
static bool initalized_ = false;

// SDL STUFF
static bool SDLInitalized = false;
static SDL_Window* _window = nullptr;
static SDL_Renderer* _renderer = nullptr;
static const SDL_Color SCREEN_CLR = { 0, 0, 0, 255 };
static const SDL_Color NULL_CLR = { 255, 105, 180, 255 };

// Starts the sum
void add_init(const unsigned long long start_value)
{
    sum_ = start_value;
    initalized_ = true;
}

// Adds number to sum
bool add_num(const unsigned long long num_in)
{
    if (!initalized_) {
        return false;
    }
    else {

        // check to see if we'd overflow result or position
        if (ULLONG_MAX - sum_ < num_in) {
            return false;
        }
        sum_ += num_in;
        return true;
    }
}

// Gets current sum
unsigned long long get_sum()
{
    if (initalized_)
        return sum_;
    else
        return 0;
}

bool OpenKOPYWindow()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return false;
    }

    _window = SDL_CreateWindow("SDL_Window", 1920, 1080, NULL);
    if (!_window) {
        SDL_Quit();
        return false;
    }
    _renderer = SDL_CreateRenderer(_window, NULL);
    if (!_renderer) {
        SDL_DestroyWindow(_window);
        SDL_Quit();
        return false;
    }
    SDL_SetRenderDrawColor(_renderer, SCREEN_CLR.r, SCREEN_CLR.g, SCREEN_CLR.b, SCREEN_CLR.a);

    return true;
}


bool CloseKOPYWindow()
{
    if (!SDLInitalized) return false;

    if (_renderer != nullptr) {
        SDL_DestroyRenderer(_renderer);
    }

    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
    }

    SDL_Quit();
    return true;
}

bool SetDrawColor(const int r, const int g, const int b, const int a)
{
    return SDL_SetRenderDrawColor(_renderer, SDL_clamp(r, 0, 255), SDL_clamp(g, 0, 255), SDL_clamp(b, 0, 255), SDL_clamp(a, 0, 255));
}

bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y) 
{
    return SDL_RenderLine(_renderer, pt1_x, pt1_y, pt2_x, pt2_y);
}

bool RenderFrame()
{
    return SDL_RenderPresent(_renderer);
}

bool LoadTexture(char* filePath)
{
    printf(filePath);
    return true;
}

bool ButtonPressed(KEYBOARD_BUTTON key)
{    
    // Events
    SDL_Event key_press;
    while (SDL_PollEvent(&key_press))
    {
        if (key_press.type == SDL_EVENT_QUIT)
        {
            return false;
            break;
        }
        else if (key_press.type == SDL_EVENT_KEY_DOWN)
        {
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