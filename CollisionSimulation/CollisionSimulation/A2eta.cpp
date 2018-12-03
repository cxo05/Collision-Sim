#include "stdafx.h"
#include "A2eta.h"
#include <gsl/gsl_integration.h>

namespace A2eta {
	double integrand1(double x, void *params) {
		double y = ((double *)params)[0];
		double eta = ((double *)params)[1];
		return 2 * sqrt((1 - y) / (1 - x * x*(1 - y) - pow(x, eta - 1)*y));
	}

	double integrand2(double y, void *params) {
		double eta = ((param_type *)params)->eta;
		double param[2] = { y, eta };
		double singular_pts[] = { 0,1 };
		gsl_integration_workspace * w;
		gsl_function F;
		double result, error, x;
		double L1, L2;
		size_t i, l = ((param_type *)params)->l;

		if (l == 0) return 0;
		w = gsl_integration_workspace_alloc(1000);
		F.function = &integrand1;
		F.params = param;
		gsl_integration_qagp(&F, singular_pts, 2, 1e-8, 1e-8, 1000, w, &result, &error);
		gsl_integration_workspace_free(w);

		L1 = 1; L2 = x = cos(M_PI - result);
		for (i = 1; i < l; i++) {
			double newL = (x * L2 * (2 * i + 1) - i * L1) / (i + 1);
			L1 = L2; L2 = newL;
		}

		return (L2 - 1) * (2 * (1 - y) + (eta - 1)*y) * pow((eta - 1)*y, -(eta + 1) / (eta - 1));
	}

	double angular_integral(size_t l, double eta) {
		param_type param;
		gsl_integration_workspace * w;
		gsl_function F;
		double singular_pts[2] = { 0,1 };
		double result, error;

		w = gsl_integration_workspace_alloc(1000);
		param.l = l; param.eta = eta;
		F.function = &integrand2;
		F.params = &param;
		gsl_integration_qagp(&F, singular_pts, 2, 1e-8, 1e-8, 1000, w, &result, &error);
		gsl_integration_workspace_free(w);

		return result;
	}

	double getA2eta(double eta) {
		return -pow(2., 2 / (eta - 1)) * angular_integral(2, eta) / 3;
	}
}