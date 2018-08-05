#include "function.h"
#include "stdafx.h"
#include <math.h>

double function(double x, void *params)
{
	struct function_params *p
		= (struct function_params *) params;

	return x;
}

double collisionDynamicFunction(double x, void * params)
{
	struct function_params *p
		= (struct function_params *) params;

	return x;
}
