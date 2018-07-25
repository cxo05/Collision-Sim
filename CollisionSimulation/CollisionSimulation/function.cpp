#include "function.h"
#include "stdafx.h"
#include <math.h>

double function(double x, void *params)
{
	struct function_params *p
		= (struct function_params *) params;



	return (1 * x + 0) * x + (-5);
}

double iplFunction(double x, void * params)
{
	struct function_params *p
		= (struct function_params *) params;

	//return 1 - pow(x, 2) - (2/ (p->a - 1)) * pow((x/ p->b), p->a-1);
	return 1;
}
