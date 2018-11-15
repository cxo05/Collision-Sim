#include "stdafx.h"
#include "vhs.h"
#include <iostream>
#include "Point.h"

vhs::vhs(){
	//Target params (diameter, location, velocity)
	Particle target(0.1f, new Vector(0,1), new Vector(0,0));
	setTarget(target);
}

void vhs::addParams(float b, float d, float v) {
	addParticle(new Particle(d, new Vector(b,0), new Vector(0,v)));
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

		
		//(*it)->setDiameter((*it)->getDiameter() * pow((u1/C_r), v));

		Vector Targetpos = Target.getinitialPosition();
		
		float vectorProjection = Targetpos.getMagnitude() 
			* (Targetpos.dotProduct(&(*it)->getinitialVelocity()))
			/ (Targetpos.getMagnitude() * ((*it)->getinitialVelocity()).getMagnitude());

		if (collisionCheck(*it, Target)) {
			float combinedRadius = (*it)->getDiameter() / 2 + Target.getDiameter() / 2;
			std::cout << "Combined Radius : " << combinedRadius << std::endl;

			//float DistanceToClosestPointFromTarget = (*it)->getinitialPosition().getXCoordinate();
			float DistanceToClosestPointFromTarget = sqrt(Targetpos.getMagnitude()*Targetpos.getMagnitude() - vectorProjection * vectorProjection);
			std::cout << "Distance to closest point from target : " << DistanceToClosestPointFromTarget << std::endl;

			float angletoTarget_atContact = acos(DistanceToClosestPointFromTarget / combinedRadius);
			std::cout << "angletoTarget_atContact : " << angletoTarget_atContact * 180 / 3.14159265 << std::endl;

			/*std::cout << "Angle of deflection of particle : " << atan(sin(angletoTarget_atContact) / (1 + cos(angletoTarget_atContact))) * 180 / 3.1415 << std::endl;
			std::cout << "Magnitude : " << u1.getMagnitude() * sqrt(2 + 2 * cos(angletoTarget_atContact)) / 2 << std::endl;
			std::cout << "Angle of deflection of target : " << (3.1415 - angletoTarget_atContact) / 2 * 180 /a 3.1415 << std::endl;
			std::cout << "Magnitude : " << u1.getMagnitude() * sin(angletoTarget_atContact/2) << std::endl;*/

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
	//TODO More cases
	if (t.getinitialVelocity().getMagnitude() == 0) {
		std::cout << "Collision : TRUE" << std::endl;
		return true;
	}

	float vectorProjection = Targetpos.getMagnitude()
		* (Targetpos.dotProduct(&(p->getinitialVelocity()))) 
		/ (Targetpos.getMagnitude() * (p->getinitialVelocity()).getMagnitude());
	std::cout << "Vector Proj : " << vectorProjection << std::endl;

	float DistanceToClosestPointFromTarget = sqrt(Targetpos.getMagnitude()*Targetpos.getMagnitude() - vectorProjection * vectorProjection);
	std::cout << "Distance to closest point from target : " << std::endl;

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
