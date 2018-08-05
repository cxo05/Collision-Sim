#include "function.h"
#include "stdafx.h"
#include <math.h>

double function(double x, function_params *params)
{
	double result = 1.0 - x*x - (params->k*pow(x, params->n + 1) / (params->n - 1) / (.5*params->m*params->c*params->c));
	//double result = 1.0 - x*x - (1*pow(x, 4) / (5 - 1) / (.5));

	return result;
}
