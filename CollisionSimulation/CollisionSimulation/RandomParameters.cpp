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
	return 0.0f;
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
