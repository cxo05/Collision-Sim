#pragma once
#include "math.h"
#include <fstream>
#include <iostream>

class path {
public:
	double kappa = 1;
	double mu = 2.117e-5;
	double timeStep = 0.001;
	path();
	void recursive(double posX_1, double posY_1, double posX_2, double posY_2, double u_1, double v_1, double u_2, double v_2, double runsLeft, std::ofstream & file);
	~path();
};

