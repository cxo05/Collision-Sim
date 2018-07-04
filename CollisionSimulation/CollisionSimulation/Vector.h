#pragma once

class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector();
	Vector(float x, float y);
	float getXCoordinate();
	float getYCoordinate();
	float getMagnitude();
	float getNorm();
	float angleToOrigin();
	void addVector(const float x2, const float y2);
	~Vector();
};
