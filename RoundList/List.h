#pragma once
#include<iostream>
using namespace std;
class List
{
public:
    class Link
    {
    public:
        /*constructor*/
        Link(int linkValue, Link* nextPtr);
        Link(const Link&);
        // data areas
        int value;
        Link* next;

    };
    /*constructors and destructor*/
    List();
    List(const List&);
    ~List();
    /**
     * @brief List will receive all elements in other
     * @param other
     * @return *this
    */
    List& operator=(const List& other);
    /**
     * @brief Returns a stream for printing the elements of the list
     * @param c_out
     * @param a
     * @return c_out
    */
    friend ostream& operator<<(ostream& c_out, List& a);
    /**
     * @brief Returns a stream for inputting values of the list
     * @param c_in
     * @param b
     * @return
    */
    friend istream& operator>>(istream& c_in, List& b);
    /**
     * @brief Adds an element to the beginning of the list
     * @param value
    */
    void add(int value);
    /**
     * @brief Inserts an element at the first index in the list that it's a larger number than all the preceding values in the list.
     * @param key
    */
    void insert(int key);
    /**
     * @brief Removes the first instance of the key in the list.
     * @param key
    */
    void remove(int key);
    /**
     * @brief Returns value at the head of the list.
     * @return
    */
    int firstElement() const;
    /**
     * @brief Returns whether the list is empty or not.
     * @return true/false
    */
    bool isEmpty() const;
    /**
     * @brief Remove the first element of the list
    */
    void removeFirst();
    /**
     * @brief Delete all elements of the list
    */
    void clear();
    /*Pointer to the head element*/
    Link* head;
};