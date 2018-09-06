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

void vhs::run() {
	std::cout << "/////////////////VHS START/////////////////" << std::endl << std::endl;
	for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		Vector u1 = (*it)->getinitialVelocity();
		Vector u2 = Target.getinitialVelocity();

		Vector v1 = Vector();
		Vector v2 = Vector();

		//TODO Change diameter
		// d = d_ref (C_r,ref / C_r)^v
		// v = w - 1/2
		//(*it)->setDiameter(10.0f);

		Vector Targetpos = Target.getinitialPosition();
		
		float vectorProjection = Targetpos.getMagnitude() 
			* (Targetpos.dotProduct(&(*it)->getinitialVelocity()))
			/ (Targetpos.getMagnitude() * ((*it)->getinitialVelocity()).getMagnitude());

		//Direct collision
		//if (trunc(1000. * vectorProjection) == trunc(1000. * Targetpos.getMagnitude())) {
		//	std::cout << "Set to collide directly" << std::endl;
		//	//TODO Do fix direct collision
		//	v1.setXCoordinate(-(u1.getXCoordinate() + u2.getXCoordinate()) / 2);
		//	v1.setYCoordinate(-(u1.getYCoordinate() + u2.getYCoordinate()) / 2);
		//	v2.setXCoordinate((u1.getXCoordinate() + u2.getXCoordinate()) / 2);
		//	v2.setYCoordinate((u1.getYCoordinate() + u2.getYCoordinate()) / 2);
		//	(*it)->setfinalVelocity(&v1);
		//	std::cout << "Particle final velocity : " << ((*it)->getfinalVelocity()).toString() << std::endl;
		//	Target.setfinalVelocity(&v2);
		//	std::cout << "Target final velocity : " << (Target.getfinalVelocity()).toString() << std::endl;
		//	return;
		//}

		if (collisionCheck(*it, Target)) {
			float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;
			std::cout << "Distance between centers in m : " << combinedRadius << std::endl;

			float vr = ((u1.getXCoordinate() - u2.getXCoordinate()) * ((*it)->getinitialPosition().getXCoordinate() - Target.getinitialPosition().getXCoordinate()))
				+ ((u1.getYCoordinate() - u2.getYCoordinate()) * ((*it)->getinitialPosition().getYCoordinate() - Target.getinitialPosition().getYCoordinate()));
			std::cout << "vr : " << vr << std::endl;

			float impulse = (2 * vr) / combinedRadius / 1; //TODO Check Units
			std::cout << "Impulse : " << impulse << std::endl;

			float Jx = (impulse * ((*it)->getinitialPosition().getXCoordinate() - Target.getinitialPosition().getXCoordinate())) / combinedRadius;
			float Jy = (impulse * ((*it)->getinitialPosition().getYCoordinate() - Target.getinitialPosition().getYCoordinate())) / combinedRadius;
			std::cout << "Impulse X : " << Jx <<std::endl;
			std::cout << "Impulse Y : " << Jy <<std::endl;

			v1.setXCoordinate(u1.getXCoordinate() - Jx);
			v1.setYCoordinate(u1.getYCoordinate() - Jy);

			v2.setXCoordinate(u2.getXCoordinate() + Jx);
			v2.setYCoordinate(u2.getYCoordinate() + Jy);

			/*
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
	}
	particles.clear();
	std::cout << std::endl << "/////////////////VHS END/////////////////" << std::endl;
	return;
}

bool vhs::collisionCheck(Particle * p, Particle t) {
	Vector Targetpos = t.getinitialPosition();

	float vectorProjection = Targetpos.getMagnitude()
		* (Targetpos.dotProduct(&(p->getinitialVelocity())))
		/ (Targetpos.getMagnitude() * (p->getinitialVelocity()).getMagnitude());

	float DistanceToClosestPointFromTarget = sqrt(Targetpos.getMagnitude()*Targetpos.getMagnitude() - vectorProjection * vectorProjection);

	float combinedRadius = p->getDiameter() / 2 + t.getDiameter() / 2;

	if (DistanceToClosestPointFromTarget < combinedRadius) {
		std::cout << "Collision : TRUE" << std::endl;
		return true;
	} else {
		std::cout << "Collision : FALSE" << std::endl;
		return false;
	}
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
