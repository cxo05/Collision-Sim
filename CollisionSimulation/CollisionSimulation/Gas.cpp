#include "stdafx.h"
#include "Gas.h"
#include <cmath>

Gas::Gas()
{
}

Gas::Gas(double deg_of_freedom, double mol_mass, double viscosity_co, double viscosity_index)
	: deg_of_freedom(deg_of_freedom), mol_mass(mol_mass), viscosity_co(viscosity_co), viscosity_index(viscosity_index)
{
}

double Gas::getFreedom()
{
	return deg_of_freedom;
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

double Gas::getNu()
{
	return (2 / (viscosity_index - 0.5)) + 1;
}

double Gas::getKappa()
{
	double gas_constant = 8.314;
	double pi = 3.1415926535897;

	double expression_1 = (viscosity_co * (8 * getNumericalFactor() * tgamma(4 - 2 / (getNu() - 1)))) / pow(5 * mol_mass * (gas_constant * 273.15 / pi), 0.5);
	double expression_2 = pow(expression_1, (getNu() - 1) / 2) / (2 * mol_mass * gas_constant * 273.15);
	return pow(expression_2, -1);
}

double Gas::getNumericalFactor()
{
	return 0.319;
}