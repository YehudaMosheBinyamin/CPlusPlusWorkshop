#pragma once
#include <cmath>
/**
 * @brief Class to represent a 2d point
*/
class Point
{
	double x;
	double y;
public:
	//Constructors
	Point() :x(0.0f), y(0.0f) {};
	Point(const Point& point);
	Point(double x, double y);
	//Getters
	double getX();
	double getY();
	/**
	 * @brief Calculate euclidean distance between *this and other.
	 * @param other 
	 * @return distance
	*/
	double distance(Point other);
};
/**
 * @brief A class to represent a polygon of any length in a 2d space.
*/
class Polygon
{
	Point* points=NULL;//Array of points
	int numberPoints;
public:
	//Constructors and destructor
	Polygon(int numberOfPoints, Point*& points);
	Polygon(const Polygon& other);
	~Polygon();
	/**
	 * @brief Returns number of points
	 * @return numberPoints
	*/
	int getNumberPoints();
	/**
	 * @brief Returns circumference of the polygon, rounded to the closest decimal value.
	 * @return circumference
	*/
	int circumference();
};