#include "Vector.h"
#include "math.h"
using namespace std;

Vector :: Vector(float x, float y, float z) 
	: x(x), y(y), z(z)
{}

float Vector :: getXCoordinate() {
	return x;
}

float Vector :: getYCoordinate() {
	return y;
}

float Vector :: getZCoordinate() {
	return z;
}

float Vector :: getMagnitude() {
	return sqrt((x*x) + (y*y) + (z*z));
}

float Vector :: getNorm() {
	return (x / getMagnitude(), y / getMagnitude(), z / getMagnitude());
}
 
float Vector :: angleToOrigin() {
	return(atan(y / x));
}
Vector::~Vector(){
}
