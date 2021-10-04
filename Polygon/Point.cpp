#include "Polygon.h"

Point::Point(const Point& point)
{
    x = point.x;
    y = point.y;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
/*Getters*/
double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::distance(Point other)
{
    double distanceSquared = pow((*this).getX() - other.getX(), 2) + pow((*this).getY() - other.getY(), 2);
    double distance=sqrt(distanceSquared);
    return distance;
}
