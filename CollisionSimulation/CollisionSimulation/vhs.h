#pragma once
#include "Particle.h"
#include <vector>

class vhs
{
	double b;
	double d;

	public:
		vhs(double b, double d, double* v1);
		void run(double u1, double u2);
		bool collisionCheck(double b, double d);
		~vhs();
};

