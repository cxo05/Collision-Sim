#include "stdafx.h"
#include "Vector.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

Vector::Vector()
	: x(0), y(0)
{}

Vector::Vector(float x, float y) 
	: x(x), y(y)
{}

float Vector::getXCoordinate() {
	return x;
}

float Vector::getYCoordinate() {
	return y;
}


float Vector::getMagnitude() {
	return sqrt((x*x) + (y*y));
}

float Vector::getNorm() {
	return (x / getMagnitude(), y / getMagnitude());
}
 
float Vector::angleToOrigin() {
	return(atan(y / x));
}

void Vector::addVector(const float x2, const float y2) {
	float angleToOrigin = cos(atan(y2 / x2));
	x += x2 * cos(angleToOrigin);
	y += y2 * sin(angleToOrigin);
}

std::string Vector::toString(){
	std::stringstream ss1, ss2;
	ss1 << getMagnitude();
	ss2 << angleToOrigin();
	std::string s1(ss1.str());
	std::string s2(ss2.str());
	return "Magnitude: " + s1 + " || Angle: " + s2;
}

void Vector::setXCoordinate(const float newX) {
	x = newX;
}

void Vector::setYCoordinate(const float newY) {
	y = newY;
}

Vector::~Vector() {
}
