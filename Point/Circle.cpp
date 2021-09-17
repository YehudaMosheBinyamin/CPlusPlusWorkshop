#include <iostream>
#include "Circle.h"
#include <cmath>
using namespace std;
/*Setters and Getters*/
void Circle::setCenterPoint(Point center)
{
	(*this).point= center;
}

Point Circle::getCenterPoint()
{
	return point;
}

void Circle::setRadius(float radius)
{
	this->radius = radius;
}

float Circle::getRadius()
{
	return radius;
}

/**
 * @brief Calculates the area of a circle according to the formula: area=PI*radius^2.
 * @return area
*/
float Circle::calculateAreaOfCircle()
{
	float radius = getRadius();
	float area = PI * pow(radius, 2);
	return area;
}

/**
 * @brief Calculates the circumference of a circle according to the formula: circumference=2*PI*radius.
 * @return circ
*/
float Circle::circOfCircle()
{
	float radius = getRadius();
	float circ = 2 * PI * radius;
	return circ;
}

/**
 * @brief Check if a point is out, on or in a circle.
 * @param otherPoint 
 * @return 1 if outside, 0 if on and -1 if in.
*/
int Circle::onCircle(Point otherPoint)
{
	float centerPointX = this->getCenterPoint().getX();
	float centerPointY = this->getCenterPoint().getY();
	float otherPointX = otherPoint.getX();
	float otherPointY = otherPoint.getY();
	/*Pythagorean Theorem squared distance*/
	float distanceSquared = pow(otherPointX - centerPointX, 2) + pow(otherPointY - centerPointY, 2);
	float radiusSquared = pow(getRadius(), 2);
	/*Check whether the point is inside the circle*/
	if (distanceSquared > radiusSquared)
	{
		return 1;//The point is outside the circle
	}
	if (distanceSquared == radiusSquared)
	{
		return 0;//The point is on the circle
	}
	else //The point is inside the circle
	{
		return -1;
	}
}
