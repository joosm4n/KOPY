#pragma once

#ifdef KOPY_EXPORTS
#define KOPY_API __declspec(dllexport)
#else
#define KOPY_API __declspec(dllimport)
#endif


// Initalizes SDL and Creates SDL_Window and SDL_Renderer
extern "C" KOPY_API bool OpenKOPYWindow();

// Closes SDL and Destroys SDL_Window and SDL_Renderer
extern "C" KOPY_API bool CloseKOPYWindow();

// Sets the SDL_Renderer draw color
extern "C" KOPY_API bool SetDrawColor(const int r, const int g, const int b, const int a);

// Draws a line from pt1 to pt2 with current color
extern "C" KOPY_API bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y);

// SDL_RenderPresent
extern "C" KOPY_API bool RenderFrame();

// Create TEXTURE?
extern "C" KOPY_API bool LoadTexture(char* file_path);

// ButtonPressed?
enum KEYBOARD_BUTTON {
	ESC,
	E,
	T
};
// Checks if a button was pressed
extern "C" KOPY_API bool ButtonPressed(KEYBOARD_BUTTON a);

