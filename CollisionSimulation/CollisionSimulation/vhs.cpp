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

int vhs::run() {
	for (vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		//*it.getinitialVelocity(); TODO Use particle velocities
		Vector u1 = Vector();
		Vector u2 = Vector();
		Vector v1 = Vector();
		Vector v2 = Vector();
		float angle;
		v1.setXCoordinate(
			u1.getXCoordinate() +
			cos(angle) * (
				cos(angle)*(u2.getXCoordinate() - u1.getXCoordinate()) +
				sin(angle)*(u1.getYCoordinate() - u2.getYCoordinate())
				)
		);

		v1.setYCoordinate(
			u1.getYCoordinate() +
			sin(angle) * (
				cos(angle)*(u1.getXCoordinate() - u2.getXCoordinate()) +
				sin(angle)*(u2.getYCoordinate() - u1.getYCoordinate())
				)
		);

		v2.setXCoordinate(
			u2.getXCoordinate() +
			cos(angle) * (
				cos(angle)*(u1.getXCoordinate() - u2.getXCoordinate()) +
				sin(angle)*(u2.getYCoordinate() - u1.getYCoordinate())
				)
		);

		v2.setYCoordinate(
			u2.getYCoordinate() +
			sin(angle) * (
				cos(angle)*(u2.getXCoordinate() - u1.getXCoordinate()) +
				sin(angle)*(u1.getYCoordinate() - u2.getYCoordinate())
				)
		);


	}
	return 1;
}

void vhs::showfinalVelocities() {
	for (vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		cout << ((*it)->getfinalVelocity()).toString() << endl;
	}
}

vhs::~vhs(){
}
