#pragma once

#include "vec3.h"
#include "vec4.h"

namespace maths {

	__declspec(align(4)) struct mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 columns[4];
		};
		
		mat4();
		mat4(float diagonal);

		static mat4 identity();

		mat4& multiply(const mat4& other);
		friend mat4 operator*(mat4  left, const mat4& right);
		mat4& operator*=(const mat4& other);
		friend vec4 operator*(const mat4& matrix, const vec4& vector);
		friend vec4 operator*(const vec4& vector, const mat4& matrix);

		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);
	
		friend std::ostream& operator<<(std::ostream&, const mat4& matrix);

		
	};

	mat4 inverse(const mat4& m);
}