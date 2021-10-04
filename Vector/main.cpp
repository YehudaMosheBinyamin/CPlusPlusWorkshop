#include "Vector.h"
/**
 * @brief Options for different operations in main
 * stop-Exit program
 * assignment-Assign vector one to vector three
 * isEqual-check if vector one is equal to vector two
 * mult-multiply vectors one and two
 * add-add vectors one and two and assign the value to vector three
 * clear-set vector one to be empty
 * delLast-remove last element of vector two
*/
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast
	//0	    1:=	       2:==	    3:*  4:+  5      6  
};
/**
* Yehuda Moshe Binyamin
* The driver function was supplied by a lecturer.
* @brief Receives a number corresponding to the menu elements in "options" enum, and performs that operation.
* @return 
*/
int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val;
	cout << "enter your choice 0-6\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3 = v1;
			break;
		case isEqual:	if (v1 == v2) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:		cout << "v1*v2=" << v1 * v2 << endl;
			break;
		case add:
			v3 = v1 + v2;
			break;
		case clear:		v1.clear();
			break;
		case delLast:	v2.delLast();
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-6\n";
		cin >> choice;
	}
	return 0;
}


/**Sample Execution:
enter your choice 0 - 6
1
capacity: 10 size : 4 val : 1 2 3 4
capacity : 10 size : 4 val : 5 6 7 8
capacity : 10 size : 4 val : 1 2 3 4
enter your choice 0 - 6
2
v1 != v2
capacity : 10 size : 4 val : 1 2 3 4
capacity : 10 size : 4 val : 5 6 7 8
capacity : 10 size : 4 val : 1 2 3 4
enter your choice 0 - 6
3
v1 * v2 = 70
capacity : 10 size : 4 val : 1 2 3 4
capacity : 10 size : 4 val : 5 6 7 8
capacity : 10 size : 4 val : 1 2 3 4
enter your choice 0 - 6
4
capacity : 10 size : 4 val : 1 2 3 4
capacity : 10 size : 4 val : 5 6 7 8
capacity : 8 size : 8 val : 1 2 3 4 5 6 7 8
enter your choice 0 - 6
5
capacity : 10 size : 0 val :
capacity : 10 size : 4 val : 5 6 7 8
capacity : 8 size : 8 val : 1 2 3 4 5 6 7 8
enter your choice 0 - 6
6
capacity : 10 size : 0 val :
capacity : 10 size : 3 val : 5 6 7
capacity : 8 size : 8 val : 1 2 3 4 5 6 7 8
enter your choice 0 - 6
0
**/
