#pragma once

class Ipl
{
private:
	const double mViscousity = 1;
	const double mIplConstant = 1;
	double radius, b;
	float angle;
public:
	Ipl(double radius, float angle, double b);
	double getForce();
	double getPotential();
	double getW0();
	double getW();
	double getDeflectionAngle();
	double getCrossSection();
	double getFunction(double x, void *params);
	//double mIntegration(double W1);
};
