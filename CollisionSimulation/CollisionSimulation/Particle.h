#pragma once
#include "Vector.h"

class Particle
{
	float diameter;
	Vector *initialVelocity;
	Vector *finalVelocity;

	public:
		Particle();
		Particle(float diameter, Vector *initVelocity);
		Vector getinitialVelocity();
		Vector getfinalVelocity();
		void setfinalVelocity(Vector *v);
		~Particle();
};