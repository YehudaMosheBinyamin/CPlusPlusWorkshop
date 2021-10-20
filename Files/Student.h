#pragma once
#include<iostream>
using namespace std;
#pragma pack(1)//In order to make sure sizeof will work correctly with evaluating size of Student
class Student
{/*A static counter from 1 to allow unique id for initialization of binary file*/
    static int uniqueId;
    int studId;
    char lastName[20];
    char firstName[20];
    /*An array of boolean values for enrollment in 5 courses*/
    bool registeredToCourse[5];
public:
    /**
     * @brief Default constructor
    */
    Student();
    /**
     * @brief Parameter constructor
     * @param studId 
     * @param firstName 
     * @param lastName 
     * @param registeredToCourses 
    */
    Student(int studId, char firstName[20], char lastName[20], bool registeredToCourses[5]);
    int getStudId();
    void setStudId(int newStudId);
    char* getFirstName();
    char* getLastName();
    /**
     * @brief Get pointer to address of first element of registeredToCourse
     * @return registeredToCourse
    */
    bool* getRegisteredToCourse();
    /**
     * @brief Set courseNum to value inCourse
     * @param inCourse value of true or false to denote whether it's taken or not by student
     * @param courseNum A course number from 1 to 5
    */
    void setCourseI(bool inCourse, int courseNum);
    /**
     * @brief Prints formatted Student
     * @param s 
     * @param stud 
     * @return s
    */
    friend ostream& operator <<(ostream& s, Student& stud);
};