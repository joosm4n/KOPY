#include "maths_func.h"
#include "vec3.h"
#include "mat4.h"

#define CHERO_RIGHT 1

namespace maths {

	mat4::mat4()
	{
		for (int i = 0; i < 4 * 4; i++) 
			elements[i] = 0.0f;
	}
	mat4::mat4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}
	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4& mat4::multiply(const mat4& other)
	{
		float result[16];
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				result[x + y * 4] = sum;
			}
		}
		for (int i = 0; i < 16; ++i) {
			elements[i] = result[i];
		}
		return *this;
	}
	mat4 operator*(mat4  left, const mat4 & right)
	{
		return left.multiply(right);
	}
	mat4& mat4::operator*=(const mat4& other)
	{
		return multiply(other);
	}
	vec4 operator*(const mat4& matrix, const vec4& vector)
	{
		vec4 result;
		for (int i = 0; i < 4; i++) {
			result[i] = 0;
			for (int j = 0; j < 4; j++) {
				result[i] += matrix.elements[i + j * 4] * vector[j];
			}
		}
		return result;
	}
	vec4 operator*(const vec4& vector, const mat4& matrix)
	{
		return matrix * vector;
	}

	mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 result(1.0f);

#if CHERNO_RIGHT
		// KIERAN'S
		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = -2.0f / (far - near);

		result.elements[0 + 3 * 4] = (right + left) / (right - left);
		result.elements[1 + 3 * 4] = (top + bottom) / (top - bottom);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);
#else
		// CHERNO'S
		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);
#endif
		return result;
	}
	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		

#if CHERNO_RIGHT
		// KIERAN'S
		mat4 result;
		result.elements[3 + 2 * 4] = 1;
		float b = (-near + -far) / (near - far);
		float c = (2.0f * near * far) / (near - far);
#else
		// CHERNO'S
		mat4 result(1.0f);
		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);
		result.elements[3 + 2 * 4] = -1.0f;
#endif

		float q = 1.0f / tan(0.5f * toRadians(fov));
		float a = q / aspectRatio;

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[2 + 3 * 4] = c;

		return result;
	}
	mat4 mat4::translation(const vec3& translation)
	{
		mat4 result(1.0f);
		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;
		
		return result;
	}
	mat4 mat4::scale(const vec3& scale)
	{
		mat4 result(1.0f);
		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}
	mat4 mat4::rotation(float angle, const vec3& axis)
	{
#if MAYBE_WRONG
		mat4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

#else
		mat4 result(1.0f);

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		float len = sqrt(x * x + y * y + z * z);
		if (len == 0.0f)
			return result; // no rotation for zero axis

		// Normalize axis to avoid distortion
		x /= len; y /= len; z /= len;

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		// Fill the 3x3 rotation block (row + col*4 indexing)
		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = z * x * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[2 + 1 * 4] = z * y * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * z * omc + c;

		// Ensure the rest remains the identity for homogeneous coords
		result.elements[3 + 3 * 4] = 1.0f;

		return result;

#endif
		return result;
	}



#if 1
	std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
	{
		stream << "mat4: (\n ";
		for (int y = 0; y < 4; y++) 
		{
			for (int x = 0; x < 4; x++)
			{
				stream << matrix.elements[y + x * 4] << ", ";
			}
			stream << "\n ";
		}
		stream << ")";

		return stream;
	}
