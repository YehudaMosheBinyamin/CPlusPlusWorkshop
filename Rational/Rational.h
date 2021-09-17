#pragma once
#include <iostream>
using namespace std;
class Rational
{
private:
    int mone;
    int mechane;
public:
    //constructors
    Rational(int mone = 1,
        int mechane = 1);
    Rational(const Rational& num);
    //modify functions
    void setMone(int myMone);
    void setMechane(int myMechane);
    //view functions
    int getMone() const;
    int getMechane() const;

    //operations
    void operator*=(Rational);
    Rational operator*(Rational);
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator/(Rational);
    bool operator==(const Rational&) const;
    bool operator!=(const Rational&) const;
    Rational &operator=(const Rational&);
    Rational operator++();
    Rational operator++(int);
    Rational &operator--();
    Rational operator--(int);
    bool operator>(Rational other);
    bool operator>=(Rational);
    bool operator<(Rational other);
    bool operator<=(Rational other);
    Rational& operator+=(const Rational& num); 
    /**
     * @brief Minimize a rational number. For example:2/8 will become 1/4
    */
    void minimizeFraction();
    /**
     * @brief Prints a rational number in mone/mechane format. Will print 1 if mone is equal to it. Will only print mechane if mone is equal to 0 or 1
    */
    void print();
    /**
     * @brief Overloading the << operator, with cout-an ostream object on the left, and a rational object on the right. Effectively allows cout<<rationalObject 
     *similarly to the print function.
     * @param s ostream object
     * @param r Rational object
    */
    friend ostream& operator<<(ostream& s, Rational& r);
    /**
     * @brief Overloading the >> operator, with cin-an istream object on the left, and a rational object on the right. Effectively allows cin>>rationalObject. 
     * @param s Istream object
     * @param r Rational object
    */
    friend istream& operator>>(istream& s, Rational& r);
};
