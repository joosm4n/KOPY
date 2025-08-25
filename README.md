
Callable Functions 

// Interfacing stuff \n
extern "C" KOPY_API bool InitKOPY(); \n 
extern "C" KOPY_API bool SetScriptPath(char* path); \n
\n
// Init() and Quit() commands for SDL \n
extern "C" KOPY_API bool OpenKOPYWindow(int width, int height); \n
extern "C" KOPY_API bool CloseKOPYWindow(); \n
\n
// Sets the SDL_Renderer draw color \n
extern "C" KOPY_API bool SetDrawColor(const int r, const int g, const int b, const int a); \n
extern "C" KOPY_API bool SetScreenColor(const int r, const int g, const int b, const int a); \n
\n
// Draw Geometry Funcs \n
extern "C" KOPY_API bool DrawLine(const float pt1_x, const float pt1_y, const float pt2_x, const float pt2_y); \n
extern "C" KOPY_API bool DrawCircle(const int pt_x, const int pt_y, const int radius); \n
extern "C" KOPY_API bool DrawFilledCircle(const int pt_x, const int pt_y, const int radius); \n
extern "C" KOPY_API bool DrawRect(const int pt_x, const int pt_y, const int width, const int height, const int rotation); \n
\n
// Render calls \n
extern "C" KOPY_API bool StartFrame(); \n
extern "C" KOPY_API bool RenderFrame(); \n
\n
// Textures \n	
int LoadTexture(char* file_name); \n
bool ShowTexture(unsigned int index); \n
bool HideTexture(unsigned int index); \n
bool PlaceTexture(unsigned int index, float pointx, float pointy, float width, float height); \n
bool MoveTexture(unsigned int index, float pointx, float pointy); \n
bool RotateTexture(unsigned int index, float degrees); \n
bool PushTexture(unsigned int index, float push_x, float push_y); \n
bool SetVel(unsigned int index, KOPY::Vec2 vel); \n
bool SetRotVel(unsigned int index, float rotVel); \n

// Event handling
extern "C" KOPY_API bool PollEvents();
extern "C" KOPY_API bool KeyPressed(unsigned int key);
extern "C" KOPY_API bool WaitForKeypress(unsigned int key);

// Testing
extern "C" KOPY_API bool ImportString(char* buffer); // Must be 'ASCII' char* 
extern "C" KOPY_API bool PassingVec2(KOPY::Vec2 vec);
extern "C" KOPY_API KOPY::Vec2 ReturnVec2(KOPY::Vec2 vecIn);

// Delays
extern "C" KOPY_API bool DelayMS(int ms);
extern "C" KOPY_API bool DelayS(int s);

// Game Stuff
extern "C" KOPY_API int CreateAsteroid(KOPY::Vec2 pos, KOPY::Vec2 size);
extern "C" KOPY_API bool UpdatePhysics();
