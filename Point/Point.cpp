#include "Circle.h"

/**
 * @brief Constructor
 * @param x A real number
 * @param y A real number
*/
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}
/*Getters*/
float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}
