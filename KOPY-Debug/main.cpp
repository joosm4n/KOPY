
#include <kopy.h>
#include <string>

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
const KOPY_Color RED = { 255, 0, 0, 255 };
const KOPY_Color GREEN = { 0, 255, 0, 255 };
const KOPY_Color BLUE = { 0, 0, 255, 255 };

int main() {

	LOG("KOPY-Debug.exe Starting");
	using namespace KOPY;
	SetScriptPath("C:/Users/Kieran/source/repos/KOPY/Cpp Files/");
	SetAssetsPath("assets/");
	SetDebugView(false);
	InitKOPY();
	OpenKOPYWindow(WIDTH, HEIGHT);
	
	NewObjType("Asteroid", "Asteroid_small.png");
	int bigboi = AddObj("Asteroid", 500, 500, 100, 100);
	AddCollider(bigboi);
	SetVel(bigboi, {0, 200});
	ShowTexture(bigboi);

	int txt1 = AddText("Hello", 500, 500);
	int txt2 = AddText("Yeet", 700, 500);
	SetTextColorKOPY(txt2, GREEN);

	bool running = true;
	int loop = 0;
	while (running) {
		StartFrame();
		PollEvents();

		SetTextPos(txt2, GetMousePos());

		if (KeyPressed(KOPY_KEY::ESCAPE)) {
			running = false;
		}
		UpdatePhysics();
		RenderFrame();
		loop++;
	}

	CloseKOPYWindow();
	LOG("KOPY-Debug Closed");

	return 0;
}