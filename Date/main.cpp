#include "Date.h"
#include <iostream>
using namespace std;
enum Codes{UpdateDate=1,PreIncrement,PostIncrement,PlusEquals,Bigger,Smaller,Equal,Exit=-1};
//328972427
/**
*Program to do operations on dates, such as the result of adding days to the result, updating the date, checking if it's bigger than an other date
* or smaller or equal.It's possible to choose requested operation based on Codes values.
**/
int main(void) 
{
    Date dateOne;
    Date dateTwo;
    int day;
    int month;
    int year;
    cout << "Enter a date" << endl;
    cin >> day;
    cin >> month;
    cin >> year;
    dateOne.setDate(day, month, year);
    dateOne.print();
    int operationCode;
    int daysToAdd;
    do {
        cout << "What do you want to do?" << endl;
        cin >> operationCode;
        switch (operationCode) {
        case UpdateDate:
        {cin >> day;
        cin >> month;
        cin >> year;
        dateOne.setDate(day, month, year);
        dateOne.print();
        break; }
        case PreIncrement:
        {(++dateOne).print();
        break; }
        case PostIncrement:
        {(dateOne++).print(); 
        break; }
        case PlusEquals:
        {cout << "Enter #days" << endl;
        cin >> daysToAdd;
        (dateOne += daysToAdd).print();
        break; }
        case Bigger:
            {cout << "Enter a date" << endl;
            cin >> day;
            cin >> month;
            cin >> year;
            dateTwo.setDate(day, month, year);
            bool bigger = dateOne > dateTwo;
            cout << "first date > second date: ";
            if (bigger == 1)
            {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
            break; }
        case Smaller:
        {cout << "Enter a date" << endl;
        cin >> day;
        cin >> month;
        cin >> year;
        dateTwo.setDate(day, month, year);
        bool smaller = dateOne < dateTwo;
        cout << "first date < second date: ";
        if (smaller == 1)
        {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
        break; }
        case Equal:
        {cout << "Enter a date" << endl;
        cin >> day;
        cin >> month;
        cin >> year;
        dateTwo.setDate(day, month, year);
        bool equal = dateOne == dateTwo;
        cout << "first date==second date: ";
        if (equal == 1)
        {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
        break; }
        case Exit:
            break;
        }
    } while (operationCode != -1);
    return 0;
}
/**
* Sample Execution
Enter a date
1
1
2020
1 / 1 / 2020
What do you want to do ?
4
Enter #days
560
21 / 7 / 2021
What do you want to do ?
3
21 / 7 / 2021
What do you want to do ?
2
2 / 1 / 2022
What do you want to do ?
1
1
1
2020
1 / 1 / 2020
What do you want to do ?
5
Enter a date
1
2
2000
first date > second date : true
What do you want to do ?
6
Enter a date
12
12
2020
first date < second date : true
What do you want to do ?
7
Enter a date
12
6
2030
first date == second date : false
What do you want to do ?
-1
**/