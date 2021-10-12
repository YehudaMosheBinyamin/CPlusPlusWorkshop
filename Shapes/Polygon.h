#pragma once
#include <iostream>
using namespace std;
/**
 * @brief A class to represent a 2d polygon
*/
class Polygon
{
private:
    int numSides;
protected:
    int* sides;
    int circumference;
public:
    /*Constructors and destructor*/
    Polygon();
    Polygon(int numSides);
    Polygon(const Polygon& other);
    Polygon(Polygon& a);
    ~Polygon();
    /**
     * @brief A function to return circumference field.
     * @return circumference
    */
    int getCircumference() const;
    /**
     * @brief Returns number of edges of the polygon
     * @return
    */
    int getNumSides() const;
    /**
     * @brief Returns equal if *this and other have the same amount of edges, and have equal circumference.
     * @param a
     * @return true/false
    */
    bool operator==(const Polygon& a);
};

