
#include "vec4.h"

namespace maths {

	static float F_ZERO = 0.0f;

	
	vec4::vec4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	vec4::vec4(const vec3& other, float _w)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = _w;
	}

	vec4 operator-(const vec4& self)
	{
		return { -self.x,-self.y,-self.z,-self.w, };
	}

	vec4& vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}
	vec4& vec4::subtract(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	vec4& vec4::multiply(const vec4 & other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}
	vec4& vec4::divide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return* this;
	}
	
	vec4& operator+(vec4 left, const vec4& right)
	{
		return left.add(right);
	}
	vec4& operator-(vec4 left, const vec4& right)
	{
		return left.subtract(right);
	}
	vec4& operator*(vec4 left, const vec4& right)
	{
		return left.multiply(right);
	}
	vec4& operator/(vec4 left, const vec4& right)
	{
		return left.divide(right);
	}

	vec4& vec4::operator+=(const vec4& other)
	{
		return add(other);
	}
	vec4& vec4::operator-=(const vec4& other)
	{
		return subtract(other);
	}
	vec4& vec4::operator*=(const vec4& other)
	{
		return multiply(other);
	}
	vec4& vec4::operator/=(const vec4& other) 
	{
		return divide(other);
	}

	bool vec4::operator==(const vec4& other)
	{
		return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
	}
	bool vec4::operator!=(const vec4& other)
	{
		return !(*this == other);
	}

	vec4 operator*(const vec4& self, float scalar)
	{
		return { self.x * scalar, self.y * scalar, self.z * scalar, self.w * scalar };
	}
	vec4 operator*(float scalar, const vec4& self) 
	{
		return self * scalar;
	}

	vec4::operator vec3() const
	{
		return vec3(x, y, z);
	}

	float& vec4::operator[](size_t index)
	{
		switch (index) 
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		default:
			printf("Invalid vec4 index");
			return F_ZERO;
		}
	}
	const float& vec4::operator[](size_t index) const
	{
		switch (index)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		default:
			printf("Invalid vec4 index");
			return F_ZERO;
		}
	}

	std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << "vec4: (" << vector.x <<
					   ", " << vector.y << 
					   ", " << vector.z <<
					   ", " << vector.w << ")";
		
		return stream;
	}

	float length(const vec4& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
	}
	vec4 normalize(const vec4& vector)
	{
		float len = length(vector);
		if (len == 0) return vec4(0, 0, 0, 0);
		return vec4(vector.x / len, vector.y / len, vector.z / len, vector.w / len);
	}

}