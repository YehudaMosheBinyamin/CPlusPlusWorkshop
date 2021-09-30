#include "Circle.h"
#include <iostream>
using namespace std;
//Yehuda Moshe Binyamin
/*
* A program that receives coordinates and radiuses for three circles.
* The program will print the area and circumference of all circles.
* Afterwards the program will receive points as an input, until the point is (0,0) 
* For each point, the program will check if it is in the circles.
* At the end the program will print out how many points out the points given are in each circle.
*/
//driver function
int main()
{
	int countTimesInside[3];
	Circle circles[3];
	float areasOfCircles[3];
	float circumferencesOfCircles[3];
	Point centerPoint;
	float centerX;
	float centerY;
	float radius;
	cout << "enter the center point and radius of 3 circles" << endl;

	/*Input circles*/
	for (int i = 0; i < 3; i++)
	{
		cin >> centerX;
		cin >> centerY;
		cin >> radius;
		centerPoint = Point(centerX, centerY);
		circles[i].setCenterPoint(centerPoint);
		circles[i].setRadius(radius);
		areasOfCircles[i]= circles[i].calculateAreaOfCircle();
		circumferencesOfCircles[i] = circles[i].circOfCircle();
	}

	char letter = 'A';//for printing A instead of 1 for circles
	char currentLetter;//for loop of printing


	/*Print areas of circles*/
	cout << "area\t";
	for (int i = 0; i < 3; i++)
	{
		currentLetter = letter + i;
		cout<<currentLetter<< ":"<< areasOfCircles[i] <<"\t";
	}
	cout << endl;
	/*Printing circumferences*/
	cout << "hekef\t";
	for (int i = 0; i < 3; i++)
	{
		currentLetter = letter + i;
		cout <<currentLetter<< ":" << circumferencesOfCircles[i] <<"\t";
	}
	cout << endl;
	float otherX=-1.0f;
	float otherY=-1.0f;
	Point otherPoint;
	for (int i = 0; i < 3; i++)
	{
		countTimesInside[i] = 0;
	}
	/*Input and check if the point is in the circle*/
	while (otherX != 0.0f || otherY != 0.0f)
	{
		cin >> otherX;
		cin >> otherY;
		if ((otherX == 0.0f)&&(otherY == 0.0f))
		{
			break;
		}
		otherPoint = Point(otherX, otherY);
		for (int i = 0; i < 3; i++)
		{
			/*If the point is on or inside a circle*/
			if ((circles[i].onCircle(otherPoint)==0) || (circles[i].onCircle(otherPoint)==-1))
			{
				countTimesInside[i]++;
			}
		}
	}
	cout << "num of points in circle\t";
	for (int i = 0; i < 3; i++)
	{
		currentLetter = letter + i;
		cout <<currentLetter << ":" << countTimesInside[i] << "\t";
	}

	return 0;
}
/*enter the center point and radius of 3 circles
0 0 3
1 1 2
5 5 2
area    A : 28.26 B : 12.56 C : 12.56
hekef   A : 18.84 B : 12.56 C : 12.56
0 1
1 0
0 4
0 0
num of points in circle A : 2     B : 2     C : 0
*/
