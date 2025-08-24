#pragma once

#include <cmath>
#include <array>

namespace KOPY {

	struct Transform {

		float Rotation;
		SDL_FRect FRect;

		Transform(const SDL_FRect& frect = { 0, 0, 0, 0 }, float rotation = 0)
			: FRect(frect), Rotation(rotation)
		{ }

		Transform(int _x, int _y, int width, int height, float rotation = 0)
			: Rotation(rotation)
		{ FRect = { (float)_x, (float)_y, (float)width, (float)height }; }

		inline void SetSize(float width, float height) {
			FRect.w = width;
			FRect.h = height;
		}
		
		inline void SetPos(float _x, float _y) {
			FRect.x = _x;
			FRect.y = _y;
		}

		void GetRotatedRectPts(std::array<int, 8>* int_array_out) const {
			const float cx = FRect.x + (FRect.w * 0.5f);
			const float cy = FRect.y + (FRect.h * 0.5f);
			
			float diffx, diffy;
			float cos_t = cos(maths::toRadians(Rotation));
			float sin_t = sin(maths::toRadians(Rotation));
			for (int i = 0; i < 8; i += 2) {
				diffx = FRect.x - cx;
				diffy = FRect.y - cy;

				int_array_out->at(i) = (diffx * cos_t - diffy * sin_t) + cx;
				int_array_out->at(i + 1) = (diffx * sin_t + diffy * cos_t) + cy;
			}
			return;
		}
	};

}