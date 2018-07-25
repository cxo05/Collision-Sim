#include "stdafx.h"
#include "Ipl.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_errno.h>

Ipl::Ipl(double radius, float angle, double b) 
	: radius(radius), angle(angle), b(b)
{}

double Ipl::getForce() {
	return mIplConstant / (pow(radius, mViscousity));
}
double Ipl::getPotential() {
	return mIplConstant / ((mViscousity - 1) * pow(radius, mViscousity - 1));
}
double Ipl::getW0() {
	//TODO Get parameters from Particle Class
	double b = 1, mass = 1, rVelocity = 1;
	return b * pow((mass*pow(rVelocity, 2) / mIplConstant), 1 / (mViscousity - 1));
}
double Ipl::getW() {
	//TODO Get parameters from Particle Class
	double mass = 1, rVelocity = 1;
	//return pow(((getPotential() / (0.5 * mass * pow(rVelocity, 2)))*(mViscousity - 1) / 2), (1 / (mViscousity - 1)))*getW0();
	return 1;
}
double Ipl::getDeflectionAngle() {
	//TODO Get parameters from Particle Class
	//TODO fix this
	//return M_PI - 2 * mIntegration(1);
	return 1;
}
double Ipl::getCrossSection() {
	//TODO Get parameters from Particle Class
	//fml
	return 0;
}

double Ipl::getFunction(double x, void *params) {
	double W = *(double *)params, Wo = *(double *)params;

	return pow(1 - pow(W, 2) - (2 / (mIplConstant - 1)) * pow((W / Wo), (mIplConstant - 1)), 0.5);
}

double Ipl::getPositiveRootW() {
	/*const gsl_root_fsolver_type * T = gsl_root_fsolver_brent;
	gsl_root_fsolver * s = gsl_root_fsolver_alloc(T);

	gsl_function FDF;
	FDF.function = &function_w;
	FDF.params = 0;

	int iter = 0, max_iter = 100, status;
	double r = 0, r_expected = sqrt(5.0);
	double x_lo = 0.0, x_hi = 5.0;

	gsl_root_fsolver_set(s, &FDF, x_lo, x_hi);
	do
	{
		iter++;
		status = gsl_root_fsolver_iterate(s);
		r = gsl_root_fsolver_root(s);
		x_lo = gsl_root_fsolver_x_lower(s);
		x_hi = gsl_root_fsolver_x_upper(s);
		status = gsl_root_test_interval(x_lo, x_hi,
			0, 0.001);

		if (status == GSL_SUCCESS)
			printf("Converged:\n");

		printf("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
			iter, x_lo, x_hi,
			r, r - r_expected,
			x_hi - x_lo);
	} while (status == GSL_CONTINUE && iter < max_iter);

	gsl_root_fsolver_free(s);

	return status;
	*/
	return 1;
}

double function_w(double x, void * params) {
	double potential = 1, mass = 1, r_velocity = 1;
	return 1 - x - potential / (0.5*mass*r_velocity);
}

/*double Ipl::mIntegration(double W1) {
	//TODO W1 = positive root of eqn
	double a = 0., b = W1; // limits of integration
	double abserr = 0., relerr = 1.e-7; // requested errors
	double result; // the integral value
	double error; // the error estimate
	double W = 1;

	size_t np = 1000; // work area size
	gsl_integration_workspace *w = gsl_integration_workspace_alloc(np);
	
	gsl_function F;
	
	//TODO fix this
	//F.function = &getFunction;
	// F.params = &W;
	
	gsl_integration_qag(&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15, w, &result, &error);

	printf("result = % .18f\n", result);
	printf("estimated error = % .18f\n", error);
	printf("intervals = %zu\n", w->size);
	
	gsl_integration_workspace_free(w);
	
	return result;
}
*/