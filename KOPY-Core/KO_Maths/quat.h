#pragma once

#include "vec4.h"

namespace maths {

	struct quat
	{
		float w, x, y, z;

		quat();
		quat(float _w, float _x, float _y, float _z);
		quat(const vec4& vector);

		quat operator*(const quat& q) const;
		void normalize();
	};

	quat AngleAxisToQuat(float angle, const vec3& axis);
	void QuatToAngleAxis(const quat& q, float* angleOut, vec3* axisOut);
	void AngleAxis(float angleA, const vec3& axisA,
					float angleB, const vec3& axisB,
					float* angleOut, vec3* axisOut);
}