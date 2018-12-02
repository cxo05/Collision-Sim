#pragma once
#include <math.h>

class RandomParameters {
public:
	RandomParameters();
	double viscosity_index = 0.67;
	double coefficient_of_viscosity = 0.845 * pow(10, -5); //Hydrogen : 0.845 * 10^-5
	double get_DRef();
	double get_CrRef();
	void get_3D_Cr(double* cr_vector);
	void get_coordinates(double* coord);
	double get_B(double* a_coord, double* b_coord, double* newV);
	~RandomParameters();

	void setCoefficientOfViscosity(double cov);
	void setMass(double mass);
	void setViscosityIndex(double vi);
	void setDiameter(double diameter);
	void setTemperature(double T);

	double getCoefficientOfViscosity();
	double getMass();
	double getViscosityIndex();
	double getDiameter();
	double getTemperature();

private:
	double k = 1.380658 * pow(10, -23); //Boltzmann_constant
	double mass = 3.34 * pow(10, -27); //Hydrogen : 3.34 * 10^-27 kg
	double v = viscosity_index - 0.5;
	double diameter = 2.92 * pow(10, -10); //Hydrogen 2.92 * 10^-10
	double radius = diameter / 2;
	double T = 273.0; //Temperature in kelvins
	double density = 1.292; //Density of air kg/m^3
};

