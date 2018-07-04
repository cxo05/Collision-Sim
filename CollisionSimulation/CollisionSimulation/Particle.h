#pragma once
#include "Vector.h"

class Particle
{
	float diameter;
	Vector intialVelocity;
	Vector finalVelocity;

	public:
	Particle(float diameter);
	Vector getinitialVelocity();
	Vector getfinalVelocity();
	~Particle();
};