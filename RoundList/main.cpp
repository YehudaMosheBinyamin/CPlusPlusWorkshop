#include "RoundList.h"
#include <iostream>
using namespace std;
/**
@author Lecturer at Machon Lev
**/
enum CHOICES {
    /**
     * @brief Exit
    */
    EXIT, 
    /**
     * @brief Add to front of list
    */
    ADD, 
    /**
     * @brief Add to end of list
    */
    ADD_TO_END, 
    /**
     * @brief Remove first element of the list
    */
    REMOVE_FIRST,
    /**
     * @brief Search for element in list
    */
    SEARCH, 
    /**
     * @brief Clear list. Sets head and last to NULL.
    */
    CLEAR, 
    /**
     * @brief Check if list is empty
    */
    EMPTY

};
/**
 * @author Lecturer at Machon Lev
 * @brief Driver code.
 * Alllows the operations in enum CHOICES.
 * @return 
*/
int main() {

    RoundList ls1;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != EXIT)
    {
        int num;
        switch (choice) {
        case ADD: 	cout << "Enter 5 numbers: ";
            for (int i = 0; i < 5; i++)
            {
                cin >> num;
                ls1.add(num);
            }
            break;
        case ADD_TO_END:cout << "Enter 5 numbers: ";
            for (int i = 0; i < 5; i++)
            {
                cin >> num;
                ls1.addToEnd(num);
            }
            break;

        case REMOVE_FIRST: ls1.removeFirst();
            break;

        case SEARCH: cout << "Enter a number: ";
            cin >> num;
            cout << ls1.search(num) << endl;
            break;

        case CLEAR: ls1.clear();
            break;

        case EMPTY: if (ls1.isEmpty())
            cout << "Empty" << endl;
                  else
            cout << "Not empty" << endl;
            break;

        default: cout << "ERROR!" << endl;
        }
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}
/**
Enter your choice : 1
Enter 5 numbers : 1 2 3 4 5
Enter your choice : 1
Enter 5 numbers : 6 7 8 9 10
Enter your choice : 2
Enter 5 numbers : 11 12 13 14 15
Enter your choice : 2
Enter 5 numbers : 16 17 18 19 20
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 6
Not empty
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 3
Enter your choice : 6
Not empty
Enter your choice : 3
Enter your choice : 6
Empty
Enter your choice : 1
Enter 5 numbers : 12 13 14 15 16
Enter your choice : 1
Enter 5 numbers : 17 18 19 20 21
Enter your choice : 4
Enter a number : 1
20
Enter your choice : 4
Enter a number : 5
16
Enter your choice : 0
**/