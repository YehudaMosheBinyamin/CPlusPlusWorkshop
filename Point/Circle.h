#pragma once
#define PI 3.14f
class Point 
{
	float x;
	float y;	
public:
	Point() :x(0.0f), y(0.0f) {};
	Point(float x, float y);
	float getX();
	float getY();
};
class Circle
{private:
	Point point;
	float radius;
public:
	Circle():radius(0.0f) {}
	void setCenterPoint(Point center);
	Point getCenterPoint();
	void setRadius(float radius);
	float getRadius();
	float calculateAreaOfCircle();
	float circOfCircle();
	int onCircle(Point otherPoint);
};
