#include "function.h"
#include "stdafx.h"
#include <math.h>

struct function_params {
	double b, m, c, k, n;
};

double function(double x, void *p)
{
	struct function_params * params
		= (struct function_params *)p;

	double result = 1.0 - x*x - (params->k*pow(x, params->n + 1) / (params->n - 1) / (.5*params->m*params->c*params->c));
	//double result = 1.0 - x*x - (1*pow(x, 4) / (5 - 1) / (.5));

	return result;
}
