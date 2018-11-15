#pragma once
#include <math.h>

class RandomParameters {
public:
	RandomParameters();
	double get_DRef();
	double get_CrRef();
	double get_Cr();
	double get_B();
	~RandomParameters();

private:
	//Boltzmann_constant
	double k = 1.380658 * pow(10, -23); //JK^-1
	double viscosity_index = 0.67; //Hydrogen : 0.67
	double coefficient_of_viscosity = 0.845 * pow(10, -5); //Hydrogen : 0.845 * 10^-5
	double mass = 3.34 * pow(10, -27); //Hydrogen : 3.34 * 10^-27 kg
	double v = viscosity_index - 0.5;
	//Temperature in kelvins
	double T = 298.0;
	double density = 1.292; //Density of air kg/m^3
};

