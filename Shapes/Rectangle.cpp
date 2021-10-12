#include "Rectangle.h"
Rectangle::Rectangle() :Polygon(){}
Rectangle::Rectangle(int a, int b):Polygon(4)
{
	sides[0] =a;
	sides[1]=b;
	sides[2]=a;
	sides[3] =b;
	circumference = 2 * a+ 2 * b;
}


