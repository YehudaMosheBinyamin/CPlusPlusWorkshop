#include "Student.h"
#pragma once
class PHD : public Student
{/*Number of hours a PHD student conducts weekly*/
    int weeklyResearchHours;
public:
    /**
     * @brief Constructor
     * @param id
     * @param firstName
     * @param lastName
     * @param numCourses
     * @param weeklyResearchHours
    */
    PHD(int id, string firstName, string lastName, int numCourses, int weeklyResearchHours);
    /**
     * @brief Determines whether the PHD student is eligible for a grant. They are eligible only if they conduct at least 25 hours of research weekly,
        and learn at least two courses
     * @return
    */
    bool milga();
    /**
     * @brief Prints details about the PHD student
    */
    void print();
};