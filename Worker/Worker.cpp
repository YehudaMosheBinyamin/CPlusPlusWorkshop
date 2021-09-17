#include "Worker.h"
#include <iostream>
using namespace std;

void Worker::calculateSalary()
{
    (*this).totalSalary = (*this).hoursWorked * (*this).salaryPerHour + (*this).extraHours * 1.5 * (*this).salaryPerHour;
}

float Worker::getTotalSalary()
{
    return totalSalary;
}


void Worker::setIdNumber(int idNumber)
{
    (*this).idNumber = idNumber;
}

int Worker::getIdNumber()
{
    return idNumber;
}

void Worker::setName(char name[20])
{
    strcpy_s(this->name, name);
}

char* Worker::getName()
{
    return name;
}

void Worker::setSalaryPerHour(float salaryPerHour)
{
    (*this).salaryPerHour = salaryPerHour;
}

float Worker::getSalaryPerHour()
{
    return salaryPerHour;
}

void Worker::setHoursWorked(int hoursWorked)
{
    (*this).hoursWorked = hoursWorked;
}

int Worker::getHoursWorked()
{
    return hoursWorked;
}

void Worker::setExtraHours(int extraHours)
{
    (*this).extraHours = extraHours;
    calculateSalary();
}

int Worker::getExtraHours()
{
    return extraHours;
}

int Worker::getAllHours()
{
    return hoursWorked + extraHours;
}