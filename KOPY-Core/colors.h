#pragma once

#include <SDL3/SDL.h>
#include <cstdint>

struct KOPY_Color 
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	KOPY_Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a = 255) 
		: r(_r), g(_g), b(_b), a(_a)
	{ }
	KOPY_Color(const SDL_Color& clr) 
		: r(clr.r), g(clr.g), b(clr.b), a(clr.a)
	{ }

};

