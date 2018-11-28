#include "stdafx.h"
#include "vhs.h"
#include <iostream>
#include "Point.h"

vhs::vhs(double b, double d, double* v){
	std::cout << "VHS START--->" << std::endl;
	this->b = b;
	this->d = d;
	run(v[0], v[1]); // x and y
	//run(v[0], v[2]);
	std::cout << "VHS END..." << std::endl;
}

void vhs::run(double u1x, double u1y) {
	Vector u1 = Vector(u1x, u1y);
	Vector u2 = Vector(0,0);

	Vector v1 = Vector();
	Vector v2 = Vector();

	/*float vectorProjection = Targetpos.getMagnitude()
		* (Targetpos.dotProduct(&particle->getinitialVelocity()))
		/ (Targetpos.getMagnitude() * (particle->getinitialVelocity()).getMagnitude());*/

	if (collisionCheck(this->b , this->d)) {
		std::cout << "Combined Radius : " << this->d << std::endl;

		std::cout << "Distance to closest point from target : " << this->b << std::endl;

		float angletoTarget_atContact = acos(this->b / this->d);
		std::cout << "angletoTarget_atContact : " << angletoTarget_atContact * 180 / 3.14159265 << std::endl;

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

		std::cout << "Particle final velocity : " << v1.toString() << std::endl;
		std::cout << "Target final velocity : " << v2.toString() << std::endl;
	}
	return;
}

bool vhs::collisionCheck(double b, double d) {
	if (b < d) {
		std::cout << "Collision : TRUE" << std::endl;
		return true;
	}
	else {
		std::cout << "Collision : FALSE" << std::endl;
		return false;
	}
}

/*bool vhs::collisionCheck(Particle * p, Particle t) {
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
}*/

vhs::~vhs(){
}
