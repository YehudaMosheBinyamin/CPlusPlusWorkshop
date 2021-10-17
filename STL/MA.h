#include "BA.h"
#pragma once
/*A class to represent a student for a Masters' degree*/
class MA : public BA
{/*Field to signify whether the student conducts research*/
    bool inResearch;
public:
    MA();
    /**
     * @brief Constructor
     * @param id
     * @param firstName
     * @param lastName
     * @param numCourses
     * @param grades
     * @param numGrades
     * @param inResearch
    */
    MA(int id, string firstName, string lastName, int numCourses, float* grades, int numGrades, bool inResearch);
    /**
     * Determines whether the MA student is eligible for a grant.
     * They will be eligible if they are doing at least 7 courses, their average is above 90 and they conduct research.
     * @return true/false
    */
    bool milga();
    /**
     * @brief Prints details about the MA student
    */
    void print();
    string studType();
    bool getInResearch();
};