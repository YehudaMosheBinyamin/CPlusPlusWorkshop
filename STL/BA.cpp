#include "BA.h"
BA::BA()
{
    this->idNumber = 0;
    this->firstName = "";
    this->lastName = "";
    this->numOfCourses = 0;
    this->grades = NULL;
    this->numGrades = 0;
}
BA::BA(int id, string firstName, string lastName, int numCourses, float* grades, int numGrades)
{
    this->idNumber = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->numOfCourses = numCourses;
    this->grades = new float[numGrades];
    for (int i = 0; i < numGrades; ++i)
    {
        this->grades[i] = grades[i];
    }
    this->numGrades = numGrades;
}

void BA::print()
{
    Student::print();
    cout << "grades: ";
    for (int i = 0; i < numGrades; ++i)
    {
        cout << grades[i] << " ";
    }
    cout << endl;
}

float BA::averageGrade()
{
    float sumGrades = 0.0f;
    for (int i = 0; i < numGrades; ++i)
    {
        sumGrades += grades[i];
    }
    float average = sumGrades / numGrades;
    return average;
}

bool BA::milga()
{

    if (numOfCourses >= 10 && averageGrade() > 95)
    {
        return true;
    }
    return false;
}

string BA::studType()
{
    string type = string("BA");
    return type;
}

BA::~BA()
{
    delete[] grades;
}
