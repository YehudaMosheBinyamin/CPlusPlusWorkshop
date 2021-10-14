#include <iostream>
using namespace std;
#include "Student.h"
#include <cstring>




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




