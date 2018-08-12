#pragma once

class CollisionDynamics
{
private:
	const double mViscousity = 1;
	const double mIplConstant = 1;
	double radius, b;
	float angle;
public:
	CollisionDynamics(double radius, float angle, double b);

	double getPositiveRootW(); 
	double getApseLine(double mRoot);
	void getDeflectionAngle(double mApseAngle);
};
