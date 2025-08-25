#pragma once

#include <cmath>
#include <array>
#include "KO_Maths/maths_func.h"

namespace KOPY {

	constexpr float MASS_UNIT = (100 * 100);
    constexpr float MASS_CONST = (1.0f / MASS_UNIT);

	struct Transform {

		float Rotation;
		float RotVel;
		maths::vec2 Velocity;
		SDL_FRect FRect;

		Transform(const SDL_FRect& frect = { 0, 0, 0, 0 }, float rotation = 0)
			: FRect(frect), Rotation(rotation), Velocity(0, 0), RotVel(0)
		{ }

		Transform(int _x, int _y, int width, int height, float rotation = 0)
			: Rotation(rotation), Velocity(0, 0), RotVel(0)
		{ FRect = { (float)_x, (float)_y, (float)width, (float)height }; }

		inline void SetSize(float width, float height) {
			FRect.w = width;
			FRect.h = height;
		}
		
		inline void SetPos(float _x, float _y) {
			FRect.x = _x;
			FRect.y = _y;
		}
		inline void Push(const maths::vec2& vec) {
			FRect.x += vec.x;
			FRect.y += vec.y;
		}

		inline maths::vec2 Centre() const {
			return { FRect.x + (FRect.w / 2), FRect.y + (FRect.h / 2) };
		}

		inline float Radius() const {
			return { FRect.w / 2 };
		}

		// Mass is currently calculated from the area of the FRect.
		inline float Mass() const {
			return { FRect.w * FRect.h * MASS_CONST }; 
		}

		void GetRotatedRectPts(std::array<int, 8>* int_array_out) const {
			const float halfW = FRect.w * 0.5f;
			const float halfH = FRect.h * 0.5f;
			const float cx = FRect.x + halfW;
			const float cy = FRect.y + halfH;
			
			float cos_t = std::cos(maths::toRadians(Rotation));
			float sin_t = std::sin(maths::toRadians(Rotation));

			int_array_out->at(0) = ((cx - FRect.x		 ) * cos_t - (cy - FRect.y		  ) * sin_t) + FRect.x;
			int_array_out->at(1) = ((cx - FRect.x		 ) * sin_t + (cx - FRect.y		  ) * cos_t) + FRect.y;
			int_array_out->at(2) = ((cx - FRect.x + halfW) * cos_t - (cy - FRect.y		  ) * sin_t) + FRect.x;
			int_array_out->at(3) = ((cx - FRect.x + halfW) * sin_t + (cx - FRect.y		  ) * cos_t) + FRect.y;
			int_array_out->at(4) = ((cx - FRect.x + halfW) * cos_t - (cy - FRect.y + halfW) * sin_t) + FRect.x;
			int_array_out->at(5) = ((cx - FRect.x + halfW) * sin_t + (cx - FRect.y + halfW) * cos_t) + FRect.y;
			int_array_out->at(6) = ((cx - FRect.x		 ) * cos_t - (cy - FRect.y + halfW) * sin_t) + FRect.x;
			int_array_out->at(7) = ((cx - FRect.x		 ) * sin_t + (cx - FRect.y + halfW) * cos_t) + FRect.y;
			return;
		}

		void UpdatePhys(float deltaTime) {

			FRect.x += Velocity.x * deltaTime;
			FRect.y += Velocity.y * deltaTime;
			Rotation += RotVel;
		}
	};

}