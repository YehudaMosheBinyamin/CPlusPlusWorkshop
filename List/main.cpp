#include <iostream>
#include "List.h"
using namespace std;
/**
 * @brief Merges two nondescending lists into one.
 * @param firstList
 * @param secondList
 * @return thirdList
*/
List merge(List& firstList, List& secondList)
{
    List thirdList;
    List::Link* firstListPtr = firstList.head;
    List::Link* secondListPtr = secondList.head;
    while ((firstListPtr != NULL) && (secondListPtr != NULL))
    {
        if (firstListPtr->value < secondListPtr->value)
        {
            thirdList.insert(firstListPtr->value);
            firstListPtr = firstListPtr->next;
        }
        else
        {
            thirdList.insert(secondListPtr->value);
            secondListPtr = secondListPtr->next;
        }
    }
    while ((firstListPtr != NULL) && (secondListPtr == NULL))
    {
        thirdList.insert(firstListPtr->value);
        firstListPtr = firstListPtr->next;
    }
    while ((secondListPtr != NULL) && (firstListPtr == NULL))
    {
        thirdList.insert(secondListPtr->value);
        secondListPtr = secondListPtr->next;
    }

    return thirdList;
}


/**
 * @brief Removes duplicate elements
 * @param list
*/
void makeSet(List& list)
{
    List::Link* linkPtr = list.head;
    while (linkPtr->next != NULL)
    {	//If there are duplicates
        if (linkPtr->value == linkPtr->next->value)
        {
            List::Link* ptr = linkPtr->next;//The element to access after deletion
            list.remove(linkPtr->value);
            linkPtr = ptr;
        }
        else
        {
            linkPtr = linkPtr->next;
        }
    }
}
/**
 * @brief Driver code supplied by lecturers.
 * Receives from the users integers in ascending order, until a lower number is inputted for two lists . Prints the merged list, and the merged list without repititive elements.
 * Afterwards it will receive from the user integers of a list and allow exit(option 0), insertion(option 1) or removal (option 2)
 * @return
*/
int main()
{
    List lst1, lst2, mergedList;

    cout << "enter sorted values for the first list:" << endl;
    cin >> lst1;
    cout << "enter sorted values for the second list:" << endl;
    cin >> lst2;
    mergedList = merge(lst1, lst2);
    cout << "the new merged list: " << mergedList << endl;
    makeSet(mergedList);
    cout << "the new merged set: " << mergedList << endl;
    List lst;
    int choice, val;
    cout << "enter the list values\n";
    cin >> lst;
    cout << "choose 0-2\n";
    cin >> choice;
    while (choice)
    {
        switch (choice)
        {
        case 1:cout << "enter a value to insert\n";
            cin >> val;
            lst.insert(val);
            break;
        case 2:cout << "enter a value to remove\n";
            cin >> val;
            try {
                lst.remove(val);
            }
            catch (char* msg)
            {
                cout << msg << endl;
            }
            break;
        default:cout << "ERROR\n";
        }
        cout << lst << endl;
        cout << "choose 0-2\n";
        cin >> choice;
    }

    return 0;
}
/**
enter sorted values for the first list :
1
2
3
3
4
4
5
5
6
6
7
7
8
8
8
9
10
10
4
enter sorted values for the second list :
1
2
3
3
4
4
5
5
6
6
7
7
8
8
8
9
10
4
the new merged list : 1
1
2
2
3
3
3
3
4
4
4
4
5
5
5
5
6
6
6
6
7
7
7
7
8
8
8
8
8
8
9
9
10
10
10

the new merged set : 1
2
3
4
5
6
7
8
9
10


enter the list values
2
3
4
5
6
7
8
8
7
choose 0 - 2
1
enter a value to insert
1
1
2
3
4
5
6
7
8
8

choose 0 - 2
1
enter a value to insert
123
1
2
3
4
5
6
7
8
8
123

choose 0 - 2
1
enter a value to insert
60
1
2
3
4
5
6
7
8
8
60
123

choose 0 - 2
2
enter a value to remove
123
1
2
3
4
5
6
7
8
8
60

choose 0 - 2
2
enter a value to remove
1
2
3
4
5
6
7
8
8
60

choose 0 - 2
0
**/