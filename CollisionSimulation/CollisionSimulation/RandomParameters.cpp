#include "stdafx.h"
#include "RandomParameters.h"
#include <random>
#include <chrono>
#include <iostream>

RandomParameters::RandomParameters() {
}

float RandomParameters::get_DRef() {
	//Currently just set to 1.0f
	return 1.0f;
}

float RandomParameters::get_CrRef() {
	//Boltzmann_constant
	float k = 1.380658 * pow(10, -23); //JK^-1
	float coefficient_of_viscosity = 0.845 * pow(10, -5); //Hydrogen : 0.845 * 10^-5
	float mass = 3.34 * pow(10, -27); //Hydrogen : 3.34 * 10^-27 kg
	float viscosity_index = 0.67; //Hydrogen : 0.67
	float v = viscosity_index - 0.5;
	//Temperature in kelvins
	float T = 298.0;
	//Total collision cross section
	float sigmaT = 3.1415 * 1.2 * pow(10, -10) * 1.2 * pow(10, -10); //Diameter of hydrogen : 1.2 * 10^-10
	float inner = (15/8 * sqrt(3.1415*mass*k) * pow(4*k/mass, v) * pow(T, 0.5+v)) / 
					(viscosity_index * sigmaT * tgamma(4-v));
	float Cr_ref = pow(sqrt(inner), 1/v);
	return Cr_ref;
}

float RandomParameters::get_Cr() {
	//From normal distribution of velocity of air molecules
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	float mean = 0;
	float standard_deviation = sqrt(8.314 * 298);
	std::normal_distribution<float> distribution(mean, standard_deviation);
	return distribution(generator);
}

float RandomParameters::get_B() {
	return 0.0f;
}


RandomParameters::~RandomParameters() {
}
