#pragma once
#include "Polygon.h"
/**
 * @brief A class to represent a triangle
*/
class Triangle :public Polygon
{
public:
	/*Constructors*/
	Triangle():Polygon() {}
	Triangle(int a, int b, int c);
};