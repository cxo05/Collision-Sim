#pragma once
#include "Particle.h"
#include <vector>

class vhs
{
	std::vector <Particle*> particles;
	Particle Target;
	public:
		vhs(); //Initialize with particles
		void addParticle(Particle *particle);
		void addParticles(std::vector <Particle*> particles);
		int run(); //Run vhs simulation
		void showfinalVelocities();
		~vhs();
};

