#pragma once
#include "Gas.h"

class CollisionDynamics
{
private:
	double b, m, c, k, n;
	double* cr;
	Gas g;
public:
	CollisionDynamics(double b, double m, double c, double k, double n, Gas g);
	CollisionDynamics(double b, double c, Gas g, double* cr);

	void extractVariables(Gas g);
	double getPositiveRootW();
	double getApseLine(double mRoot);
	double getDeflectionAngle(double mApseAngle);
	void getFinalVelocity(double mDeflectionAngle);
};
