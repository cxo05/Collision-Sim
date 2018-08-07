#pragma once

struct function_params
{
	double m, c, k, n;
};

double function(double x, void *params);
double collisionDynamicFunction(double x, void *params);