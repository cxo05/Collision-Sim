#pragma once

class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector(float x, float y, float z);
	float getXCoordinate();
	float getYCoordinate();
	float getZCoordinate();
	float getMagnitude();
	float getNorm();
	float angleToOrigin();
	~Vector();
};
