#include "stdafx.h"
#include "vhs.h"
#include <iostream>
#include "Point.h"

vhs::vhs(){
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
	std::cout << "/////////////////VHS START/////////////////" << std::endl;
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
		
		//Via Vector Projection of target position vector on u1 
		
		//TODO Change position to position vector;

		Vector Targetpos = Target.getinitialPosition();
		
		float vectorProjection = Targetpos.getMagnitude() 
			* (Targetpos.dotProduct(&(*it)->getinitialVelocity()))
			/ (Targetpos.getMagnitude() * ((*it)->getinitialVelocity()).getMagnitude());

		if (trunc(1000. * vectorProjection) == trunc(1000. * Targetpos.getMagnitude())) {
			std::cout << "Set to collide directly" << std::endl;
			//TODO Do fix direct collision
			v1.setXCoordinate(-(u1.getXCoordinate() + u2.getXCoordinate()) / 2);
			v1.setYCoordinate(-(u1.getYCoordinate() + u2.getYCoordinate()) / 2);
			v2.setXCoordinate((u1.getXCoordinate() + u2.getXCoordinate()) / 2);
			v2.setYCoordinate((u1.getYCoordinate() + u2.getYCoordinate()) / 2);
			(*it)->setfinalVelocity(&v1);
			std::cout << "Particle final velocity : " << ((*it)->getfinalVelocity()).toString() << std::endl;
			Target.setfinalVelocity(&v2);
			std::cout << "Target final velocity : " << (Target.getfinalVelocity()).toString() << std::endl;
			//std::cout << "Testing cos : " << asin()
			return 1;
		}

		float DistanceToClosestPointFromTarget = sqrt(Targetpos.getMagnitude()*Targetpos.getMagnitude() - vectorProjection*vectorProjection);
		
		float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;

		if (DistanceToClosestPointFromTarget < combinedRadius) {
			std::cout << "Particle set to collide with target" << std::endl;

			float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;

			angletoTarget_atContact = asin(DistanceToClosestPointFromTarget/combinedRadius);
			std::cout << "Angle to target at contact : " << angletoTarget_atContact*180/3.14 << std::endl;
			std::cout << "Closest distance : " << DistanceToClosestPointFromTarget << std::endl;

			//TOOD angletoTarget_atContact


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
	std::cout << "/////////////////VHS END/////////////////" << std::endl;
	return 1;
}

void vhs::showfinalVelocities() {
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		std::cout << ((*it)->getfinalVelocity()).toString() << std::endl;
	}
}

void vhs::showParticles() {
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		std::cout << "Initial Position : " << (*it)->getinitialPosition().getXCoordinate() << "," << (*it)->getinitialPosition().getYCoordinate() << " Velocity: " << ((*it)->getinitialVelocity()).toString() << std::endl;
	}
}

vhs::~vhs(){
}
