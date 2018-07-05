#include "stdafx.h"
#include "Particle.h"
#include <iostream>

Particle::Particle() {
	std::cout << "Created default Particle" << std::endl;
	diameter = 1;
	initialVelocity = new Vector;
}

Particle::Particle(float diameter, float initPosX, float initPosY, Vector *initVelocity){
	std::cout << "Created Particle with diameter " << diameter << std::endl;
	diameter = diameter;
	initialVelocity = initVelocity;
	initialPosX = initPosX;
	initialPosY = initPosY;
}

Vector Particle::getinitialVelocity(){
	return *initialVelocity;
}

Vector Particle::getfinalVelocity(){
	return *finalVelocity;
}

float Particle::getinitialPositionX() {
	return initialPosX;
}

float Particle::getinitialPositionY() {
	return initialPosY;
}

void Particle::setfinalVelocity(Vector *v) {
	finalVelocity = v;
}

Particle::~Particle()
{
}
