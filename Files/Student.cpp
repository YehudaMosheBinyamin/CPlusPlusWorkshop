#include "Student.h"
#include <string.h>

Student::Student()
{
    studId = uniqueId;
    strncpy_s(firstName, 20, "                   ", 20);
    strncpy_s(lastName, 20, "                   ", 20);
    for (int i = 0; i < 5; ++i)
    {
        registeredToCourse[i] = false;
    }
    uniqueId++;
}
int Student::uniqueId = 1;
Student::Student(int studId, char firstName[20], char lastName[20], bool registeredToCourses[5])
{
    this->studId = studId;
    strncpy_s(this->firstName, 20, firstName, 20);
    strncpy_s(this->lastName, 20, lastName, 20);
    for (int i = 0; i < 5; ++i)
    {
        this->registeredToCourse[i] = registeredToCourses[i];
    }
}

int Student::getStudId()
{
    return studId;
}

void Student::setStudId(int newStudId)
{
    studId = newStudId;
}

char* Student::getFirstName()
{
    return firstName;
}

char* Student::getLastName()
{
    return lastName;
}

bool* Student::getRegisteredToCourse()
{
    return registeredToCourse;
}

void Student::setCourseI(bool inCourse, int courseNum)
{
    registeredToCourse[courseNum] = inCourse;
}

ostream& operator<<(ostream& s, Student& stud)
{
    s << stud.getStudId() << endl;
    s << stud.getFirstName() << endl;
    s << stud.getLastName() << endl;
    bool* getRegisteredToCourse = stud.getRegisteredToCourse();
    for (int i = 0; i < 5; ++i)
    {
        if (getRegisteredToCourse[i] == true)
        {
            s << "Y" << endl;
        }
        else
        {
            s << "N" << endl;
        }
    }
    return s;
}