#endif

	mat4 inverse(const mat4& m) 
	{
		double inv[16], det;
		int i;

		inv[0] = m.elements[5] * m.elements[10] * m.elements[15] -
			m.elements[5] * m.elements[11] * m.elements[14] -
			m.elements[9] * m.elements[6] * m.elements[15] +
			m.elements[9] * m.elements[7] * m.elements[14] +
			m.elements[13] * m.elements[6] * m.elements[11] -
			m.elements[13] * m.elements[7] * m.elements[10];

		inv[4] = -m.elements[4] * m.elements[10] * m.elements[15] +
			m.elements[4] * m.elements[11] * m.elements[14] +
			m.elements[8] * m.elements[6] * m.elements[15] -
			m.elements[8] * m.elements[7] * m.elements[14] -
			m.elements[12] * m.elements[6] * m.elements[11] +
			m.elements[12] * m.elements[7] * m.elements[10];

		inv[8] = m.elements[4] * m.elements[9] * m.elements[15] -
			m.elements[4] * m.elements[11] * m.elements[13] -
			m.elements[8] * m.elements[5] * m.elements[15] +
			m.elements[8] * m.elements[7] * m.elements[13] +
			m.elements[12] * m.elements[5] * m.elements[11] -
			m.elements[12] * m.elements[7] * m.elements[9];

		inv[12] = -m.elements[4] * m.elements[9] * m.elements[14] +
			m.elements[4] * m.elements[10] * m.elements[13] +
			m.elements[8] * m.elements[5] * m.elements[14] -
			m.elements[8] * m.elements[6] * m.elements[13] -
			m.elements[12] * m.elements[5] * m.elements[10] +
			m.elements[12] * m.elements[6] * m.elements[9];

		inv[1] = -m.elements[1] * m.elements[10] * m.elements[15] +
			m.elements[1] * m.elements[11] * m.elements[14] +
			m.elements[9] * m.elements[2] * m.elements[15] -
			m.elements[9] * m.elements[3] * m.elements[14] -
			m.elements[13] * m.elements[2] * m.elements[11] +
			m.elements[13] * m.elements[3] * m.elements[10];

		inv[5] = m.elements[0] * m.elements[10] * m.elements[15] -
			m.elements[0] * m.elements[11] * m.elements[14] -
			m.elements[8] * m.elements[2] * m.elements[15] +
			m.elements[8] * m.elements[3] * m.elements[14] +
			m.elements[12] * m.elements[2] * m.elements[11] -
			m.elements[12] * m.elements[3] * m.elements[10];

		inv[9] = -m.elements[0] * m.elements[9] * m.elements[15] +
			m.elements[0] * m.elements[11] * m.elements[13] +
			m.elements[8] * m.elements[1] * m.elements[15] -
			m.elements[8] * m.elements[3] * m.elements[13] -
			m.elements[12] * m.elements[1] * m.elements[11] +
			m.elements[12] * m.elements[3] * m.elements[9];

		inv[13] = m.elements[0] * m.elements[9] * m.elements[14] -
			m.elements[0] * m.elements[10] * m.elements[13] -
			m.elements[8] * m.elements[1] * m.elements[14] +
			m.elements[8] * m.elements[2] * m.elements[13] +
			m.elements[12] * m.elements[1] * m.elements[10] -
			m.elements[12] * m.elements[2] * m.elements[9];

		inv[2] = m.elements[1] * m.elements[6] * m.elements[15] -
			m.elements[1] * m.elements[7] * m.elements[14] -
			m.elements[5] * m.elements[2] * m.elements[15] +
			m.elements[5] * m.elements[3] * m.elements[14] +
			m.elements[13] * m.elements[2] * m.elements[7] -
			m.elements[13] * m.elements[3] * m.elements[6];

		inv[6] = -m.elements[0] * m.elements[6] * m.elements[15] +
			m.elements[0] * m.elements[7] * m.elements[14] +
			m.elements[4] * m.elements[2] * m.elements[15] -
			m.elements[4] * m.elements[3] * m.elements[14] -
			m.elements[12] * m.elements[2] * m.elements[7] +
			m.elements[12] * m.elements[3] * m.elements[6];

		inv[10] = m.elements[0] * m.elements[5] * m.elements[15] -
			m.elements[0] * m.elements[7] * m.elements[13] -
			m.elements[4] * m.elements[1] * m.elements[15] +
			m.elements[4] * m.elements[3] * m.elements[13] +
			m.elements[12] * m.elements[1] * m.elements[7] -
			m.elements[12] * m.elements[3] * m.elements[5];

		inv[14] = -m.elements[0] * m.elements[5] * m.elements[14] +
			m.elements[0] * m.elements[6] * m.elements[13] +
			m.elements[4] * m.elements[1] * m.elements[14] -
			m.elements[4] * m.elements[2] * m.elements[13] -
			m.elements[12] * m.elements[1] * m.elements[6] +
			m.elements[12] * m.elements[2] * m.elements[5];

		inv[3] = -m.elements[1] * m.elements[6] * m.elements[11] +
			m.elements[1] * m.elements[7] * m.elements[10] +
			m.elements[5] * m.elements[2] * m.elements[11] -
			m.elements[5] * m.elements[3] * m.elements[10] -
			m.elements[9] * m.elements[2] * m.elements[7] +
			m.elements[9] * m.elements[3] * m.elements[6];

		inv[7] = m.elements[0] * m.elements[6] * m.elements[11] -
			m.elements[0] * m.elements[7] * m.elements[10] -
			m.elements[4] * m.elements[2] * m.elements[11] +
			m.elements[4] * m.elements[3] * m.elements[10] +
			m.elements[8] * m.elements[2] * m.elements[7] -
			m.elements[8] * m.elements[3] * m.elements[6];

		inv[11] = -m.elements[0] * m.elements[5] * m.elements[11] +
			m.elements[0] * m.elements[7] * m.elements[9] +
			m.elements[4] * m.elements[1] * m.elements[11] -
			m.elements[4] * m.elements[3] * m.elements[9] -
			m.elements[8] * m.elements[1] * m.elements[7] +
			m.elements[8] * m.elements[3] * m.elements[5];

		inv[15] = m.elements[0] * m.elements[5] * m.elements[10] -
			m.elements[0] * m.elements[6] * m.elements[9] -
			m.elements[4] * m.elements[1] * m.elements[10] +
			m.elements[4] * m.elements[2] * m.elements[9] +
			m.elements[8] * m.elements[1] * m.elements[6] -
			m.elements[8] * m.elements[2] * m.elements[5];

		det = m.elements[0] * inv[0] + m.elements[1] * inv[4] + m.elements[2] * inv[8] + m.elements[3] * inv[12];

		if (det == 0)
			return false;

		det = 1.0 / det;

		mat4 invOut;
		for (i = 0; i < 16; i++) {
			invOut.elements[i] = inv[i] * det;
		}

		return invOut;
	}

}