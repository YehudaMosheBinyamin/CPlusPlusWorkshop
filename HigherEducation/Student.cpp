#include <iostream>
using namespace std;
#include <cstring>
#include "Student.h"

void Student::print()
{
    cout << "ID: " << idNumber << endl;
    cout << "first name: " << firstName << endl;
    cout << "last name:" << lastName << endl;
    cout << "num courses: " << numOfCourses << endl;
}

Student::~Student()
{
}

string Student::getFName()
{
    return firstName;
}

string Student::getLName()
{
    return lastName;
}

void Student::setFName(string newFName)
{
    firstName = newFName;
}

void Student::setLName(string newLName)
{
    lastName = newLName;
}

int Student::getNumCourses()
{
    return numberOfCourses;
}




