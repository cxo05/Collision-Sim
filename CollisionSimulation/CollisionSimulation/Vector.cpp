#include "Vector.h"
#include "math.h"
using namespace std;

Vector :: Vector()
	: x(0), y(0)
{}

Vector :: Vector(float x, float y) 
	: x(x), y(y)
{}

float Vector :: getXCoordinate() {
	return x;
}

float Vector :: getYCoordinate() {
	return y;
}


float Vector :: getMagnitude() {
	return sqrt((x*x) + (y*y));
}

float Vector :: getNorm() {
	return (x / getMagnitude(), y / getMagnitude());
}
 
float Vector :: angleToOrigin() {
	return(atan(y / x));
}

void Vector::addVector(const float x2, const float y2) {
	float angleToOrigin = cos(atan(y2 / x2));
	x += x2 * cos(angleToOrigin);
	y += y2 * sin(angleToOrigin);
}

Vector::~Vector() {
}
