#pragma once

#include "macros.h"
#include "enums.h"

#ifdef KOPY_EXPORTS
#define KOPY_API __declspec(dllexport)
#else
#define KOPY_API __declspec(dllimport)
#endif

// Initalizes all KOPY stuff
extern "C" KOPY_API bool InitKOPY();
extern "C" KOPY_API bool SetScriptPath(char* path);

// Initalizes SDL and Creates SDL_Window and SDL_Renderer
extern "C" KOPY_API bool OpenKOPYWindow(int width, int height);
extern "C" KOPY_API bool CloseKOPYWindow();

// Sets the SDL_Renderer draw color
extern "C" KOPY_API bool SetDrawColor(const int r, const int g, const int b, const int a);
extern "C" KOPY_API bool SetScreenColor(const int r, const int g, const int b, const int a);

// Draw Funcs
extern "C" KOPY_API bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y);
extern "C" KOPY_API bool DrawCircle(const int pt_x, const int pt_y, const int radius);
extern "C" KOPY_API bool DrawFilledCircle(const int pt_x, const int pt_y, const int radius);

// Render calls
extern "C" KOPY_API bool StartFrame();
extern "C" KOPY_API bool RenderFrame();

// Textures	
extern "C" KOPY_API int LoadTexture(char* file_name);
extern "C" KOPY_API bool PlaceTexture(int index, int pointx, int pointy, int width, int height);
extern "C" KOPY_API bool MoveTexture(int index, int pointx, int pointy);
extern "C" KOPY_API bool RotateTexture(int index, int degrees);

// Event handling
extern "C" KOPY_API bool PollEvents();
extern "C" KOPY_API bool KeyPressed(unsigned int key);
extern "C" KOPY_API bool WaitForKeypress(unsigned int key);

// Testing passing a string
extern "C" KOPY_API bool ImportString(char* buffer); // Must be 'ASCII' char* 

// Delays
extern "C" KOPY_API bool DelayMS(int ms);
extern "C" KOPY_API bool DelayS(int s);