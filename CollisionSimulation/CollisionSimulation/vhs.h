#pragma once
#include <Eigen/Dense>
#include <Eigen/StdVector>

class VHS
{
	double b, d;
	public:
		VHS(double b, double d);
		std::vector<Eigen::Vector3d> run(Eigen::Vector3d aCoord, Eigen::Vector3d bCoord, Eigen::Vector3d u1, Eigen::Vector3d u2);
		bool collisionCheck();
		double getDeflectionAngle();
		~VHS();
};

