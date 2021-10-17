#include "Student.h"
#pragma once
/**
 * @brief A class to represent a student studying pursuing a bachelor degree.
*/
class BA : public Student
{	/*Grades of the student*/
    float* grades;
    int numGrades;
public:
    /**
     * @brief Constructor
     * @param id
     * @param firstName
     * @param lastName
     * @param numCourses
     * @param grades
     * @param numGrades
    */
    BA();
    BA(int id, string firstName, string lastName, int numCourses, float* grades, int numGrades);
    /**
     * @brief Prints information about the student
    */
    void print();
    /**
     * @brief Calculates the student's average grade.
     * @return average
    */
    float averageGrade();
    /**
     * @brief Determines whether the student is eligible for a grant.
     * They will be eligible if they are doing at least 10 courses, and their average is above 95
     * @return true/false
    */
    bool milga();
    string studType();
    ~BA();
};