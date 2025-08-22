#pragma once

namespace KOPY {

	struct Transform {

		float Rotation = 0;
		SDL_FRect FRect = { 0, 0, 0, 0};

		Transform(const SDL_FRect& frect, float rotation = 0)
			: FRect(frect), Rotation(rotation)
		{ }

		inline void SetSize(float width, float height) {
			FRect.w = width;
			FRect.h = height;
		}
		
		inline void SetPos(float _x, float _y) {
			FRect.x = _x;
			FRect.y = _y;
		}
	};

}