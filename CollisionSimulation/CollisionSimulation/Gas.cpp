#include "stdafx.h"
#include "Gas.h"
#include <cmath>
#include <iostream>

Gas::Gas()
{
}

Gas::Gas(double num_factor, double mol_mass, double temp, double viscosity_co, double viscosity_index)
	: num_factor(num_factor), mol_mass(mol_mass), temp(temp), viscosity_co(viscosity_co), viscosity_index(viscosity_index)
{
}

double Gas::getMol_mass()
{
	return mol_mass;
}

double Gas::getViscosity_co()
{
	return viscosity_co;
}

double Gas::getViscosity_index()
{
	return viscosity_index;
}

double Gas::getTemperature()
{
	return temp;
}

double Gas::getNu()
{
	return (2 / (viscosity_index - 0.5)) + 1;
}

double Gas::getKappa()
{
	double k = 1.380658e-23;
	double gas_constant = k/mol_mass;
	double pi = 3.1415926535897;
		
	// u = 5  * m * (R * T / pi) ^ 0.5 * (2 * m * R * T / k) ^ (2 / (n - 1)) / 8 * A_2(n) * (gamma(4 - 2 / (n - 1))) 
	// 1) expression 1 = u * 8 * A_2(n) * (gamma(4 - 2 / (n - 1))) 
	// exp1 = 5  * m * (R*T/pi) ^ 0.5 * (2 * m * R * T / k) ^ (2 / (n - 1))
	// 2) expression 2 = exp1 / (5  * m * (R * T / pi) ^ 0.5)
	// exp2 = (2 * m * R * T / k) ^ (2 / (n - 1))
	// 3) expression 3 = exp2 ^ ((n - 1) / 2)
	// exp3 = 2 * m * R * T / k
	// 4) expression 4 = 2 * m * R * T / exp3
	// k = exp4

	double expression_1 = (viscosity_co * (8 * getNumericalFactor() * tgamma(4 - 2 / (getNu() - 1))));
	double expression_2 = expression_1 / (5 * mol_mass * sqrt(gas_constant * getTemperature() / pi));
	double expression_3 = pow(expression_2, (getNu() - 1) / 2);
	double expression_4 = (2 * mol_mass * gas_constant * getTemperature()) / expression_3;
	return expression_4;
}

double Gas::getNumericalFactor()
{
	return num_factor;
}