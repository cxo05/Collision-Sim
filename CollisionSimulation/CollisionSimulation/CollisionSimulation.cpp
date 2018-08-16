// CollisionSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "vhs.h"
#include "Point.h"
#include "Ipl.h"
#include <stdio.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_errno.h>
#include "CollisionDynamics.h"

int main()
{
	/*
	Starting of collision dynamics (finding deflection angle) testing 
	Change function parameters here: 
	miss-distance impact parameter : b, 
	mass : m,
	molecular velocity vector : c,
	constant kappa : k,
	exponent eta : n
	*/
	CollisionDynamics collDy(0.5, 2, 2, 1, 5);

	vhs vhs;
	
	//TODO Check vhs angles and add detection for particles on same path

	vhs.setTarget(Particle(1.0f, new Vector(2, 5), new Vector(0, 0)));
	vhs.addParticle(new Particle(1.0f, new Vector(0, 0), new Vector(3.8, 10)));
	vhs.run();

	vhs.setTarget(Particle(1.0f, new Vector(2, 5), new Vector(0, 0)));
	vhs.addParticle(new Particle(1.0f, new Vector(0, 0), new Vector(2, 5)));
	vhs.run();

	std::cout << "\n\n\n//////////////PROGRAM END///////////////" << std::endl;
	system("pause");
    return 0;
}


