#pragma once
#include "Vector.h"
#include "Point.h"

class Particle
{
	private: 
		float diameter; //Meter
		Vector *location; 
		Vector *initialVelocity;
		Vector *finalVelocity;

	public:
		Particle();
		Particle(float diameter, Vector *location, Vector *initVelocity);
		Vector getinitialVelocity();
		Vector getfinalVelocity();
		Vector getinitialPosition();
		float getDiameter();
		void setfinalVelocity(Vector *v);
		void setDiameter(float d);
		~Particle();
};