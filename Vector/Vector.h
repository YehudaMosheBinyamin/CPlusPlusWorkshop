#include <iostream>
using namespace std;
#pragma once
class Vector {
    int* arr=NULL;//pointer to dynamic array
    int capacity;//max possible size
    int size;//actual size
public:
    //Constructors
    Vector();
    Vector(int size);
    Vector(const Vector& other);
    //destructor
    ~Vector();
    /**
     * @brief Returns capacity
     * @return capacity
    */
    int getCapacity();
    /**
     * @brief Returns size
     * @return size
    */
    int getSize();
    /**
     * @brief Print the vector in the following format: capacity: <capacity> size: <size> val: <values>
    */
    void print();
    /**
     * @brief Assign vector to another vector. On error, the function will print error and exit with failure code.
     * @param other 
     * @return *this
    */
    Vector& operator = (const Vector &other);
    /**
     * @brief Returns whether two vectors are equal by size and by contents.
     * @param other 
     * @return true/false
    */
    bool operator == (const Vector &other);
    /**
     * @brief Returns element of array at requested index. On error, the function will print error and exit with failure code.
     * @param index 
     * @return an integer in array
    */
    int& operator [] (int index);
    /**
     * @brief Returns scalar multiplication of *this and other
     * @param other 
     * @return result of multiplication
    */
    int operator * (const Vector &other);
    /**
     * @brief Returns new vector containing the elements of this array followed by those of other array
     * @param other 
     * @return new Vector
    */
    Vector operator + (const Vector &other);
    /**
     * @brief Sets size of vector to zero.
    */
    void clear();
    /**
     * @brief Deletes last element. In case of an empty array, an error will be printed and the program will exit with -1.
    */
    void delLast();
    /**
     * @brief Inserts a value in the next empty space in the vector. If the vector is full the program weill exit with an error code.
     * @param val 
    */
    void insert(int val);
};