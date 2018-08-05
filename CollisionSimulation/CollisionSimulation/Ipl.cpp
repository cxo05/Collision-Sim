#include "stdafx.h"
//#include "Ipl.h"
//#include <math.h>
//#include <string>
//#include <sstream>
//#include <iostream>
//#include <gsl/gsl_integration.h>
//#include <gsl/gsl_roots.h>
//#include <gsl/gsl_errno.h>
//
//#include "function.h"
//
//Ipl::Ipl(double radius, float angle, double b) 
//	: radius(radius), angle(angle), b(b)
//{}
//
//double Ipl::getForce() {
//	return mIplConstant / (pow(radius, mViscousity));
//}
//double Ipl::getPotential() {
//	return mIplConstant / ((mViscousity - 1) * pow(radius, mViscousity - 1));
//}
//double Ipl::getW0() {
//	//TODO Get parameters from Particle Class
//	double b = 1, mass = 1, rVelocity = 1;
//	return b * pow((mass*pow(rVelocity, 2) / mIplConstant), 1 / (mViscousity - 1));
//}
//double Ipl::getW() {
//	//TODO Get parameters from Particle Class
//	return 0;
//}
//double Ipl::getDeflectionAngle() {
//	//TODO Get parameters from Particle Class
//	return 0;
//}
//double Ipl::getCrossSection() {
//	//TODO Get parameters from Particle Class
//	return 0;
//}
//
//double Ipl::getPositiveRootW() {
//	//TODO Set up function to input 
//	int status;
//	int iter = 0, max_iter = 100;
//	const gsl_root_fsolver_type *T;
//	gsl_root_fsolver *s;
//	double r = 0, r_expected = sqrt(5.0);
//	double x_lo = 1, x_hi = 5.0;
//	gsl_function F;
//
//	//TODO Input correct params
//	struct function_params params = { 1.0, 1.0, 1.0, 1.0, 5.0};
//
//	F.function = &function;
//	F.params = &params;
//
//	T = gsl_root_fsolver_brent;
//	s = gsl_root_fsolver_alloc(T);
//	gsl_root_fsolver_set(s, &F, x_lo, x_hi);
//
//	printf("using %s method\n",
//		gsl_root_fsolver_name(s));
//
//	printf("%5s [%9s, %9s] %9s %10s %9s\n",
//		"iter", "lower", "upper", "root",
//		"err", "err(est)");
//
//	do
//	{
//		iter++;
//		status = gsl_root_fsolver_iterate(s);
//		r = gsl_root_fsolver_root(s);
//		x_lo = gsl_root_fsolver_x_lower(s);
//		x_hi = gsl_root_fsolver_x_upper(s);
//		status = gsl_root_test_interval(x_lo, x_hi,
//			0, 0.001);
//
//		if (status == GSL_SUCCESS)
//			printf("Converged:\n");
//
//		printf("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
//			iter, x_lo, x_hi,
//			r, r - r_expected,
//			x_hi - x_lo);
//	} while (status == GSL_CONTINUE && iter < max_iter);
//
//	gsl_root_fsolver_free(s);
//
//	return r;
//}