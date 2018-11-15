#pragma once
#include <math.h>

class RandomParameters {
public:
	double viscosity_index_hydrogen = 0.67;
	RandomParameters();
	double get_DRef();
	double get_CrRef();
	double* get_3D_Cr();
	double get_B();
	~RandomParameters();

private:
	//Boltzmann_constant
	double k = 1.380658 * pow(10, -23); 
	
	double coefficient_of_viscosity = 0.845 * pow(10, -5); //Hydrogen : 0.845 * 10^-5
	
	double mass = 3.34 * pow(10, -27); //Hydrogen : 3.34 * 10^-27 kg
	
	double v = viscosity_index_hydrogen - 0.5;
	
	double diameter = 2.92 * pow(10, -10); //Hydrogen 2.92 * 10^-10
	
	double radius = diameter / 2;
	//Temperature in kelvins
	double T = 273.0;
	
	double density = 1.292; //Density of air kg/m^3
};

