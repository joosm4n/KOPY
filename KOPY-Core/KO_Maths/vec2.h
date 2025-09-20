#pragma once

#include  <iostream>
#include "vec3.h"

namespace maths {

	struct vec3;

	struct vec2
	{
		float x, y;

		vec2();
		vec2(const float& x, const float& y);
		vec2(const vec3& v);

		vec2& add(const vec2& other);
		vec2& subtract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		friend vec2 operator-(const vec2& self);

		friend vec2& operator+(vec2 left, const vec2& right);
		friend vec2& operator-(vec2 left, const vec2& right);
		friend vec2& operator*(vec2 left, const vec2& right);
		friend vec2& operator/(vec2 left, const vec2& right);

		friend vec2 operator+(const vec2& left, const float scalar);
		friend vec2 operator-(const vec2& left, const float scalar);
		friend vec2 operator*(const vec2& left, const float scalar);
		friend vec2 operator/(const vec2& left, const float scalar);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		friend vec2 perpendicular(const vec2& vector);
		friend vec2 perpendicularCCW(const vec2& vector);
		friend float dot(const vec2& left, const vec2& right);
		friend double length(const vec2 vector);
		friend vec2 normalize(const vec2& vector);
		vec2 perp();
		vec2 perpCCW();

		static vec2 xaxis() { return vec2(1, 0); };
		static vec2 yaxis() { return vec2(0, 1); };

		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);

		friend std::ostream& operator<<(std::ostream&, const vec2& vector);
		float& operator[](size_t index);

		explicit operator vec3() const { return vec3(this->x, this->y, 1); }

		vec2& Rotate(const float angle);
		vec2& RotateAround(const vec2& point, const float angle);

		friend vec2 GetRotatedVec(vec2 vector, const float angle);
		friend vec2 GetRotatedVecAround(vec2 vector, const vec2& point, const float angle);
	};

}