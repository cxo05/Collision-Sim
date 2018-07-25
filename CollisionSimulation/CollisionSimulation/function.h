#pragma once
struct function_params
{
	double a, b, c;
};

double function(double x, void *params);
double iplFunction(double x, void *params);