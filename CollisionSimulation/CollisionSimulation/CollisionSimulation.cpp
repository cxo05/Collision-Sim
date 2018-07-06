// CollisionSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "vhs.h"

using namespace std;

int main()
{
	cout << "Starting program" << endl;

	cout << "Testing Vector class\n\n\n" << endl;

	Vector vector = Vector(1,1);
	Vector vector2 = Vector(1,1);
	cout << (vector -= vector2).toString() << endl;


	cout << "\n\n\n" << endl;
	cout << "Testing VHS class\n\n\n" << endl;
	//TODO add input

	vhs vhs;
	
	vhs.addParticle(new Particle());
	vhs.addParticle(new Particle(10.0f, 0, 0, new Vector(2,3)));
	vhs.addParticle(new Particle(15.0f, 3, 0, new Vector(1,5)));

	vhs.setTarget(Particle(10.0f, 5, 5, new Vector(0,0)));

	vhs.showParticles();

	cout << "Program ended" << endl;
	system("pause");
    return 0;
}


