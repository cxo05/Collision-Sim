#pragma once
#include <Eigen/Dense>

class VHS
{
	public:
		VHS();
		Eigen::Vector3d* run(double b, double d, double* aCoord, double* bCoord, double* u1, double* u2);
		bool collisionCheck(double b, double d);
		~VHS();
};

