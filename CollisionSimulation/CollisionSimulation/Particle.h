#pragma once
#include "Vector.h"

class Particle
{
	float diameter;
	Vector intialVelocity;
	Vector finalVelocity;

	public:
		Particle(float diameter, Vector initVelocity);
		Vector getinitialVelocity();
		Vector getfinalVelocity();
		void setfinalVelocity(Vector v);
		~Particle();
};