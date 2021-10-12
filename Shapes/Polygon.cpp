#pragma once
#include "Polygon.h"
#include <istream>
#include<ostream>
using namespace std;


Polygon::Polygon()
{
	numSides = 0;
	circumference = 0;
	sides = NULL;
}

Polygon::Polygon(int numSides)
{
	circumference = 0;
	sides = new int[numSides];
	if (numSides > 4)
	{
		cout << "enter sides for polygon:" << endl;
		for (int i = 0; i < numSides; ++i)
		{
			cin >> sides[i];
			circumference += sides[i];
		}
		this->numSides = numSides;
	}
	this->numSides = numSides;
}

	Polygon::Polygon(const Polygon& other)
	{
		numSides = other.getNumSides();
		sides = new int[numSides];
		for (int i = 0; i < numSides; ++i)
		{
			sides[i] = other.sides[i];
		}
	}


	int Polygon::getCircumference()const
	{
		return circumference;
	}

	int Polygon::getNumSides()const
	{
		return numSides;
	}

	bool Polygon::operator==(const Polygon& other)
	{
		if ((other.getCircumference() == getCircumference()) && (other.numSides == numSides))
		{
			return true;
		}
		return false;

	}
	Polygon::~Polygon() 
	{
		delete[] sides;
	}
	


	