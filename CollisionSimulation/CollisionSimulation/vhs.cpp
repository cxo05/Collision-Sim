#include "stdafx.h"
#include "VHS.h"
#include <iostream>


VHS::VHS(){
}

std::vector<Eigen::Vector3d> VHS::run(double b, double d, double* aCoord, double* bCoord, double* ua, double* ub) {
	std::cout << "VHS START--->" << std::endl;

	std::vector<Eigen::Vector3d> finalVelocities;

	std::cout << "Diameter : " << d << std::endl;
	std::cout << "Miss Distance : " << b << std::endl;

	if (collisionCheck(b, d)) {
		//Initialize vectors
		Eigen::Vector3d ip1(aCoord[0], aCoord[1], aCoord[2]);
		Eigen::Vector3d ip2(bCoord[0], bCoord[1], bCoord[2]);
		Eigen::Vector3d u1(ua[0], ua[1], ua[2]);
		Eigen::Vector3d u2(ub[0], ub[1], ub[2]);

		//Finding relative position of 1 at contact
		Eigen::Vector3d newV = u2 - u1;
		Eigen::Vector3d temPos;
		temPos = (((newV).dot(ip2 - ip1)) / (newV).dot(newV) * (newV)) + ip1;
		Eigen::Vector3d positionAtContact = temPos - sqrt(d * d - b * b) * newV.normalized();

		//Computing final velocities
		Eigen::Vector3d normalVector = (positionAtContact - ip2) / (positionAtContact - ip2).norm();
		Eigen::Vector3d relativeVelocity = u1 - u2;
		Eigen::Vector3d normalVelocity = (relativeVelocity.dot(normalVector))*normalVector;
		Eigen::Vector3d v1 = u1 - normalVelocity;
		Eigen::Vector3d v2 = u2 + normalVelocity;

		finalVelocities.push_back(v1);
		finalVelocities.push_back(v2);
	}
	else {
		finalVelocities.push_back(Eigen::Vector3d(0,0,0));
		finalVelocities.push_back(Eigen::Vector3d(0,0,0));
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
