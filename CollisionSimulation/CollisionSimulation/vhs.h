#pragma once
#include <Eigen/Dense>
#include <Eigen/StdVector>

class VHS
{
	public:
		VHS();
		std::vector<Eigen::Vector3d> run(double b, double d, Eigen::Vector3d aCoord, Eigen::Vector3d bCoord, Eigen::Vector3d u1, Eigen::Vector3d u2);
		bool collisionCheck(double b, double d);
		~VHS();
};

