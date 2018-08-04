#include "function.h"
#include "stdafx.h"
#include <math.h>

double function(double x, void *params)
{
	struct function_params *p
		= (struct function_params *) params;

	//double result = 1.0 - (p->b/x)*(p->b/x - (p->k*pow(p->r, -p->n + 1) / (p->n - 1) / (.5*p->m*p->c*p->c));
	double result = 1.0 - x*x - (1*pow(x, 4) / (5 - 1) / (.5));

	return result;
}

double iplFunction(double x, void * params)
{
	struct function_params *p
		= (struct function_params *) params;

	//return 1 - pow(x, 2) - (2/ (p->a - 1)) * pow((x/ p->b), p->a-1);
	return 1;
}
