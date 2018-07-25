#include "stdafx.h"
#include "Particle.h"
#include <iostream>

Particle::Particle() : diameter(1), initialVelocity(new Vector) {
	std::cout << "Created default Particle" << std::endl;
}

Particle::Particle(float diameter, Vector *location, Vector *initVelocity)
	: diameter(diameter), initialVelocity(initVelocity), location(location){
	std::cout << "Created Particle " << std::endl;
	std::cout << "Size : " << diameter << " || Position : " << (*location).getXCoordinate() << "," << (*location).getYCoordinate() << " || Initial Velocity :" << initialVelocity->toString() << std::endl;
}

Vector Particle::getinitialVelocity(){
	return *initialVelocity;
}

Vector Particle::getfinalVelocity(){
	return *finalVelocity;
}

Vector Particle::getinitialPosition() {
	return *location;
}

float Particle::getDiameter() {
	return diameter;
}

void Particle::setfinalVelocity(Vector *v) {
	finalVelocity = v;
}

void Particle::setDiameter(float d) {
	diameter = d;
}

Particle::~Particle()
{
}
