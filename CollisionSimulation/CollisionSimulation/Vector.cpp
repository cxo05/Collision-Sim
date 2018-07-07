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

Vector& Vector::operator+=(const Vector& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vector& Vector::operator-=(const Vector &v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

//std::ostream & operator<<(std::ostream &, Vector &v) {
//	return std::cout << "Magnitude: " << v.getMagnitude() << " || Angle (radians): " << v.angleToOrigin() << ")";
//}

std::string Vector::toString() {
	std::stringstream ss1, ss2;
	ss1 << getMagnitude();
	float a = angleToOrigin() * (180 / 3.14);
	ss2 << a;
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
