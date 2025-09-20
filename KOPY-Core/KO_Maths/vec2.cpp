
#include "vec2.h"

namespace maths {

	static float NULL_FLOAT = 0.0f;

	vec2::vec2()
		: x(0), y(0)
	{
	}
	vec2::vec2(const float& X, const float& Y)
		: x(X), y(Y)
	{
	}
	vec2::vec2(const vec3& v)
		: x(v.x), y(v.y)
	{
	}

	vec2& vec2::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}
	vec2& vec2::subtract(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
	vec2& vec2::multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}
	vec2& vec2::divide(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return*this;
	}

	vec2 operator-(const vec2& self)
	{
		return {-self.x, -self.y};
	}

	vec2& operator+(vec2 left, const vec2& right)
	{
		return left.add(right);
	}
	vec2& operator-(vec2 left, const vec2& right)
	{
		return left.subtract(right);
	}
	vec2& operator*(vec2 left, const vec2& right)
	{
		return left.multiply(right);
	}
	vec2& operator/(vec2 left, const vec2& right)
	{
		return left.divide(right);
	}

	vec2 operator+(const vec2& left, const float scalar)
	{							
		return vec2(left.x + scalar, left.y + scalar);
	}							
	vec2 operator-(const vec2& left, const float scalar)
	{							
		return vec2(left.x - scalar, left.y - scalar);
	}							
	vec2 operator*(const vec2& left, const float scalar)
	{								
		return vec2(left.x * scalar, left.y * scalar);
	}							
	vec2 operator/(const vec2& left, const float scalar)
	{
		return vec2(left.x / scalar, left.y / scalar);
	}

	vec2& vec2::operator+=(const vec2& other)
	{
		return add(other);
	}
	vec2& vec2::operator-=(const vec2& other)
	{
		return subtract(other);
	}
	vec2& vec2::operator*=(const vec2& other)
	{
		return multiply(other);
	}
	vec2& vec2::operator/=(const vec2& other)
	{
		return divide(other);
	}

	bool vec2::operator==(const vec2& other)
	{
		return this->x == other.x && this->y == other.y;
	}
	bool vec2::operator!=(const vec2& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "vec2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}
	float& vec2::operator[](size_t index)
	{
		switch (index)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		default:
			std::cerr << "Invalid vec3() index" << std::endl;
			return NULL_FLOAT;
		}
	}

	double length(const vec2 vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}
	float dot(const vec2& left, const vec2& right)
	{
		return (left.x * right.x) + (left.y * right.y);
	}
	vec2 normalize(const vec2& vector)
	{
		double len = length(vector);
		if (len == 0) return vec2(0, 0);
		return vec2(vector.x / len, vector.y / len);
	}

	vec2 perpendicular(const vec2& vector)
	{
		return vec2(vector.y, -vector.x);
	}
	vec2 perpendicularCCW(const vec2& vector)
	{
		return vec2(-vector.y, vector.x);
	}

	vec2 vec2::perp()
	{
		return vec2(this->y, -this->x);
	}
	vec2 vec2::perpCCW()
	{
		return vec2(-this->y, this->x);
	}

	vec2& vec2::Rotate(const float angle)
	{
		double rads = angle * 3.14159265f / 180.0f;
		float cosA = std::cos(rads);
		float sinA = std::sin(rads);

		float origX = x;
		float origY = y;

		this->x = origX * cosA - origY * sinA;
		this->y = origX * sinA + origY * cosA;

		return *this;
	}
	vec2& vec2::RotateAround(const vec2& point, const float angle)
	{
		vec2 diff = *this - point;
		*this = diff.Rotate(angle) + point;
		return *this;
	}

	vec2 GetRotatedVec(vec2 vector, const float angle)
	{
		return vector.Rotate(angle);
	}
	vec2 GetRotatedVecAround(vec2 vector, const vec2& point, const float angle)
	{
		return vector.RotateAround(point, angle);
	}

}
