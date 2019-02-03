#include "stdafx.h"
#include "path.h"

path::path() {
	std::ofstream positionData;
	positionData.open("positionData.csv");
	positionData << "posX_1, posY_1, posX_2, posY_2" << std::endl;
	
	double t = 0;
	recursive(0,0,1,0.25,1,0,-1,0, 1500, positionData);
}

void path::recursive(double posX_1, double posY_1, double posX_2, double posY_2, double u_1, double v_1, double u_2, double v_2, double runsLeft, std::ofstream & file) {
	runsLeft--;
	double newX_1, newY_1, newX_2, newY_2, newu_1, newv_1, newu_2, newv_2;

	double r = sqrt((posX_1 - posX_2) * (posX_1 - posX_2) + (posY_1 - posY_2) * (posY_1 - posY_2));
	double F = kappa * pow(r, -mu);
	double F_x = (posX_1 - posX_2) / r * F;
	double F_y = (posY_1 - posY_2) / r * F;
	
	newu_1 = u_1 + F_x * timeStep;
	newv_1 = v_1 + F_y * timeStep;
	newu_2 = u_2 - F_x * timeStep;
	newv_2 = v_2 - F_y * timeStep;

	newX_1 = posX_1 + newu_1 * timeStep;
	newY_1 = posY_1 + newv_1 * timeStep;
	newX_2 = posX_2 + newu_2 * timeStep;
	newY_2 = posY_2 + newv_2 * timeStep;

	file << newX_1 << "," << newY_1 << "," << newX_2 << "," << newY_2 << std::endl;
	//std::cout << "Stepped" << std::endl;
	if (runsLeft == 0) {
		return;
	}
	recursive(newX_1, newY_1, newX_2, newY_2, newu_1, newv_1, newu_2, newv_2, runsLeft, file);
}

path::~path() {
}
