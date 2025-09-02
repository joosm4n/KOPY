#pragma once

#include "vec3.h"

namespace maths {

	struct mat3
	{
		union
		{
			float elements[3 * 3];
			vec3 columns[3];
		};

		mat3();
		mat3(float diagonal);

		static mat3 identity();

		mat3& multiply(const mat3& other);
		friend mat3 operator*(mat3  left, const mat3& right);
		mat3& operator*=(const mat3& other);

		/*
		static mat3 translation(const vec3& translation);
		static mat3 rotation(float angle, const vec3& axis);
		static mat3 scale(const vec3& scale);
		*/

		static mat3 xRotation(float angle);
		static mat3 yRotation(float angle);
		static mat3 zRotation(float angle);

		friend std::ostream& operator<<(std::ostream&, const mat3& matrix);

	};

	vec3 MAT3_MULT(const mat3& mat, const vec3& vec);

}