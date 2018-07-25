#include "stdafx.h"
#include "vhs.h"
#include <iostream>
#include "Point.h"

vhs::vhs(){
	std::cout << "Created vhs sim" << std::endl;
}

void vhs::addParticle(Particle *particle) {
	std::cout << "Added a particle" << std::endl;
	particles.push_back(particle);
}

void vhs::addParticles(std::vector <Particle*> newParticles) {
	std::cout << "Added particles" << std::endl;
	particles.insert(particles.end(), newParticles.begin(), newParticles.end());
}

void vhs::setTarget(Particle particle) {
	std::cout << "Added Target" << std::endl;
	Target = particle;
}

int vhs::run() {
	std::cout << "Running VHS..." << std::endl;
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		Vector u1 = (*it)->getinitialVelocity();
		Vector u2 = Target.getinitialVelocity();

		//TODO Change diameter
		// d = d_ref (C_r,ref / C_r)^v
		// v = w - 1/2
		//(*it)->setDiameter(10.0f);

		//Result
		Vector v1 = Vector();
		Vector v2 = Vector();

		//TODO Calculate angletoTarget
		float angletoTarget_atContact = 0.0f;

		//Vector perpendicular to u1
		Vector perpendicular;
		perpendicular.setXCoordinate(-(u1.getYCoordinate()));
		perpendicular.setYCoordinate(u1.getXCoordinate());

		Point closestPoint = (*it)->getinitialPosition() += ((Target.getinitialPosition() -= (*it)->getinitialPosition()) *= u1.getNorm());
		std::cout << closestPoint << std::endl;
		float closestPointDistance = closestPoint.getDistanceTo(Target.getinitialPosition());

		float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;
		if (closestPointDistance < combinedRadius) {
			std::cout << "Particle set to collide with target" << std::endl;

			float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;

			angletoTarget_atContact = asin(closestPointDistance/combinedRadius);
			std::cout << angletoTarget_atContact * (180 / 3.14159265358979323846) << std::endl;

			v1.setXCoordinate(
				u1.getXCoordinate() +
				cos(angletoTarget_atContact) * (
					cos(angletoTarget_atContact)*(u2.getXCoordinate() - u1.getXCoordinate()) +
					sin(angletoTarget_atContact)*(u1.getYCoordinate() - u2.getYCoordinate())
					)
			);

			v1.setYCoordinate(
				u1.getYCoordinate() +
				sin(angletoTarget_atContact) * (
					cos(angletoTarget_atContact)*(u1.getXCoordinate() - u2.getXCoordinate()) +
					sin(angletoTarget_atContact)*(u2.getYCoordinate() - u1.getYCoordinate())
					)
			);

			v2.setXCoordinate(
				u2.getXCoordinate() +
				cos(angletoTarget_atContact) * (
					cos(angletoTarget_atContact)*(u1.getXCoordinate() - u2.getXCoordinate()) +
					sin(angletoTarget_atContact)*(u2.getYCoordinate() - u1.getYCoordinate())
					)
			);

			v2.setYCoordinate(
				u2.getYCoordinate() +
				sin(angletoTarget_atContact) * (
					cos(angletoTarget_atContact)*(u2.getXCoordinate() - u1.getXCoordinate()) +
					sin(angletoTarget_atContact)*(u1.getYCoordinate() - u2.getYCoordinate())
					)
			);

			//Change frame of reference
			//Checking final velocity direction quadrants	
			/*if ((v1.angleToOrigin() / 90) % 4 + 1 == (v2.angleToOrigin / 90) % 4 + 1) {
			(*it)->setfinalVelocity(&(v1-=v2));
			}*/

			(*it)->setfinalVelocity(&v1);
			std::cout << "Particle final velocity : " << ((*it)->getfinalVelocity()).toString() << std::endl;
			Target.setfinalVelocity(&v2);
			std::cout << "Target final velocity : " << (Target.getfinalVelocity()).toString() << std::endl;
		}
		else {
			std::cout << "No collision with target" << std::endl;
		}
	}
	particles.clear();
	std::cout << "VHS ended" << std::endl;
	return 1;
}

void vhs::showfinalVelocities() {
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		std::cout << ((*it)->getfinalVelocity()).toString() << std::endl;
	}
}

void vhs::showParticles() {
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		std::cout << "Initial Position : " << (*it)->getinitialPosition() << " Velocity: " << ((*it)->getinitialVelocity()).toString() << std::endl;
	}
}

vhs::~vhs(){
}
