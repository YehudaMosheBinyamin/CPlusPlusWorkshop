#include"Rational.h"
#include<iostream>
using namespace std;
//328972427

/*A program that receives two rational numbers from user, and prints the results of various operations on them*/
int main(void)
{
	Rational rationalOne, rationalTwo;
	cout << "Enter 2 rational numbers" << endl;
	cout << "a:";
	cin >> rationalOne;
	cout << "b:";
	cin >> rationalTwo;
	Rational subtractionResult = rationalTwo-rationalOne;
	cout << "b-a: ";
	cout <<subtractionResult<<endl;
	bool notEqual = rationalOne != rationalTwo;
	cout << "a!=b: ";
	if (notEqual == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	bool smaller = rationalOne<rationalTwo;
	cout << "a<b: ";
	if (smaller == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	bool larger = rationalOne>rationalTwo;
	cout << "a>b: ";
	if (larger == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	bool largerOrEqual = rationalOne >= rationalTwo;
	cout << "a>=b: ";
	if (largerOrEqual == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	Rational preIncrement= rationalOne++;
	cout << "a++: ";
	cout << preIncrement<<endl;
	cout << "--a: ";
	Rational postDecremnt=--rationalOne;
	cout << postDecremnt << endl;
	Rational preDecrement=rationalOne--;
	cout << "a--: ";
	cout << preDecrement << endl;
	//Now rationalTwo will receive the values of rationalOne
	rationalTwo=rationalOne;
	subtractionResult = rationalTwo - rationalOne;
	cout << "b-a: ";
	cout << subtractionResult << endl;
	Rational divisionResult= rationalOne / rationalTwo;
	cout << "a/b: ";
	cout << divisionResult << endl;
	notEqual = rationalOne != rationalTwo;
	cout << "a!=b: ";
	if (notEqual == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	smaller = rationalOne < rationalTwo;
	cout << "a<b: ";
	if (smaller == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	largerOrEqual = rationalOne >= rationalTwo;
	cout << "a>=b: ";
	if (largerOrEqual == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}

/**Example Execution
Enter 2 rational numbers
a : 2 / 3
b : 3 / 4
b - a : 1 / 12
a != b : true
a<b : true
	a>b : false
	a >= b : false
	a++ : 2 / 3
	--a : 2 / 3
	a-- : 2 / 3
	b - a : 0
	a / b : 1
	a != b : false
	a < b : false
	a >= b : true**/