#include "stdafx.h"
#include "CollisionDynamics.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_errno.h>
#include "Gas.h"

/**
	Collysion Dynamics Class
	This class outputs the deflection angle of a particle coming towards (from our point of view) a stationary particle

	TODO: Change input params of class itself (from radius, angle, b to function_params)
	The class takes in the function_params parameters and
	1) Uses root solver to find positive root W (dimensionless coordinate) (Eqn 2.20)
	2) Inputs positive root W to an integral to find the angle of the apse line (Eqn 2.19)
	3) Finally finds the deflection angle (Eqn 2.21)

**/
CollisionDynamics::CollisionDynamics(double b, double m, double c, double k, double n, Gas g)
	: b(b), m(m), c(c), k(k), n(n), g(g)
{
	getFinalVelocity(getDeflectionAngle(getApseLine(getPositiveRootW())));
}

CollisionDynamics::CollisionDynamics(double b, double c, Gas g, double* cr)
	: b(b), c(c), g(g), cr(cr)
{
	extractVariables(g);
	getFinalVelocity(getDeflectionAngle(getApseLine(getPositiveRootW())));
}

/**
	Function to extract values from real gases (ie Kappa value)
**/
void CollisionDynamics::extractVariables(Gas g) {
	m = g.getMol_mass();
	n = g.getNu();
	k = g.getKappa();
}

/**
	Function paramters for root finding and integration
	m = mass
	c = velocity
	k = kappa	(constant in IPL) 
	n = miu     (coefficient of viscosity) 
**/
struct function_params {
	double b, m, c, k, n;
};


/**
	Function to find the positive root W (result is the actual equation)
**/
double rootFunction(double x, void *p) {
	struct function_params * params
		= (struct function_params *)p;

	//std::cout << params->b << std::endl;
	//std::cout << params->m << std::endl;
	//std::cout << params->c << std::endl;
	//std::cout << params->k << std::endl;
	//std::cout << params->n << std::endl;

	//system("pause");
	
	double result = 1.0 - x * x - (params->k*pow((params->b / x), 1 - params->n) / (params->n - 1) / (.5*params->m*params->c*params->c));
	return result;
}	

/**
	Getting deflection angle
**/
double CollisionDynamics::getDeflectionAngle(double mApseAngle) {
	std::cout << "//////////////GETTING DEFLECTION ANGLE///////////////" << std::endl;
	std::cout << "////////////// FOR A PARTICLES WITH B : " << b << ", M : " << m << ", C : " << c << ", K : " << k << ", N : " << n << " ///////////////" << std::endl;
	std::cout << "////////////// DEFLECTION ANGLE: " << (M_PI - 2 * mApseAngle) * 180 / M_PI <<	" ///////////////" << std::endl;
	std::cout << "//////////////FINISHED GETTING DEFLECTION ANGLE///////////////" << std::endl << std::endl;
	return (M_PI - 2 * mApseAngle);
}

void CollisionDynamics::getFinalVelocity(double mDeflectionAngle){
	double epsilon = 1.57;
	double cr_absolute = pow(pow(cr[0], 2) + pow(cr[1], 2) + pow(cr[2], 2), 0.5);
	double u_star = cos(mDeflectionAngle) * cr[0] + sin(mDeflectionAngle) * sin(epsilon) * pow(pow(cr[1], 2) + pow(cr[2], 2), 0.5);
	double v_star = cos(mDeflectionAngle) * cr[1] + sin(mDeflectionAngle) * (cr_absolute * cr[2] * cos(epsilon) - cr[0] * cr[1] * sin(epsilon)) / pow(pow(cr[1], 2) + pow(cr[2], 2), 0.5);
	double w_star = cos(mDeflectionAngle) * cr[2] - sin(mDeflectionAngle) * (cr_absolute * cr[2] * cos(epsilon) + cr[0] * cr[2] * sin(epsilon)) / pow(pow(cr[1], 2) + pow(cr[2], 2), 0.5);
	double cr_star_absolute = pow(pow(u_star, 2) + pow(v_star, 2) + pow(w_star, 2), 0.5);
	std::cout << "//////////////FINAL VELOCITY FOUND : " << cr_star_absolute << "///////////////" << std::endl << std::endl;
}

/**
	Getting Apse line angle
**/
double CollisionDynamics::getApseLine(double mRoot) {
	std::cout << "//////////////STARTING INTEGRATION ANGLE OF FOR APSE LINE///////////////" << std::endl;
	std::cout << "USING ROOT : " << mRoot << std::endl;

	double lowerLim = 0., upperLim = mRoot; // limits of integration
	double abserr = 0., relerr = 1.e-7; // requested errors
	double result; // the integral value
	double error; // the error estimate

	size_t np = 1000; // work area size
	gsl_integration_workspace *w = gsl_integration_workspace_alloc(np);

	gsl_function F2;

	struct function_params params = { b, m, c, k, n };

	F2.function = &rootFunction;
	F2.params = &params;

	/*
	Integration method is (should be) Gaussian quadrature 
	*/
	gsl_integration_qag(&F2, lowerLim, upperLim, abserr, relerr, np, GSL_INTEG_GAUSS15, w, &result, &error);

	printf("result = % .18f\n", result);
	printf("estimated error = % .18f\n", error);
	printf("intervals = %zu\n", w->size);

	gsl_integration_workspace_free(w);

	std::cout << "Apse Line is = " << result;
	std::cout << "//////////////ENDING INTEGRATION FOR ANGLE OF APSE LINE///////////////\n\n\n" << std::endl;

	return result;
}

/**
	Getting positive root W
**/
double CollisionDynamics::getPositiveRootW() {

	double mRoot;

	int status;
	int iter = 0, max_iter = 100;
	const gsl_root_fsolver_type *T;
	gsl_root_fsolver *s;
	double r = 0, r_expected = sqrt(5.0);
	double x_lo = 0.0, x_hi = 1.0;
	gsl_function F;

	struct function_params params = { b, m, c, k, n };

	F.function = &rootFunction;
	F.params = &params;

	/*
	Root finding is applied using brent's method (since it does not need the derivative of the equation like Newton's Raphson method)
	https://en.wikipedia.org/wiki/Brent%27s_method
	The "error" (should) be the numerical tolerance	to determine which method is used to find the root
	I might be wrong though
	*/
	T = gsl_root_fsolver_brent;
	s = gsl_root_fsolver_alloc(T);
	gsl_root_fsolver_set(s, &F, x_lo, x_hi);

	std::cout << "//////////////STARTING ROOT SEARCH///////////////" << std::endl;
	printf("using %s method\n",
		gsl_root_fsolver_name(s));

	printf("%5s [%9s, %9s] %9s %10s %9s\n",
		"iter", "lower", "upper", "root",
		"err", "err(est)");

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

		mRoot = r;
	} while (status == GSL_CONTINUE && iter < max_iter);

	gsl_root_fsolver_free(s);
	std::cout << "//////////////ROOT SEARCH END///////////////" << std::endl;

	return mRoot;
}