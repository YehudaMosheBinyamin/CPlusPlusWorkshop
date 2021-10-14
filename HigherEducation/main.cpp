#include<iostream>
using namespace std;
#include<vector>
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"
/**
 * @author Yehuda Moshe Binyamin
 * @brief Prints only students eligible for a grant
 * @param students
*/
void printOnlyEligible(vector<Student*> students)
{
    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i]->milga() == true)
        {
            students[i]->print();
        }
    }
}
/**
 * @brief Driver code. Initialization of a vector of seven sample students.
 * The function will call the printOnlyEligible global function in order to print the students eligible for a grant
 * @return
*/
int main()
{
    vector<Student*>myVec1;
    int id;
    string firstName;
    string lastName;
    id = 123;
    firstName = "abe";
    lastName = "avraham";
    float grades[] = { 90, 100, 90 };
    BA BAFirst = BA(id, firstName, lastName, 3, grades, 3);
    myVec1.push_back(&BAFirst);


    id = 234;
    firstName = "itzhak";
    lastName = "avrahamson";
    float gradesSecond[10] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };
    BA BASecond = BA(id, firstName, lastName, 10, gradesSecond, 10);
    myVec1.push_back(&BASecond);


    id = 345;
    firstName = "yaakov";
    lastName = "jacobson";
    float gradesMAFirst[7] = { 90, 100, 90, 100, 90, 100, 90 };
    MA MAFirst = MA(id, firstName, lastName, 7, gradesMAFirst, 7, 0);
    myVec1.push_back(&MAFirst);


    id = 456;
    firstName = "sara";
    lastName = "emanu";
    float gradesMASecond[7] = { 90, 100, 90, 100, 90, 100, 90 };
    MA MASecond = MA(id, firstName, lastName, 7, gradesMASecond, 7, 1);
    myVec1.push_back(&MASecond);



    id = 567;
    firstName = "rivka";
    lastName = "imanu";
    PHD PHDFirst = PHD(id, firstName, lastName, 1, 30);
    myVec1.push_back(&PHDFirst);



    id = 678;
    firstName = "rachel";
    lastName = "jacobs";
    PHD PHDSecond = PHD(id, firstName, lastName, 2, 20);
    myVec1.push_back(&PHDSecond);


    id = 789;
    firstName = "leah";
    lastName = "jacobs";
    PHD PHDThird = PHD(id, firstName, lastName, 2, 30);
    myVec1.push_back(&PHDThird);
    printOnlyEligible(myVec1);
    return 0;
}
/**Sample Execution
ID: 234
first name : itzhak
last name : avrahamson
num courses : 10
grades : 100 100 90 100 90 100 90 100 90 100
ID : 456
first name : sara
last name : emanu
num courses : 7
grades : 90 100 90 100 90 100 90
research : yes
ID : 789
first name : leah
last name : jacobs
num courses : 2
hours : 30
**/
