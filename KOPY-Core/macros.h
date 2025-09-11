#pragma once

#include <iostream>

#define DEBUG 1

#if DEBUG
#define LOGn(x) std::cout << x
#define LOG(x) std::cout << x << std::endl
#define LOG2(x, y) std::cout << x << y << std::endl
#define ERR_HANDLE(x, y, z) if (x) { LOG(y); z; }
#define ERR_SDLINIT ERR_HANDLE(!SDLInitalized, "SDL NOT INITALIZED", return false)
#define ERR_KOPYINIT ERR_HANDLE(!KOPYInitalized, "KOPY NOT INITALIZED", return false)
#define ERR_INITS ERR_KOPYINIT; ERR_SDLINIT;
#elif
#define LOGn(x)
#define LOG(x)
#define LOG2(x, y)
#define ERR_HANDLE(x, y)
#define ERR_SDLINIT
#define ERR_KOPYINIT
#define ERR_INITS
#endif

#define DEFAULT_SCREEN_WIDTH 1920
#define DEFAULT_SCREEN_HEIGHT 1080

#define SAME_CLR(x, y) ((x.r == y.r) && (x.g == y.g) && (x.b == y.b) && (x.a == y.a))
#define FLOAT_MAX 
