#include "stdafx.h"
#include "Particle.h"
#include <iostream>

Particle::Particle() : diameter(1), initialVelocity(new Vector) {
	std::cout << "Created default Particle" << std::endl;
}

Particle::Particle(float diameter, float initPosX, float initPosY, Vector *initVelocity)
	: diameter(diameter), initialVelocity(initVelocity), initialPosX(initPosX), initialPosY(initPosY){
	std::cout << "Created Particle of size : " << diameter << " and position : " << initPosX << "," << initialPosY << std::endl;
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
