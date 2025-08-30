#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "vec3.h"
#include "vec2.h"

namespace maths {

	constexpr double KO_PI = M_PI;
	constexpr double KO_TWOPI = 2 * KO_PI;


	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

	inline  float EdgeFunc(const vec2& a, const vec2& b, const vec2& c)
		{ return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
	inline  float EdgeFunc(const vec3& a, const vec3& b, const vec3& c)
		{ return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

	vec3 BaryCentricWeight(const vec2& p, const vec2& a, const vec2& b, const vec2& c);
	float LinearInterp(float x, const vec2& pt1, const vec2& pt2);
	bool PointInTriangle(const vec2& pt, const vec2& pt1, const vec2& pt2, const vec2& pt3, vec3* weight = nullptr);

	float GetZPoint(const float x, const float y, const vec3& pt1, const vec3& pt2, const vec3& pt3);
	float GetZPointLine(const float x, const float y, const vec3& pt1, const vec3& pt2, float* t_in = { nullptr });
}