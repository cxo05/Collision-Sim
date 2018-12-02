#pragma once

class Gas
{
private:
	double num_factor, mol_mass, viscosity_co, viscosity_index, temp;
public:
	Gas();
	Gas(double num_factor, double mol_mass, double temp, double viscosity_co, double viscosity_index);

	double getMol_mass();
	double getViscosity_co();
	double getViscosity_index();
	double getTemperature();
	double getNumericalFactor();

	double getNu();
	double getKappa();
};
