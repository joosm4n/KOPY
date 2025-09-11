#pragma once

#include <float.h>

namespace KOPY {

	struct ObjParam
	{
		float max_vel;
		float max_acel;

		ObjParam(float maxVel = FLT_MAX, float maxAcel = FLT_MAX) 
			: max_vel(maxVel)
			, max_acel(maxAcel)
		{ }
	};

}