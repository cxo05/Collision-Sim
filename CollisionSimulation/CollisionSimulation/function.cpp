#include "function.h"
#include "stdafx.h"

double function(double x, void *params)
{
	struct function_params *p
		= (struct function_params *) params;



	return (1 * x + 0) * x + (-5);
}
