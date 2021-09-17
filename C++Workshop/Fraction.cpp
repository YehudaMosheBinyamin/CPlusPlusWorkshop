#include <iostream>
#include "Fraction.h"
using namespace std;


void Fraction::setMoneh(int moneh)
{
	this->moneh = moneh;
}

void Fraction::setMechane(int mechane)
{
	if (mechane == 0)
	{
		mechane = 1;
	}
	this->mechane = mechane;
}


int Fraction::getMoneh()
{
	return moneh;
}
int Fraction::getMechane()
{
	return mechane;
}


void Fraction::print()
{	
	cout << getMoneh() << "/" << getMechane()<<" ";
	minimizeFraction();
}

bool Fraction::equal(Fraction shever2)
{
	if ((float(this->moneh)/ this->mechane) != (float(shever2.moneh) / shever2.mechane))
	{
		return false;
	}	
	return true;
}

void Fraction::minimizeFraction()
{
	int divisor = 0;
	do
	{
		divisor++;
	} while ((moneh % divisor) && (mechane % divisor));
	setMoneh(moneh / divisor);
	setMechane(mechane / divisor);
}