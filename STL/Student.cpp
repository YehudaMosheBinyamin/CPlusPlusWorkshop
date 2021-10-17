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

string Student::getFname()
{
    return firstName;
}

string Student::getLname()
{
    return lastName;
}

void Student::setFname(string newFName)
{
    firstName = newFName;
}

void Student::setLname(string newLName)
{
    lastName = newLName;
}

int Student::getNumCourses()
{
    return numOfCourses;
}




