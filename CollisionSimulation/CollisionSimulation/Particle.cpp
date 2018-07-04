#include "stdafx.h"
#include "Particle.h"
#include <iostream>

Particle::Particle() {
	std::cout << "Created default Particle" << std::endl;
	diameter = 1;
	initialVelocity = ;
}

Particle::Particle(float diameter, Vector initVelocity){
	std::cout << "Created Particle with diameter " << diameter << std::endl;
	diameter = diameter;
	initialVelocity = initVelocity;
}

Vector Particle::getinitialVelocity(){
	return intialVelocity;
}

Vector Particle::getfinalVelocity(){
	return finalVelocity;
}

void Particle::setfinalVelocity(Vector v) {
	finalVelocity = v;
}

Particle::~Particle()
{
}
