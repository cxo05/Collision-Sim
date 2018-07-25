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
#include "IplTester.h"


int main()
{
	IplTester iplTester;

	//TODO add input

	std::cout << "VHS start" << std::endl << std::endl << std::endl;

	vhs vhs;
	
	//TODO Check vhs angles and add detection for particles on same path

	/*for (float i = 0; i < 2; i+= 0.1) {
		vhs.setTarget(Particle(1.0f, new Point(2, 5), new Vector(0, 0)));
		vhs.addParticle(new Particle(1.0f, new Point(0, 0), new Vector(2-i, 5)));
		vhs.run();
	}*/

	vhs.setTarget(Particle(1.0f, new Point(2, 5), new Vector(0, 0)));
	vhs.addParticle(new Particle(1.0f, new Point(0, 0), new Vector(2, 5)));
	vhs.run();

	std::cout << "\n\n\nProgram ended" << std::endl;
	system("pause");
    return 0;
}


