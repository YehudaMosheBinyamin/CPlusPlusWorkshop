#include <iostream>
using namespace std;
#include "Polygon.h"
/**
 * Yehuda Moshe Binyamin
 * @brief Driver function that receives requested number of points of a polygon, and then values of the points. 
 * The program will calcualte and print the circumference of the polygon
 * @param  
 * @return 
*/
int main(void)
{   double* numbersForPoints = NULL;
    int numPoints = 0;
    cout << "Please enter number of points in the for inclusion in a polygon, then the points themselves" << endl;
    cin >> numPoints;
    int numNumForPoints = numPoints * 2;
    numbersForPoints = new double[numPoints*2];
    for (int i = 0; i < numNumForPoints; ++i)
    {
        cin >> numbersForPoints[i];
    }
    Point* points = new Point[numPoints];
    int indexOfNumbersForPoints = 0;
    for (int i = 0; i < numPoints;++i)
    {
        points[i] = Point(numbersForPoints[indexOfNumbersForPoints], numbersForPoints[indexOfNumbersForPoints + 1]);
        indexOfNumbersForPoints += 2;
    }
    Polygon polygon = Polygon(numPoints, points);
    delete[] numbersForPoints;
    delete[] points;
    cout << "The polygon's circumference is: " << polygon.circumference() << endl;
    return 0;
}
/**
* Sample Execution:
Please enter number of points in the for inclusion in a polygon, then the points themselves
4 0 0 0 2 2 2 2 0
The polygon's circumference is : 8

Please enter number of points in the for inclusion in a polygon, then the points themselves
3 10 10 10 14 13 10
10 10
10 14
13 10
The polygon's circumference is: 12
**/