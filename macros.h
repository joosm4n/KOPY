#pragma once

#define DEBUG 1

#if DEBUG
#define LOG(x) std::cout << x << std::endl
#define LOG2(x, y) std::cout << x << y << std::endl
#define ERR_HANDLE(x, y, z) if (x) { LOG(y); z; }
#elif
#define LOG(x)
#define LOG2(x, y)
#define ERR_HANDLE(x, y)
#endif

#define DEFAULT_SCREEN_WIDTH 1920
#define DEFAULT_SCREEN_HEIGHT 1080

