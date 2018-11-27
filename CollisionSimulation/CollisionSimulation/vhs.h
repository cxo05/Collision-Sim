#pragma once
#include "Particle.h"
#include <vector>

class vhs
{
	Particle* particle;
	Particle Target;
	double cr_ref;
	public:
		vhs();
		void addParams(float b, float d, float v, double cr_ref);
		void setParticle(Particle *particle);
		void setTarget(Particle particle);
		void run();
		bool collisionCheck(Particle * p, Particle t);
		void showfinalVelocities();
		~vhs();
};

