#include "stdafx.h"
#include "VHS.h"
#include <iostream>


VHS::VHS(double B, double D){
	b = B;
	d = D;
}

std::vector<Eigen::Vector3d> VHS::run(Eigen::Vector3d aCoord, Eigen::Vector3d bCoord, Eigen::Vector3d u1, Eigen::Vector3d u2) {
	std::vector<Eigen::Vector3d> finalVelocities;

	if (collisionCheck()) {
		//Finding relative position of 1 at contact
		Eigen::Vector3d newV = u2 - u1;
		Eigen::Vector3d temPos = (((newV).dot(bCoord - aCoord)) / (newV).dot(newV) * (newV)) + aCoord;
		Eigen::Vector3d positionAtContact = temPos - sqrt(d * d - b * b) * newV.normalized();

		//Computing final velocities
		Eigen::Vector3d normalVector = (positionAtContact - bCoord).normalized();
		Eigen::Vector3d relativeVelocity = u1 - u2;
		Eigen::Vector3d normalVelocity = (relativeVelocity.dot(normalVector))*normalVector;
		Eigen::Vector3d v1 = u1 - normalVelocity;
		Eigen::Vector3d v2 = u2 + normalVelocity;

		finalVelocities.push_back(v1);
		finalVelocities.push_back(v2);
	}
	else {
		finalVelocities.push_back(u1);
		finalVelocities.push_back(u2);
	}
	
	return finalVelocities;
}

bool VHS::collisionCheck() {
	if (b < d) {
		return true;
	}
	else {
		return false;
	}
}

double VHS::getDeflectionAngle() {
	double angle = acos(b / d) * 180 / 3.141592;
	if (std::isnan(angle)) {
		angle = 0;
	}
	return angle * 2;
}

VHS::~VHS(){
}
