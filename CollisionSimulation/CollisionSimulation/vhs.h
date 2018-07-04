#pragma once
#include "Particle.h"
#include <vector>

class vhs{
	std::vector <Particle> particles;
	Particle Target;
	public:
		vhs(); //Initialize with particles
		int run(); //Run vhs simulation
		~vhs();
};

