#include "PHD.h"

PHD::PHD(int id, string firstName, string lastName, int numCourses, int weeklyResearchHours)
{
    this->idNumber = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->numOfCourses = numCourses;
    this->weeklyResearchHours = weeklyResearchHours;
}

bool PHD::milga()
{
    if (weeklyResearchHours > 25 && numOfCourses >= 2)
    {
        return true;
    }
    return false;
}

void PHD::print()
{
    Student::print();
    cout << "hours: " << weeklyResearchHours << endl;
}
