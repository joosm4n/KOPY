
#include "maths_func.h"
#include "mat3.h"

namespace maths {

	mat3::mat3()
	{
		for (int i = 0; i < 3 * 3; i++)
			elements[i] = 0.0f;
	}
	mat3::mat3(float diagonal)
	{
		for (int i = 0; i < 3 * 3; i++)
			elements[i] = 0.0f;

		elements[0 + 0 * 3] = diagonal;
		elements[1 + 1 * 3] = diagonal;
		elements[2 + 2 * 3] = diagonal;
	}
	mat3 mat3::identity()
	{
		return mat3(1.0f);
	}

	mat3& mat3::multiply(const mat3& other)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 3; e++)
				{
					sum += elements[x + e * 3] * other.elements[e + y * 3];
				}
				elements[x + y * 3] = sum;
			}
		}

		return *this;
	}

	mat3 operator*(mat3  left, const mat3& right)
	{
		return left.multiply(right);
	}

	mat3& mat3::operator*=(const mat3& other)
	{
		return multiply(other);
	}

	mat3 mat3::xRotation(float angle)
	{
		mat3 result(1.0f);
		float rads = toRadians(angle);
		result.elements[0] = 1;
		result.elements[1] = 0;
		result.elements[2] = 0;
		result.elements[3] = 0;
		result.elements[4] = std::cos(rads);
		result.elements[5] = -std::sin(rads);
		result.elements[6] = 0;
		result.elements[7] = std::sin(rads);
		result.elements[8] = std::cos(rads);
		return result;
	}
	mat3 mat3::yRotation(float angle)
	{
		mat3 result(1.0f);
		float rads = toRadians(angle);
		result.elements[0] = std::cos(rads);
		result.elements[1] = 0;
		result.elements[2] = std::sin(rads);
		result.elements[3] = 0;
		result.elements[4] = 1;
		result.elements[5] = 0;
		result.elements[6] = -std::sin(rads);
		result.elements[7] = 0;
		result.elements[8] = std::cos(rads);
		return result;
	}
	mat3 mat3::zRotation(float angle)
	{
		mat3 result(1.0f);
		float rads = toRadians(angle);
		result.elements[0] = std::cos(rads);
		result.elements[1] = -std::sin(rads);
		result.elements[2] = 0;
		result.elements[3] = std::sin(rads);
		result.elements[4] = std::cos(rads);
		result.elements[5] = 0;
		result.elements[6] = 0;
		result.elements[7] = 0;
		result.elements[8] = 1;
		return result;
	}

	vec3 MAT3_MULT(const mat3& mat, const vec3& vec)
	{
		vec3 result;
		result.x = (mat.elements[0] * vec.x +
					mat.elements[1] * vec.y +
					mat.elements[2] * vec.z );

		result.y = (mat.elements[3] * vec.x +
					mat.elements[4] * vec.y +
					mat.elements[5] * vec.z );

		result.z = (mat.elements[6] * vec.x +
					mat.elements[7] * vec.y +
					mat.elements[8] * vec.z );

		return result;
	}

	/*
	mat3 mat3::rotation(float angle, const vec3& axis)
	{
		mat3 result(1.0f);

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

		return result;
	}
	*/
#if 1
	std::ostream& operator<<(std::ostream& stream, const mat3& matrix)
	{
		stream << "mat3: (\n ";
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
}