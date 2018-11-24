#pragma once
#include "Particle.h"
#include <vector>

class vhs
{
	Particle* particle;
	Particle Target;
	public:
		vhs();
		void addParams(float b, float d, float v);
		void setParticle(Particle *particle);
		void setTarget(Particle particle);
		void run();
		bool collisionCheck(Particle * p, Particle t);
		void showfinalVelocities();
		~vhs();
};

