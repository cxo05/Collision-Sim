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

std::string Vector::toString() {
	std::stringstream ss1, ss2;
	ss1 << getMagnitude();
	float a = angleToOrigin() * (180 / 3.14159265358979323846);
	ss2 << a;
	return "(" + std::to_string(x) + "," + std::to_string(y) + ") " + "Magnitude: " + ss1.str() + " || Angle: " + ss2.str();
}

void Vector::setXCoordinate(const float newX) {
	x = newX;
}

void Vector::setYCoordinate(const float newY) {
	y = newY;
}

float Vector::dotProduct(Vector *v) {
	return this->getXCoordinate() * v->getXCoordinate() + this->getYCoordinate() * v->getYCoordinate();
}

Vector::~Vector() {
}
