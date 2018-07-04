#pragma once

#include <string>

class Vector
{
private:
	float x;
	float y;

public:
	Vector();
	Vector(float x, float y);
	float getXCoordinate();
	float getYCoordinate();
	float getMagnitude();
	float getNorm();
	float angleToOrigin();
	void setXCoordinate(const float newX);
	void setYCoordinate(const float newY);
	void addVector(const float x2, const float y2);
	std::string toString();
	~Vector();
};
