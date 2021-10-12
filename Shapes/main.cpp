#include<iostream>
using namespace std;
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"
/**
 * @author Yehuda Moshe Binyamin
 * @brief Driver code.
 * Receives from user number of edges of polygon, and then the edges of the polygon.
 * Then it receives that information for a second polygon and prints "equal" if the polygons are equals,
 * or "not equal" otherwise.
 * @return 
*/
int main()
{
    int amountSidesFirst;
    int amountSidesSecond;
    Polygon* first = NULL;
    Polygon* second = NULL;
    int sides[4] = { 0 };
    cout << "enter number of sides for polygon 1:" << endl;
    cin >> amountSidesFirst;
    if (amountSidesFirst > 4)
    {
        first = new Polygon(amountSidesFirst);
    }
    else
    {
        cout << "enter sides for polygon:" << endl;
        if (amountSidesFirst == 3)
        {
            for (int i = 0; i < amountSidesFirst; ++i)
            {
                cin >> sides[i];
            }
            first = new Triangle(sides[0], sides[1], sides[2]);
        }
        else//if(amountSidesFirst == 4)
        {
            //Practically, input only two sides, the adjacent ones. 
            //The constructor will initialize also the opposite sides with the same length
            for (int i = 0; i < amountSidesFirst / 2; ++i)
            {
                cin >> sides[i];
            }
            first = new Rectangle(sides[0], sides[1]);
        }
    }
    cout << "enter number of sides for polygon 2:" << endl;
    cin >> amountSidesSecond;
    if (amountSidesFirst == amountSidesSecond)
    {

        if (amountSidesSecond > 4)
        {
            second = new Polygon(amountSidesSecond);
        }
        else
        {
            cout << "enter sides for polygon:" << endl;
            if (amountSidesFirst == 3)
            {
                for (int i = 0; i < amountSidesFirst; ++i)
                {
                    cin >> sides[i];
                }
                second = new Triangle(sides[0], sides[1], sides[2]);
            }
            else//if (amountSidesFirst == 4)
            {
                amountSidesFirst = 2;//Practically, input only two sides, the adjacent ones. 
                //The constructor will initialize also the opposite sides with the same length
                for (int i = 0; i < amountSidesFirst; ++i)
                {
                    cin >> sides[i];
                }
                second = new Rectangle(sides[0], sides[1]);
            }
        }
        bool equal = *first == *second;
        if (equal)
        {
            cout << "equal" << endl;
        }
        else
        {
            cout << "not equal" << endl;
        }
    }
    else {
        cout << "not equal" << endl;
    }
    delete first;
    delete second;
    return 0;
}
/**
enter number of sides for polygon 1:
3
enter sides for polygon :
20 10 15
enter number of sides for polygon 2 :
3
enter sides for polygon :
11 14 20
equal


enter number of sides for polygon 1:
3
enter sides for polygon:
20 10 15
enter number of sides for polygon 2:
3
enter sides for polygon:
10 14 20
not equal

enter number of sides for polygon 1:
4
enter sides for polygon:
20 15
enter number of sides for polygon 2:
4
enter sides for polygon:
15 10
not equal

enter number of sides for polygon 1:
6
enter sides for polygon:
20 10  5 5 5 15
enter number of sides for polygon 2:
6
enter sides for polygon:
10 10  10 10 5 15
equal

enter number of sides for polygon 1:
6
enter sides for polygon:
20 10  5 5 5 15
enter number of sides for polygon 2:
2
not equal




**/
