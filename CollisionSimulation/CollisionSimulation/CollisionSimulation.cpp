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
	std::cout << "\n\n\n//////////////COLLISION DYNAMICS///////////////" << std::endl;
	//IplTester iplTester;
	CollisionDynamics col = CollisionDynamics(1,1,1);
	col.getPositiveRootW();

	//TODO add input

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


