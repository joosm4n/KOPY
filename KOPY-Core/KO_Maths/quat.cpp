
#include "quat.h"
#include <algorithm>

namespace maths {

	quat::quat()
	{
		w = 1;
		x = 0;
		y = 0;
		z = 0;
	}
	quat::quat(float _w, float _x, float _y, float _z)
	{
		w = _w;
		x = _x;
		y = _y;
		z = _z;
	}
	quat::quat(const vec4& vector)
	{
		w = vector.w;
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	quat quat::operator*(const quat& q) const {
		return quat(
			w * q.w - x * q.x - y * q.y - z * q.z,
			w * q.x + x * q.w + y * q.z - z * q.y,
			w * q.y - x * q.z + y * q.w + z * q.x,
			w * q.z + x * q.y - y * q.x + z * q.w
		);
	}

	void quat::normalize() {
		float len = std::sqrt(w * w + x * x + y * y + z * z);
		if (len > 1e-6f) {
			w /= len; x /= len; y /= len; z /= len;
		}
	}

	quat AngleAxisToQuat(float angle, const vec3& axis) {
		vec3 n = axis;
		normalize(n);
		float half = 0.5f * angle;
		float s = std::sin(half);
		return quat(std::cos(half), n.x * s, n.y * s, n.z * s);
	}

	void QuatToAngleAxis(const quat& q, float* angleOut, vec3* axisOut) {
		quat nq = q;
		nq.normalize();

		float angle = 2.0f * std::acos(std::clamp(nq.w, -1.0f, 1.0f));
		float s = std::sqrt(1.0f - nq.w * nq.w);

		if (s < 1e-6f) {
			*axisOut = vec3(1.0f, 0.0f, 0.0f);
		}
		else {
			*axisOut = vec3(nq.x / s, nq.y / s, nq.z / s);
		}
		*angleOut = angle;
	}

	void AngleAxis(float angleA, const vec3& axisA,
		float angleB, const vec3& axisB,
		float* angleOut, vec3* axisOut)
	{
		quat qA = AngleAxisToQuat(angleA, axisA);
		quat qB = AngleAxisToQuat(angleB, axisB);

		// Composition: first apply A, then B
		quat qResult = qB * qA;
		qResult.normalize();

		QuatToAngleAxis(qResult, angleOut, axisOut);
	}
}