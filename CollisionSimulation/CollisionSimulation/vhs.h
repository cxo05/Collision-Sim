#pragma once
#include "Particle.h"

using namespace std;

class vhs
{
	Particle *particles[];
	Particle Target;
	public:
		vhs(); //Initialize with particles
		bool run(); //Run vhs simulation
		~vhs();
};

