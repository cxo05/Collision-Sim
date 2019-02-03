#pragma once
#include <math.h>
#include <Eigen/Dense>

class RandomParameters {
public:
	RandomParameters();
	double viscosity_index;
	double coefficient_of_viscosity;
	double get_CrRef();
	Eigen::Vector3d get_3D_Cr();
	Eigen::Vector3d get_coordinates_at_contact(double n, double diameter, Eigen::Vector3d cr1, Eigen::Vector3d cr2);
	double get_B(Eigen::Vector3d a_coord, Eigen::Vector3d b_coord, Eigen::Vector3d newV);
	~RandomParameters();

	void setCoefficientOfViscosity(double cov);
	void setMass(double mass);
	void setViscosityIndex(double vi);
	void setDiameter(double diameter);
	void setTemperature(double T);
	void setV();

	double getCoefficientOfViscosity();
	double getMass();
	double getViscosityIndex();
	double getDiameter();
	double getTemperature();
	double getTimeToCollision();

private:
	double k = 1.380658e-23; //Boltzmann_constant
	double mass;
	double v;
	double diameter;
	double T;
	double time;

	Eigen::Vector3d l_prime, l;
};

