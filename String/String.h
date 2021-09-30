#pragma once
#include <iostream>
using namespace std;
#ifndef MAX_WORD_LENGTH  
#define MAX_WORD_LENGTH 101
#endif 
class String
{
    char string[MAX_WORD_LENGTH];
public:
    //Constructors
    String(const char* str);
    String(const String& str);
    /**
     * @brief Inserts str into string from index. If index is bigger than strlen(string) the function will print ERROR and the program will exit with an error code.
     * @param index 
     * @param str 
     * @return combinedString
    */
    String insert(int index, const char* str);
    /**
     * @brief Returns true if this string is larger lexicographically than str, else false
     * @param str 
     * @return rue/false
    */
    bool operator > (const String str);
    /**
     * @brief Returns true if this string is larger or equal lexicographically than str, else false
     * @param str
     * @return true/false
    */
    bool operator >= (const String str);
    /**
     * @brief Returns true if this string is smaller lexicographically than str, else false
     * @param str
     * @return true/false
    */
    bool operator < (const String str);
    /**
     * @brief Returns true if this string is smaller or equal lexicographically than str, else false
     * @param str
     * @return true/false
    */
    bool operator <= (const String str);
    /**
     * @brief Returns true if this string is equal lexicographically to str, else false
     * @param str
     * @return true/false
    */
    bool operator == (const String str);
    /**
     * @brief Returns true if this string is unequal lexicographically to str, else false
     * @param str
     * @return true/false
    */
    bool operator != (const String str);
    /**
    * @brief Returns a stream s of type ostream, in order to define how cout will print an object of class type String.
    * The usage is as the standard usage of cout: cout<<str when str is an instance of class String.
    * @param s
    * @param str
    * @return s
   */
    friend ostream& operator << (ostream& s, String& str);
    /**
     * @brief Returns string
     * @return string
    */
    char* getString();
};
