#pragma once

#include <iostream>

namespace maths {

	struct vec2;

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float& x, const float& y, const float& z);

		vec3& add(const vec3& other);
		vec3& subtract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		friend vec3 operator+(vec3 left, const float scalar);
		friend vec3 operator-(vec3 left, const float scalar);
		friend vec3 operator*(vec3 left, const float scalar);
		friend vec3 operator/(vec3 left, const float scalar);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		friend std::ostream& operator<<(std::ostream&, const vec3& vector);

		friend double length(const vec3 vector);
		friend vec3 normalize(const vec3& vector);
		friend float dot(const vec3& left, const vec3& right);

		static vec3 xaxis(const float amount = { 1 });
		static vec3 yaxis(const float amount = { 1 });
		static vec3 zaxis(const float amount = { 1 });

		vec3& rotateAroundX(const vec3& axis, const float angle);
		vec3& rotateAroundY(const vec3& axis, const float angle);
		vec3& rotateAroundZ(const vec3& axis, const float angle);
			
		operator vec2() const;
	};

}