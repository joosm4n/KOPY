#pragma once

#include <iostream>
#include "vec3.h"

namespace maths {

	struct vec4
	{
		union { float x; float r; };
		union { float y; float g; };
		union { float z; float b; };
		union { float w; float a; };

		vec4() = default;
		vec4(float x, float y, float z, float w);
		vec4(const vec3& other, float _w = 0);

		vec4& add(const vec4& other);
		vec4& subtract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		friend vec4& operator*(vec4 self, float scalar);
		friend vec4& operator*(float scalar, vec4 self);

		friend vec4& operator+(vec4 left, const vec4& right);
		friend vec4& operator-(vec4 left, const vec4& right);
		friend vec4& operator*(vec4 left, const vec4& right);
		friend vec4& operator/(vec4 left, const vec4& right);

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		operator vec3() const;

		float& operator[](size_t index);
		const float& operator[](size_t index) const;
		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		friend float length(const vec4& vector);
		friend vec4 normalize(const vec4& vector);
	};

}
