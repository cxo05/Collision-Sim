#pragma once
#include <math.h>
#include <Eigen/Dense>

class RandomParameters {
public:
	RandomParameters();
	double viscosity_index = 0.67;
	double coefficient_of_viscosity = 0.845e-5; //Hydrogen : 0.845 * 10^-5
	double get_DRef();
	double get_CrRef();
	Eigen::Vector3d get_3D_Cr();
	Eigen::Vector3d get_coordinates();
	double get_B(Eigen::Vector3d a_coord, Eigen::Vector3d b_coord, Eigen::Vector3d newV);
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
	double k = 1.380658e-23; //Boltzmann_constant
	double mass = 3.34e-27; //Hydrogen : 3.34 * 10^-27 kg
	double v = viscosity_index - 0.5;
	double diameter = 2.92e-10; //Hydrogen 2.92 * 10^-10
	double radius = diameter / 2;
	double T = 273.0; //Temperature in kelvins
	double density = 1.292; //Density of air kg/m^3
};

