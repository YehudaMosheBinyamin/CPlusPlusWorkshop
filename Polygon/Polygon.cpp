#include "Polygon.h"
Polygon::Polygon(int numberOfPoints,Point*& points)
{
    if (this->points)
    {
        delete[] this->points;
    }
    numberPoints = numberOfPoints;
    this->points = new Point[numberPoints];
    for (int i = 0; i < numberPoints; ++i)
    {
        this->points[i] = points[i];
    }
}

Polygon::Polygon(const Polygon& other)
{
    if (points)
    {
        delete[] points;
    }
    numberPoints = other.numberPoints;
    points = new Point[numberPoints];
    for (int i = 0; i < numberPoints; ++i)
    {
        points[i] = other.points[i];
    }
}

int Polygon::getNumberPoints()
{
    return numberPoints;
}

Polygon::~Polygon()
{
    if (points)
    {
        delete[] points;
    }
}

int Polygon::circumference()
{
    double circumference = 0.0;
    for (int i = 0; i < numberPoints-1; ++i)
    {
        circumference += points[i].distance(points[i + 1]);
    }
    //Finally,add distance from last point to first point
    circumference += points[numberPoints-1].distance(points[0]);
    return int(round(circumference));
}


