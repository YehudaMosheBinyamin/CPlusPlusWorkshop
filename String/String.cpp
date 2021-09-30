#include "String.h"
using namespace std;
String::String(const char* str)
{
    size_t strLen = strlen(str);
    strcpy_s(string,MAX_WORD_LENGTH-2,str);
    string[strLen] = '\0';
}
String::String(const String& str)
{
    size_t strLen = strlen(str.string);
    strcpy_s(string, MAX_WORD_LENGTH - 2, str.string);
    string[strLen] = '\0';
}
String String::insert(int index, const char* str)
{
    size_t thisStringLength = strlen(this->string);
    size_t otherStringLength = strlen(str);
    if (index > thisStringLength)
    {
        cout << "ERROR";
        exit(-1);
    }
    int newSize = thisStringLength + otherStringLength + 1;
    char* combinedChar = new char[newSize];
    //Insert indices of this string in combined string as long as indices are before index
    size_t thisUntilIndex = 0;
    for (; thisUntilIndex < index; thisUntilIndex++)
    {
        combinedChar[thisUntilIndex] = string[thisUntilIndex];
    }
    size_t indexToStartFrom=thisUntilIndex;//The index from where to start continuing the inserting of the first element. 
    //into the new string after inserting the second element and to start putting in second element.

    //Now put second word in new combined word, from requested index onwards.
    for (size_t secondStringIndex= 0; secondStringIndex<otherStringLength;secondStringIndex++)
    {
        combinedChar[indexToStartFrom + secondStringIndex] = str[secondStringIndex];
        //cout << combinedChar[indexToStartFrom + secondStringIndex] << endl;
    }
    //Now put the rest of the letters of the original string into new string
    int afterSecondWord =indexToStartFrom+otherStringLength;//The index in new string to put the letters from first word in from there onwards.
    int restThisIndex = 0;//Index in the part of this string which hasn't yet been inserted into new string
    for (;restThisIndex<thisStringLength;restThisIndex++)
    {    
        combinedChar[afterSecondWord+restThisIndex] = string[indexToStartFrom+restThisIndex];
        //cout << combinedChar[afterSecondWord + indexToStartFrom] << endl;
     }
    combinedChar[newSize-1] = '\0';//Add null byte at the end.
    String newCombinedString = String(combinedChar);
    return newCombinedString;
}
bool String::operator>(const String str)
{
    int comparisonValue = strcmp(this->string, str.string);
    if (comparisonValue > 0)
    {
        return true;
    }
    return false;
}

bool String::operator>=(const String str)
{
    if (this->string < str.string)
    {
        return false;
    }
    return true;
}

bool String::operator<(const String str)
{
    int comparisonValue = strcmp(this->string, str.string);
    if (comparisonValue < 0)
    {
        return true;
    }
    return false;
}

bool String::operator<=(const String str)
{
    if (this->string > str.string)
    {
        return false;
    }
    return true;
}

bool String::operator==(const String str)
{
    int comparisonValue = strcmp(this->string, str.string);
    if (comparisonValue == 0)
    {
        return true;
    }
    return false;
}

bool String::operator!=(const String str)
{
    if (this->string == str.string)
    {
        return false;
    }
    return true;
    
}

char* String::getString()
{
    return string;
}

ostream& operator<<(ostream& s,String& str)
{
    s << str.getString();
    return s;
}
