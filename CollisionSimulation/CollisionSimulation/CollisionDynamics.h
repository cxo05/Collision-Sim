#pragma once

class CollisionDynamics
{
private:
	double b, m, c, k, n;
public:
	CollisionDynamics(double b, double m, double c, double k, double n);

	double getPositiveRootW();
	double getApseLine(double mRoot);
	void getDeflectionAngle(double mApseAngle);
};
