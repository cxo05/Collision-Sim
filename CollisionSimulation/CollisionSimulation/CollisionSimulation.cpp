// CollisionSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "vhs.h"
#include "Point.h"

int main()
{
	std::cout << "Starting program" << std::endl;
	std::cout << "Testing VHS class\n\n\n" << std::endl;

	//TODO add input


	vhs vhs;
	
	vhs.addParticle(new Particle(1.0f, new Point(0,0), new Vector(2,0)));

	vhs.addParticle(new Particle(1.0f, new Point(10,10), new Vector(2,0)));
	
	vhs.setTarget(Particle(10.0f, new Point(0,5), new Vector(0,0)));

	vhs.run();

	//vhs.showParticles();

	std::cout << "\n\n\nProgram ended" << std::endl;
	system("pause");
    return 0;
}


