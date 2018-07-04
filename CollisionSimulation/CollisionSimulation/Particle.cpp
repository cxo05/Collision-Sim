#include "stdafx.h"
#include "Particle.h"
#include <iostream>

Particle::Particle(float diameter)
{
	std::cout << "Created Particle with diameter " << diameter << std::endl;
	diameter = diameter;
}

Vector Particle::getinitialVelocity()
{
	return intialVelocity;
}

Vector Particle::getfinalVelocity()
{
	return finalVelocity;
}


Particle::~Particle()
{
}
