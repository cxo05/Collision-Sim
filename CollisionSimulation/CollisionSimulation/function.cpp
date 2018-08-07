#include "function.h"
#include "stdafx.h"
#include <math.h>

double function(double x, void *params)
{
	struct function_params *p
		= (struct function_params *) params;

	//double k = p->k;
	//double n = p->n;
	//double m = p->m;
	//double c = p->c;

	//double result = 1.0 - (p->b/x)*(p->b/x) - (p->k*pow(p->r, -p->n + 1) / (p->n - 1) / (.5*p->m*p->c*p->c);
	//double result = 1.0 - x*x - (k*pow(x, 1-n) / (n - 1) / (.5*m*c*c));
	double result = 1.0 - x*x - (1*pow(x, 4) / (4) / (.5));

	return result;
}

double collisionDynamicFunction(double x, void * params)
{
	struct function_params *p
		= (struct function_params *) params;

	return x;
}
