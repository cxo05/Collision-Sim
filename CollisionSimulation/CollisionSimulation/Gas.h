#pragma once

class Gas
{
private:
	double deg_of_freedom, mol_mass, viscosity_co, viscosity_index;
public:
	Gas();
	Gas(double deg_of_freedom, double mol_mass, double viscosity_co, double viscosity_index);

	double getFreedom();
	double getMol_mass();
	double getViscosity_co();
	double getViscosity_index();

	double getNu();
	double getKappa();
	double getNumericalFactor();
};
