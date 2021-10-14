#include "MA.h"

MA::MA(int id, string firstName, string lastName, int numCourses, float* grades, int numGrades, bool inResearch) :
    BA(id, firstName, lastName, numCourses, grades, numGrades)
{
    this->inResearch = inResearch;
}

bool MA::milga()
{
    if ((averageGrade() > 90) && (numOfCourses >= 7) && (inResearch == true))
    {
        return true;
    }
    return false;
}

void MA::print()
{
    BA::print();
    cout << "research: ";
    if (inResearch == true)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

