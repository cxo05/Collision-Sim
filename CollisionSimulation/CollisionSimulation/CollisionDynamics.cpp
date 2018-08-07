#include "stdafx.h"
#include "CollisionDynamics.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_errno.h>

CollisionDynamics::CollisionDynamics(double radius, float angle, double b)
	: radius(radius), angle(angle), b(b)
{
	getPositiveRootW();
}

double r(double x, void * params) {
	(void)params;
	return x;
}

struct function_params {
	double b, m, c, k, n;
};

double rootFunction(double x, void *p) {
	struct function_params * params
		= (struct function_params *)p;

	double result = 1.0 - x * x - (params->k*pow(x, params->n + 1) / (params->n - 1) / (.5*params->m*params->c*params->c));
	//double result = 1.0 - x*x - (1*pow(x, 4) / (5 - 1) / (.5));

	return result;
}

double CollisionDynamics::getPositiveRootW() {
	//TODO
	double mForce = 1;

	double mPhi = 1;

	//TODO Set up function to input 
	int status;
	int iter = 0, max_iter = 100;
	const gsl_root_fsolver_type *T;
	gsl_root_fsolver *s;
	double r = 0, r_expected = sqrt(5.0);
	double x_lo = 0.0, x_hi = 5.0;
	gsl_function F;

	//TODO Input correct params
	struct function_params params = { 1.0, 1.0, 1.0, 1.0, 5.0 };

	F.function = &rootFunction;
	F.params = &params;

	T = gsl_root_fsolver_brent;
	s = gsl_root_fsolver_alloc(T);
	gsl_root_fsolver_set(s, &F, x_lo, x_hi);

	std::cout << "\n\n\n//////////////STARTING ROOT SEARCH///////////////" << std::endl;
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
	} while (status == GSL_CONTINUE && iter < max_iter);

	gsl_root_fsolver_free(s);
	std::cout << "\n\n\n//////////////ROOT SEARCH END///////////////" << std::endl;

	return r;
}