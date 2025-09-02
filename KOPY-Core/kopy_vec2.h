#pragma once

#include "KO_Maths/vec2.h"

namespace KOPY {

	struct Vec2 {
		float x;
		float y;

		Vec2(float _x = 0, float _y = 0)
			: x(_x), y(_y)
		{ }

		Vec2(bool a)
		{
			if (a) {
				x = 1;
				y = 1;
			}
			else {
				x = 0;
				y = 0;
			}
		}
	};

#define OLVec2(vec2) "vec2(" << vec2.x << ", " << vec2.y << ")"

	inline Vec2 MakeVec2(float x, float y) {
		return { x, y };
	}

	inline Vec2 MathsToKopy(maths::vec2 mathVec) {
		return { mathVec.x, mathVec.y };
	}
	inline maths::vec2 KopyToMaths(KOPY::Vec2 kopyVec) {
		return { kopyVec.x, kopyVec.y };
	}
}