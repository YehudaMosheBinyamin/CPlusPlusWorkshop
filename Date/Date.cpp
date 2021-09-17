#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    if (day < 1 || day>30)
    {
        cout << "Error day" << endl;
        day = 1;
    }
    if (month < 1 || month>12)
    {
        cout << "Error month" << endl;
        month = 1;
    }
    if (year < 1970 || year>2099)
    {
        cout << "Error year" << endl;
        year = 1970;
    }
}

Date& Date:: operator+=(int numDays) { 
    year = year + (numDays / 360);
    month = (month + numDays / 30) % 12;
    day = (day + numDays) % 360 % 30;
    return *this;
}

Date::Date(const Date& other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}
bool Date::operator > (const Date& other)const
{
    if (year > other.year)
    {
        return true;
    }
    if (year >= other.year && month > other.month)
    {
        return true;
    }
    if (year >= other.year && month >= other.month && day > other.day) {
        return true;
    }
    return false;
}
bool Date::operator <(const Date& other)const
{
    if (year < other.year)
    {
        return true;
    }
    if (year <= other.year && month < other.month)
    {
        return true;
    }
    if (year <= other.year && month <= other.month && day < other.day) {
        return true;
    }
    return false;
}
Date& Date::operator++()
{
    if (day < 30)
    {
        day++;
        return *this;
    }
    if (month < 12)
    {
        day = 1;
        month++;
        return *this;
    }
    if (year < 2099)
    {
        day = 1;
        month = 1;
        year++;
        return *this;
    }
}
Date Date::operator++(int)
{
    Date tempDate = *this;
    if (day < 30)
    {
        day++;
    }
    if (month < 12)
    {
        day = 1;
        month++;
    }
    if (year < 2099)
    {
        day = 1;
        month = 1;
        year++;
    }
    return tempDate;
}
bool Date::operator ==(const Date& other)const {
    if (year == other.year && month == other.month && day == other.day)
    {
        return true;
    }
    return false;
}
void Date::print()
{
    cout << day << "/" << month << "/" << year << endl;
}
void Date::setDate(int day, int month, int year)
{
    if (day < 1 || day>30 || month < 1 || month>12 || year < 1970 || year>2099)
    {
        return;
    }
    this->day = day;
    this->month = month;
    this->year = year;
}
