
#include "vec3.h"
#include "mat3.h"
#include <cmath>
#include <cassert>
#include "vec2.h"

namespace maths {

	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	vec3& vec3::subtract(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	vec3& vec3::multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}
	vec3& vec3::divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return*this;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);
	}
	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.subtract(right);
	}
	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.multiply(right);
	}
	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.divide(right);
	}

	vec3 operator+(vec3 left, const float scalar)
	{
		left.x += scalar;
		left.y += scalar;
		left.z += scalar;
		return left;
	}
	vec3 operator-(vec3 left, const float scalar)
	{
		left.x -= scalar;
		left.y -= scalar;
		left.z -= scalar;
		return left;
	}
	vec3 operator*(vec3 left, const float scalar)
	{
		left.x *= scalar;
		left.y *= scalar;
		left.z *= scalar;
		return left;
	}
	vec3 operator/(vec3 left, const float scalar)
	{
		left.x /= scalar;
		left.y /= scalar;
		left.z /= scalar;
		return left;
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		return add(other);
	}
	vec3& vec3::operator-=(const vec3& other)
	{
		return subtract(other);
	}
	vec3& vec3::operator*=(const vec3& other)
	{
		return multiply(other);
	}
	vec3& vec3::operator/=(const vec3& other)
	{
		return divide(other);
	}

	bool vec3::operator==(const vec3& other)
	{
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}
	bool vec3::operator!=(const vec3& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

	double length (const vec3 vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}
	vec3 normalize(const vec3& vector)
	{
		double len = length(vector);
		if ( len == 0) return vec3(0, 0, 0);
		return vec3(vector.x / len, vector.y / len, vector.z / len);
	}
	float dot(const vec3& left, const vec3& right)
	{
		return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
	}

	vec3 vec3::xaxis(const float amount)
	{
		return vec3(1 * amount, 0, 0);
	}
	vec3 vec3::yaxis(const float amount)
	{
		return vec3(0, 1 * amount, 0);
	}
	vec3 vec3::zaxis(const float amount)
	{
		return vec3(0, 0, 1 * amount);
	}

	vec3& vec3::rotateAroundX(const vec3& axis, const float angle)
	{
		vec3 relative = *this - axis;
		mat3 rotMat = mat3::xRotation(angle);
		vec3 rotated = MAT3_MULT(rotMat, relative);
		*this = rotated + axis;
		return *this;
	}
	vec3& vec3::rotateAroundY(const vec3& axis, const float angle)
	{							
		vec3 relative = *this - axis;
		mat3 rotMat = mat3::yRotation(angle);
		vec3 rotated = MAT3_MULT(rotMat, relative);
		*this = rotated + axis;
		return *this;
	}								
	vec3& vec3::rotateAroundZ(const vec3& axis, const float angle)
	{
		vec3 relative = *this - axis;
		mat3 rotMat = mat3::zRotation(angle);
		vec3 rotated = MAT3_MULT(rotMat, relative);
		*this = rotated + axis;
		return *this;
	}

	vec3::operator vec2() const
	{ 
		return vec2(x, y); 
	};

}