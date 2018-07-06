#pragma once

class Ipl
{
private:
	const double mViscousity = 1;
	const double mIplConstant = 1;
	double radius;
public:
	Ipl(double radius);
	double getForce(double radius);
	double getPotential(double radius);
	double getW0(double radius);
	double getW(double radius);
	double getDeflectionAngle(double radius);
	double getCrossSection(double radius);
	double getFunction(double x, void *params);
	double mIntegration(double W1);
};
