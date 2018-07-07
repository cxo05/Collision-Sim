#pragma once
#include "Vector.h"
#include "Point.h"

class Particle
{
	private: 
		float diameter;
		Point *location;
		Vector *initialVelocity;
		Vector *finalVelocity;

	public:
		Particle();
		Particle(float diameter, Point *location, Vector *initVelocity);
		Vector getinitialVelocity();
		Vector getfinalVelocity();
		Point getinitialPosition();
		float getDiameter();
		void setfinalVelocity(Vector *v);
		void setDiameter(float d);
		~Particle();
};