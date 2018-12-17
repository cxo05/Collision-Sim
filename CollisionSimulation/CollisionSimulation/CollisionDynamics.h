#pragma once
#include "Gas.h"
#include <Eigen/Dense>

class CollisionDynamics
{
private:
	double b, m, c, k, n, deflectionAngle, epsilon;
	Eigen::Vector3d cr1, cr2, newV, finalVa;
	Gas g;

	int OoM(double mRoot);
public:
	CollisionDynamics(double b, double c, Gas g, Eigen::Vector3d cr1, Eigen::Vector3d cr2, Eigen::Vector3d newV, double epsilon);

	void extractVariables(Gas g);
	double getPositiveRootW();
	double getApseLine(double mRoot);
	double getDeflectionAngle(double mApseAngle);
	void getFinalVelocity(double mDeflectionAngle);

	double getDeflectionAngle();
	Eigen::Vector3d getFinalV1();
	Eigen::Vector3d getFinalV2();
};
