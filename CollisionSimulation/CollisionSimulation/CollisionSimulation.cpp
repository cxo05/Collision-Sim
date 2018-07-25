// CollisionSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "vhs.h"
#include "Point.h"
#include <stdio.h>
#include <gsl/gsl_integration.h>

double getFunction(double x, void *params) {
	return x;
}

int main()
{
	double a = 0., b = 100; // limits of integration
	double abserr = 0., relerr = 1.e-7; // requested errors
	double result; // the integral value
	double error; // the error estimate
	double x = 5;

	size_t np = 1000; // work area size
	gsl_integration_workspace *w = gsl_integration_workspace_alloc(np);

	gsl_function F;

	//TODO fix this
	F.function = &getFunction;
	//F.params = &x;

	gsl_integration_qag(&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15, w, &result, &error);

	printf("result = % .18f\n", result);
	printf("estimated error = % .18f\n", error);
	printf("intervals = %zu\n", w->size);

	gsl_integration_workspace_free(w);

	std::cout << result << std::endl;

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


