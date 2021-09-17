#include <iostream>
#include <cstdlib>
#include "Fraction.h"
using namespace std;
//328972427
/**
* A program that receives two fractionsas an input and prints whether they are equal or not.
* If they are not, they will be printed.
**/
int main() {
	Fraction shever1;
	Fraction shever2;
	int moneh;
	int mechane;
	char slash;
	cout << "enter two rational numbers" << endl;
	cin >> moneh;
	cin >> slash;
	cin >> mechane;
	shever1.setMoneh(moneh);
	shever1.setMechane(mechane);
	cin >> moneh;
	cin >> slash;
	cin >> mechane;
	shever2.setMoneh(moneh);
	shever2.setMechane(mechane);
	int equalOrDifferent = shever1.equal(shever2);
	if (equalOrDifferent == 0)
	{
		cout << "different"<<endl;
		shever1.print();
		shever2.print();	
	}
	else
	{
		cout << "equal"<<endl;
	}
	
	return 0;
}
/**
* Example inputs:
enter two rational numbers
1 / 2 3 / 6
equal 


enter two rational numbers
1/2 2/6
different 
1/2 2/6
**/