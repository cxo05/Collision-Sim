#pragma once
#include <Eigen/Dense>
#include <Eigen/StdVector>

class VHS
{
	public:
		VHS();
		std::vector<Eigen::Vector3d> run(double b, double d, double* aCoord, double* bCoord, double* u1, double* u2);
		bool collisionCheck(double b, double d);
		~VHS();
};

