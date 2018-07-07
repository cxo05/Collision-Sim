#include "stdafx.h"
#include "Point.h"
#include <iostream>


Point::Point() : x(0),y(0){
}

Point::Point(float x, float y) : x(x),y(y) {
}

float Point::getX() {
	return x;
}

float Point::getY() {
	return y;
}

float Point::getDistanceTo(Point p) {
	float xd = x - p.x;
	float yd = y - p.y;
	return sqrt(xd*xd + yd*yd);
}

Point & Point::operator+=(const Point & p) {
	x += p.x;
	y += p.y;
	return *this;
}

Point & Point::operator-=(const Point & p) {
	x -= p.x;
	y -= p.y;
	return *this;
}

Point & Point::operator*=(const float f) {
	x *= f;
	y *= f;
	return *this;
}

Point::~Point() {
}

std::ostream & operator<<(std::ostream &, const Point &p) {
	return std::cout << "(" << p.x << "," << p.y << ")";
}
