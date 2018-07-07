#pragma once
#include <iostream>

class Point {
private: 
	float x, y;
	friend std::ostream& operator<<(std::ostream&, const Point&);

public:
	Point();
	Point(float x, float y);
	float getX();
	float getY();
	float getDistanceTo(Point p);
	Point& operator+=(const Point& p);
	Point& operator-=(const Point& p);
	Point& operator*=(const float f);
	~Point();
};

