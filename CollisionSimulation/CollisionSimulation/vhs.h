#pragma once
#include "Particle.h"
#include <vector>

class vhs
{
	std::vector <Particle*> particles;
	Particle Target;
	public:
		vhs();
		void addParticle(Particle *particle);
		void addParticles(std::vector <Particle*> particles);
		void setTarget(Particle particle);
		void run();
		bool collisionCheck(Particle * p, Particle t);
		void showfinalVelocities();
		void showParticles();
		~vhs();
};

