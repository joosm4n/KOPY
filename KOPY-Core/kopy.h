#pragma once

#include "macros.h"
#include "event_enums.h"
#include "kopy_vec2.h"
#include "colors.h"
#include <cstdint>

#ifdef KOPY_EXPORTS
#define KOPY_API __declspec(dllexport)
#else
#define KOPY_API __declspec(dllimport)
#endif

// Types
typedef uint32_t idx_t;

// Interfacing stuff
extern "C" KOPY_API bool InitKOPY();
extern "C" KOPY_API bool SetScriptPath(const char* path);
extern "C" KOPY_API bool SetAssetsPath(const char* path);

// Init() and Quit() commands for SDL
extern "C" KOPY_API bool OpenKOPYWindow(int width, int height);
extern "C" KOPY_API bool CloseKOPYWindow();

// Sets the SDL_Renderer draw color
extern "C" KOPY_API bool SetDrawColor(const int r, const int g, const int b, const int a);
extern "C" KOPY_API bool SetScreenColor(const int r, const int g, const int b, const int a);
extern "C" KOPY_API bool SetDebugView(bool state);

// Draw Geometry Funcs
extern "C" KOPY_API bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y);
extern "C" KOPY_API bool DrawCircle(const int pt_x, const int pt_y, const int radius);
extern "C" KOPY_API bool DrawFilledCircle(const int pt_x, const int pt_y, const int radius);
extern "C" KOPY_API bool DrawRect(const int pt_x, const int pt_y, const int width, const int height, const int rotation);

// Render calls
extern "C" KOPY_API bool StartFrame();
extern "C" KOPY_API bool RenderFrame();

// Textures	
extern "C" KOPY_API int LoadTexture(char* file_name);
extern "C" KOPY_API bool ShowTexture(idx_t index);
extern "C" KOPY_API bool HideTexture(idx_t index);
extern "C" KOPY_API bool PlaceTexture(idx_t index, float pointx, float pointy, float width, float height);
extern "C" KOPY_API bool MoveTexture(idx_t index, float pointx, float pointy);
extern "C" KOPY_API bool RotateTexture(idx_t index, float degrees);
extern "C" KOPY_API bool PushTexture(idx_t index, float push_x, float push_y);
extern "C" KOPY_API bool SetVel(idx_t index, KOPY::Vec2 vel);
extern "C" KOPY_API bool AddVel(idx_t index, KOPY::Vec2 vel);
extern "C" KOPY_API bool SetRotVel(idx_t index, float rotVel);
extern "C" KOPY_API bool SetMaxVel(idx_t index, float maxVel);
extern "C" KOPY_API bool SetMaxAcel(idx_t index, float maxAcel);

// Dynamic Object loading
extern "C" KOPY_API int NewObjType(const char* type_name, const char* texture_path);
extern "C" KOPY_API int AddObj(const char* type_name, float _x, float _y, float width, float height);

// Text
extern "C" KOPY_API int AddText(const char* content, float x, float y);
extern "C" KOPY_API bool ResizeText(idx_t textIndex, unsigned int size);
extern "C" KOPY_API bool SetTextColorRGBA(idx_t textIndex, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
extern "C" KOPY_API bool SetTextColorKOPY(idx_t textIndex, KOPY_Color clr);
extern "C" KOPY_API bool SetTextPos(idx_t textIndex, KOPY::Vec2 pos);
extern "C" KOPY_API bool SetTextContent(idx_t textIndex, const char* content);

// Event handling
extern "C" KOPY_API bool PollEvents();
extern "C" KOPY_API bool KeyPressed(KOPY::KOPY_KEY key);
extern "C" KOPY_API bool WaitForKeypress(KOPY::KOPY_KEY key);
extern "C" KOPY_API int GetMouseX();
extern "C" KOPY_API int GetMouseY();
extern "C" KOPY_API KOPY::Vec2 GetMousePos();
extern "C" KOPY_API bool MouseButtonPressed(KOPY::KOPY_MOUSE_BUTTON button);

// Testing
extern "C" KOPY_API bool ImportString(const char* buffer); // Must be 'ASCII' char* 
extern "C" KOPY_API bool PassingVec2(KOPY::Vec2 vec);
extern "C" KOPY_API KOPY::Vec2 ReturnVec2();

// Delays
extern "C" KOPY_API bool DelayMS(int ms);
extern "C" KOPY_API bool DelayS(int s);

// Game Stuff
extern "C" KOPY_API int CreateAsteroid(KOPY::Vec2 pos, KOPY::Vec2 size);
extern "C" KOPY_API bool UpdatePhysics();
extern "C" KOPY_API bool AddCollider(idx_t tformIndex);
