#pragma once

struct function_params
{
	double b, m, c, k, n;
};

double function(double x, function_params *params);