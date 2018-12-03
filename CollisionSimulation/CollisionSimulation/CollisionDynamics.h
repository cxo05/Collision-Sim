#pragma once
#include "Gas.h"
#include <Eigen/Dense>

class CollisionDynamics
{
private:
	double b, m, c, k, n, deflectionAngle, finalV;
	Eigen::Vector3d cr;
	double finalVa[3];
	Gas g;
public:
	CollisionDynamics(double b, double m, double c, double k, double n, Gas g);
	CollisionDynamics(double b, double c, Gas g, Eigen::Vector3d cr);

	void extractVariables(Gas g);
	double getPositiveRootW();
	double getApseLine(double mRoot);
	double getDeflectionAngle(double mApseAngle);
	void getFinalVelocity(double mDeflectionAngle);

	double getDeflectionAngle();
	double* getFinalV();
};
