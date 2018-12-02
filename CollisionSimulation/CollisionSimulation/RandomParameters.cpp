#include "stdafx.h"
#include "RandomParameters.h"
#include <random>
#include <chrono>
#include <iostream>

#include <Eigen/Dense>

RandomParameters::RandomParameters() {
}

double RandomParameters::get_DRef() {
	//Currently just set to 1.0
	return 1.0;
}

double RandomParameters::get_CrRef() {
	//Total collision cross section
	double sigmaT = 3.1415 * radius * radius;
	double inner = (15/8 * sqrt(3.1415*mass*k) * pow(4*k/mass, v) * pow(T, 0.5+v)) /
					(coefficient_of_viscosity * sigmaT * tgamma(4-v));
	double Cr_ref = pow(sqrt(inner), 1/v);
	return Cr_ref;
}

 void RandomParameters::get_3D_Cr(double* cr_vector) {
	//From normal distribution of velocity of air molecules generate random 3D vector Cr
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	int mean = 0;
	double standard_deviation = sqrt(8.314 * 298);
	std::normal_distribution<double> distribution(mean, standard_deviation);
	cr_vector[0] = distribution(generator);
	cr_vector[1] = distribution(generator);
	cr_vector[2] = distribution(generator);
}

void RandomParameters::get_coordinates(double* coord) {
	double alpha = 1; //1 for now
	double meanFreePath = (4*alpha*(5-2* viscosity_index)*(7-2* viscosity_index))/
							(5 * (alpha + 1) * (alpha + 2)) * 
							sqrt(mass / (2 * 3.1415 * k * T)) *
							(coefficient_of_viscosity / density);

	//std::cout << "Mean free path for hydrogen : " << meanFreePath << std::endl;
	
	//Choose 2 points within cube of width meanFreePath
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> unif(0, meanFreePath);
	coord[0] = unif(generator);
	coord[1] = unif(generator);
	coord[2] = unif(generator);
}

double RandomParameters::get_B(double* a_coord, double* b_coord, double* newV) {
	double b;
	Eigen::Vector3d newVasd(newV[0], newV[1], newV[2]);
	Eigen::Vector3d asd2(a_coord[0] - b_coord[0], a_coord[1] - b_coord[1], a_coord[2] - b_coord[2]);
	Eigen::Vector3d tem = newVasd.cross(asd2);
	double numerator = tem.norm();
	double denominator = sqrt(newV[0] * newV[0] + newV[1] * newV[1] + newV[2] * newV[2]);
	b = numerator / denominator;
	return b;
}

RandomParameters::~RandomParameters() {
}

void RandomParameters::setCoefficientOfViscosity(double cov) {
	coefficient_of_viscosity = cov;
}

void RandomParameters::setMass(double mass) {
	this->mass = mass;
}

void RandomParameters::setViscosityIndex(double vi) {
	viscosity_index = vi;
}

void RandomParameters::setDiameter(double diameter) {
	this->diameter = diameter;
}

void RandomParameters::setTemperature(double T) {
	this->T = T;
}

double RandomParameters::getCoefficientOfViscosity() {
	return coefficient_of_viscosity;
}

double RandomParameters::getMass() {
	return mass;
}

double RandomParameters::getViscosityIndex() {
	return viscosity_index;
}

double RandomParameters::getDiameter() {
	return diameter;
}

double RandomParameters::getTemperature() {
	return T;
}