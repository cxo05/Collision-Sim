#pragma once
#include "Vector.h"

class Particle
{
	float diameter;
	float initialPosX, initialPosY;
	Vector *initialVelocity;
	Vector *finalVelocity;

	public:
		Particle();
		Particle(float diameter, float initPosX, float initPosY, Vector *initVelocity);
		Vector getinitialVelocity();
		Vector getfinalVelocity();
		float getinitialPositionX();
		float getinitialPositionY();
		void setfinalVelocity(Vector *v);
		~Particle();
};