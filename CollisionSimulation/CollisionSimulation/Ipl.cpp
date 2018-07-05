#include "stdafx.h"
#include "Ipl.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "gsl_integration.h"

double Ipl::getForce(double radius) {
	return mIplConstant / (pow(radius, mViscousity));
}
double Ipl::getPotential(double radius) {
	return mIplConstant / ((mViscousity - 1) * pow(radius, mViscousity - 1));
}
double Ipl::getW0(double radius) {
	//TODO Get parameters from Particle Class
	double b = 1, mass = 1, rVelocity = 1;
	return b * pow((mass*pow(rVelocity, 2) / mIplConstant), 1 / (mViscousity - 1));
}
double Ipl::getW(double radius) {
	//TODO Get parameters from Particle Class
	double mass = 1, rVelocity = 1;
	return pow(((getPotential(radius) / (0.5 * mass * pow(rVelocity, 2)))*(mViscousity - 1) / 2), (1 / (mViscousity - 1)))*getW0(radius);
}
double Ipl::getDeflectionAngle(double radius) {
	//TODO Get parameters from Particle Class
	return M_PI - 2 * mIntegration();
}
double Ipl::getCrossSection(double radius) {
	//TODO Get parameters from Particle Class
	//fml
}


double Ipl::getFunction(double x, void *params) {
	double W = *(double *)params, Wo = *(double *)params;

	return pow(1 - pow(W, 2) - (2 / (mIplConstant - 1)) * pow((W / Wo), (mIplConstant - 1)), 0.5);
}



double Ipl::mIntegration() {
	//TODO W1 = positive root of eqn
	double a = 0., b = W1; // limits of integration
	double abserr = 0., relerr = 1.e-7; // requested errors
	double result; // the integral value
	double error; // the error estimate
	double W = 1;

	size_t np = 1000; // work area size
	gsl_integration_workspace *w = gsl_integration_workspace_alloc(np);
	
	gsl_function F;
	
	 F.function = &getFunction;
	 F.params = &W;
	
	gsl_integration_qag(&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15, w, &result, &error);

	printf("result = % .18f\n", result);
	printf("estimated error = % .18f\n", error);
	printf("intervals = %zu\n", w->size);
	
	gsl_integration_workspace_free(w);
	
	return result;
}
