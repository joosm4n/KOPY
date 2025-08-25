#pragma once

#include <iostream>

#define DEBUG 1

#if DEBUG
#define LOGn(x) std::cout << x
#define LOG(x) std::cout << x << std::endl
#define LOG2(x, y) std::cout << x << y << std::endl
#define ERR_HANDLE(x, y, z) if (x) { LOG(y); z; }
#define ERR_SDLINIT ERR_HANDLE(!SDLInitalized, "SDL NOT INITALIZED", return false)
#elif
#define LOGn(x)
#define LOG(x)
#define LOG2(x, y)
#define ERR_HANDLE(x, y)
#define ERR_SDLINIT
#endif

#define DEFAULT_SCREEN_WIDTH 1920
#define DEFAULT_SCREEN_HEIGHT 1080

#define SAME_CLR(x, y) ((x.r == y.r) && (x.g == y.g) && (x.b == y.b) && (x.a == y.a))
