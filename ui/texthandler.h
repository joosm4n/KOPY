#pragma once

#include "text.h"
#include <array>

constexpr Uint8 MAX_TEXT_OBJS = 63;

namespace KOPY {

	class TextHandler
	{
	private:
		std::array<Text, MAX_TEXT_OBJS> m_TextObjs;
		std::array<Uint8, MAX_TEXT_OBJS> m_FontIndex;

		std::array<TTF_Font*, 32> m_Fonts;
		
		TTF_TextEngine* m_TextEngine;


	public:

		TextHandler() {}



	};


}