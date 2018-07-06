#include "stdafx.h"
#include "vhs.h"
#include <iostream>

using namespace std;

vhs::vhs(){
	cout << "Created vhs sim" << endl;
}

void vhs::addParticle(Particle *particle) {
	cout << "Added a particle" << endl;
	particles.push_back(particle);
}

void vhs::addParticles(vector <Particle*> newParticles) {
	cout << "Added particles" << endl;
	particles.insert(particles.end(), newParticles.begin(), newParticles.end());
}

void vhs::setTarget(Particle particle) {
	cout << "Added Target" << endl;
	Target = particle;
}

int vhs::run() {
	cout << "Running VHS..." << endl;
	for (vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		Vector u1 = (*it)->getinitialVelocity();
		Vector u2 = Vector(0,0);
		//TODO Change frame of reference

		//Result
		Vector v1 = Vector();
		Vector v2 = Vector();

		float angletoTarget = 0.0;

		//TODO Calculate angletoTarget
		
		//Vector perpendicular to u1
		Vector perpendicular;
		perpendicular.setXCoordinate(-(u1.getYCoordinate()));
		perpendicular.setYCoordinate(u1.getXCoordinate());

		float x;
		float y;

		//Find point of intersection between velocity vector of 1 and perpendicular line with a point that is 2's position > Z
		
		//Center of particle 1 at point of contact : Z - (sqrt(c^2-b^2))(v1/v1.norm())

		// d = d_ref (C_r,ref / C_r)^v
		// v = w - 1/2

		v1.setXCoordinate(
			u1.getXCoordinate() +
			cos(angletoTarget) * (
				cos(angletoTarget)*(u2.getXCoordinate() - u1.getXCoordinate()) +
				sin(angletoTarget)*(u1.getYCoordinate() - u2.getYCoordinate())
				)
		);

		v1.setYCoordinate(
			u1.getYCoordinate() +
			sin(angletoTarget) * (
				cos(angletoTarget)*(u1.getXCoordinate() - u2.getXCoordinate()) +
				sin(angletoTarget)*(u2.getYCoordinate() - u1.getYCoordinate())
				)
		);

		v2.setXCoordinate(
			u2.getXCoordinate() +
			cos(angletoTarget) * (
				cos(angletoTarget)*(u1.getXCoordinate() - u2.getXCoordinate()) +
				sin(angletoTarget)*(u2.getYCoordinate() - u1.getYCoordinate())
				)
		);

		v2.setYCoordinate(
			u2.getYCoordinate() +
			sin(angletoTarget) * (
				cos(angletoTarget)*(u2.getXCoordinate() - u1.getXCoordinate()) +
				sin(angletoTarget)*(u1.getYCoordinate() - u2.getYCoordinate())
				)
		);

		//Checking final velocity direction quadrants
		//if ((v1.angleToOrigin / 90) % 4 + 1 == (v2.angleToOrigin / 90) % 4 + 1) {
		//	(*it)->setfinalVelocity(&(v1-=v2));
		//}


	}
	cout << "VHS ended" << endl;
	return 1;
}

void vhs::showfinalVelocities() {
	for (vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		cout << ((*it)->getfinalVelocity()).toString() << endl;
	}
}

void vhs::showParticles() {
	for (vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		cout << "(" << (*it)->getinitialPositionX() << " , " << (*it)->getinitialPositionY() << ") Velocity: " << ((*it)->getinitialVelocity()).toString() << endl;
	}
}

vhs::~vhs(){
}
