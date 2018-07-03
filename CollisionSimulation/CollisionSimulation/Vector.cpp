#include <math.h>

class Vector {
	//Positions relative to origin
	private float x, y, z;
	
	public:
	Vector(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float getXCoordinate() {
		return x;
	}

	float getYCoordinate() {
		return y;
	}

	float getZCoordinate() {
		return z;
	}

	float getMagnitude() {
		return sqrt((x*x)+(y*y)+(z*z));
	}

	float getNormal() {
		return Vector(x/getMagnitude(),y/getMagnitude(),z/getMagnitude());
	}

	static float angleToOrigin(vector v) {
		// TODO calculate angle to origin
	}
}