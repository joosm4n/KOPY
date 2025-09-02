
#include "maths_func.h"


namespace maths {

	vec3 BaryCentricWeight(const vec2& p, const vec2& a, const vec2& b, const vec2& c)
	{
		// Get double the signed area of all three triangles that make up ABC
		const float BCP = EdgeFunc(b, c, p);
		const float CAP = EdgeFunc(c, a, p);
		const float ABP = EdgeFunc(a, b, p);
		const float ABC = EdgeFunc(a, b, c);

		// We now have the weights of the point P towards each of the vertices (Barycentric coordinates)
		const float weightA = BCP / ABC;
		const float weightB = CAP / ABC;
		const float weightC = ABP / ABC;

		// Return the normalized weight
		return vec3(weightA, weightB, weightC);
	}

	// Function that returns the y value from 2 points and an x value
	float LinearInterp(float x, const vec2& pt1, const vec2& pt2)
	{
		return 0.0f;
	}

	float GetZPoint(const float x, const float y, const vec3& pt1, const vec3& pt2, const vec3& pt3)
	{
		if (pt1.z == pt2.z && pt2.z == pt3.z)
			return pt1.z;

		float A = pt1.y * (pt2.z - pt3.z) + pt2.y * (pt3.z - pt1.z) + pt3.y * (pt1.z - pt2.z);
		float B = pt1.z * (pt2.x - pt3.x) + pt2.z * (pt3.x - pt1.x) + pt3.z * (pt1.x - pt2.x);
		float C = pt1.x * (pt2.y - pt3.y) + pt2.x * (pt3.y - pt1.y) + pt3.x * (pt1.y - pt2.y);
		float D = -pt1.x * (pt2.y * pt3.z - pt3.y * pt2.z) - pt2.x * (pt3.y * pt1.z - pt1.y * pt3.z) - pt3.x * (pt1.y * pt2.z - pt2.y * pt1.z);

		if (C == 0.0f) return pt1.z;

		return (D - (A * x) - (B * y)) / C;
	}
	float GetZPointLine(const float x, const float y, const vec3& pt1, const vec3& pt2, float* t_in)
	{
		float t = 0.0f;
		if (t_in != nullptr)
			t = *t_in;

		vec3 dir = pt2 - pt1;
		if (std::abs(dir.x) > 1e-6f)
			t = (x - pt1.x) / dir.x;
		else if (std::abs(dir.y) > 1e-6f)
			t = (y - pt1.y) / dir.y;
		else
			throw std::runtime_error("Line is vertical in both x and y, can't solve for z from (x, y)");

		return pt1.z + t * dir.z;
	}

	bool PointInTriangle(const vec2& p, const vec2& a, const vec2& b, const vec2& c, vec3* weight)
	{
		// Get double the signed area of all three triangles that make up ABC
		const float BCP = EdgeFunc(b, c, p);
		const float CAP = EdgeFunc(c, a, p);
		const float ABP = EdgeFunc(a, b, p);

		const float ABC = EdgeFunc(a, b, c);
		if (weight != nullptr)
		{
			// We now have the weights of the point P towards each of the vertices (Barycentric coordinates)
			const float oneOverABC = 1 / ABC;
			weight->x = BCP * oneOverABC;
			weight->y = CAP * oneOverABC;
			weight->z = ABP * oneOverABC;
		}
		return ((ABP > 0 && BCP > 0 && CAP > 0) && abs(ABC * 0.5f) > 0);
	}
}