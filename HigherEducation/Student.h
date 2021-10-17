#pragma once
#include<iostream>
using namespace std;
#include <string>
class Student
{
protected:
    int idNumber;
    string firstName;
    string lastName;
    int numOfCourses;
public:
    virtual bool milga() = 0;
    virtual void print();
    virtual ~Student();
    virtual string studType() = 0;
    string getFName();
    string getLName();
    void setFName(string newFName);
    void setLName(string newLName);
    int getNumCourses();  
};





