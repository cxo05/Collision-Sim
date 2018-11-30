#include "stdafx.h"
#include "VHS.h"
#include <iostream>


VHS::VHS(){
	
}

Eigen::Vector3d* VHS::run(double b, double d, double* aCoord, double* bCoord, double* ua, double* ub) {
	std::cout << "VHS START--->" << std::endl;

	Eigen::Vector3d finalVelocities[2];

	std::cout << "Diameter : " << d << std::endl;
	std::cout << "Miss Distance : " << b << std::endl;

	if (collisionCheck(b, d)) {
		double angletoTarget_atContact = acos(b / d);
		std::cout << "angletoTarget_atContact : " << angletoTarget_atContact * 180 / 3.14159265 << std::endl;

		Eigen::Vector3d p1(aCoord[0], aCoord[1], aCoord[2]);
		Eigen::Vector3d p2(bCoord[0], bCoord[1], bCoord[2]);
		Eigen::Vector3d u1(ua[0], ua[1], ua[2]);
		Eigen::Vector3d u2(ub[0], ub[1], ub[2]);

		Eigen::Vector3d normalVector = (p1 - p2) / (p1 - p2).norm();
		Eigen::Vector3d relativeVelocity = u1 - u2;
		Eigen::Vector3d normalVelocity = (relativeVelocity.dot(normalVector))*normalVector;
		Eigen::Vector3d v1 = u1 - normalVelocity;
		Eigen::Vector3d v2 = u2 + normalVelocity;

		finalVelocities[0] = v1;
		finalVelocities[1] = v2;
	}

	std::cout << "VHS END..." << std::endl;
	
	return finalVelocities;
}

bool VHS::collisionCheck(double b, double d) {
	if (b < d) {
		std::cout << "Collision : TRUE" << std::endl;
		return true;
	}
	else {
		std::cout << "Collision : FALSE" << std::endl;
		return false;
	}
}

VHS::~VHS(){
}
