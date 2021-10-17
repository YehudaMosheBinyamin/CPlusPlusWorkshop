#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"


enum option {
    stop,	//	סיום התוכנית
    addNewStudent,	//	הוספת סטודנט חדש
    milgalist,	//	הדפסת פרטי כל התלמידים הזכאים למלגה
    mostResearch,	//	הדפסת שם (משפחה ופרטי) של הסטודנט שעוסק הכי הרבה שעות במחקר
    countMilgaBA,	//	הדפסת מספר הסטודנטים לתואר ראשון הזכאים למלגה
    noResearchMA,	//	הדפסת שמות (משפחה ופרטי) של הסטודנטים MA שאינם עוסקים במחקר
    overheadStudent,	//	הדפסת הודעה מתאימה, האם קיים סטודנט שלומד יותר מ- 15 קורסים
    removePHDFailers,	//	מחיקת כל הסטודנטים לתואר שלישי שאינם לומדים באף קורס
};
//פונקצית הוספת סטודנט לרשימת הסטודנטים
void add(list <Student*>& students)
{
    int typeStudent;
    int numOfCourses;
    int id;
    string firstName;
    string lastName;
    bool doesResearch;
    int researchHoursWeekly;
    cout << "enter 1 to add a BA student\n";
    cout << "enter 2 to add a MA student\n";
    cout << "enter 3 to add a PHD student\n";
    cin >> typeStudent;
    cout << "enter id, first name, last name and number Of Courses\n";
    cin >> id;
    cin >> firstName;
    cin >> lastName;
    cin >> numOfCourses;
    BA* baStudent;
    MA* maStudent;
    PHD* phdStudent;
   
    int numOfGrades = numOfCourses;
    float* grades = NULL;
    //אם מדובר בתלמידים לתואר ראשון ושני יש להזין נתונים
    if (typeStudent == 1 || typeStudent == 2)
    {   cout << "enter " << numOfCourses << " grades\n";
        grades = new float[numOfCourses];
        for (int i = 0; i < numOfCourses; ++i)
        {
            cin >> grades[i];
        }
    }
    switch (typeStudent)
    {
    case 1:
        baStudent = new BA(id, firstName, lastName, numOfCourses, grades, numOfGrades);
        students.push_back(baStudent);
        break;
    case 2:
        cout << "enter 1 if the student does research and 0 if not\n";
        cin >> doesResearch;
        maStudent = new MA(id, firstName, lastName, numOfCourses, grades, numOfGrades, doesResearch);
        students.push_back(maStudent);
        break;
    case 3:
        cout << "enter number of research hours\n";
        cin >> researchHoursWeekly;
        phdStudent = new PHD(id, firstName, lastName, numOfCourses, researchHoursWeekly);
        students.push_back(phdStudent);
        break;
    }
}
//פונקציה המדפיסה את נתוני הזכאים למלגה
void milga(list<Student*> students)
{
    for_each(students.begin(), students.end(), [](Student* student) {if (student->milga() == true) { student->print(); }});
}
//פונקציה המדפיסה את תלמיד לדוקטורט שחוקר הכי הרבה שעות. 
//NULL אם אין סטודנטי ם לדוקטורט אז יוחזר 
//אם יש מספר סטודנטים עם אותו נתון אז יוחזר התלמיד המקסימלי הראשון ברשימה  
Student* mostResearchHours(list<Student*> students)
{
    students.remove_if([](Student* student) {return student->studType() == string("MA") || student->studType() == string("BA"); });
    if (students.size() == 0)
    {
        return NULL;
    }
    return *(max_element(students.begin(), students.end(), [=](Student* one, Student* two) {return ((PHD*)one)->getWeeklyResearchHours() < ((PHD*)two)->getWeeklyResearchHours(); }));
}


//פונקציה ממרצה המאפשר ביצוע פעולות של מידע על רשימת סטודנטים
int main()
{
    Student* s;
    list<Student*> students;
    int op;
    cout << "enter 0-7\n";
    cin >> op;
    while (op != stop)
    {
        switch (op)
        {
        case addNewStudent:add(students);//הוספת סטודנט חדש					
            break;
        case milgalist:milga(students);	//הדפסת פרטי הזכאים למלגה
            break;
        case mostResearch:

            //הדפסת שם הסטודנט שעוסק במחקר הכי הרבה שעות:
            s = mostResearchHours(students);
            if (s != NULL)
            {
                cout << "PHD studnet with most research hours: ";
                cout << s->getFname() << ' ' << s->getLname() << endl;
            }
            break;

        case countMilgaBA:
            cout << "#BA studnets for milga: ";
            cout << count_if(students.begin(), students.end(), [](Student* student) {return student->studType() == "BA" && student->milga() == true; });
            cout << endl;
            break;


        case noResearchMA:
            cout << "list of no research MA students : ";
            //הדפסת רשימת (שם משפחה ופרטי) הסטודנטים לתואר שני שאינם עוסקים במחקר
            for_each(students.begin(), students.end(), [](Student* student) {if (student->studType() == "MA" && ((MA*)student)->getInResearch() == false) { cout << student->getFname() << " " << student->getLname(); }});
            cout << endl;
            break;


        case overheadStudent:
            if (any_of(students.begin(), students.end(), [](Student* student) {return student->getNumCourses() > 15; }))
            {
                cout << "there is a student that takes more than 15 courses\n";
            }
            else
            {
                cout << "no student takes more than 15 courses\n";
            }
            break;

        case removePHDFailers:
            //מחיקה מהווקטור/רשימה של כל הסטודנטים לתואר שלישי שאינם לומדים קורסים בכלל
            students.remove_if([](Student* student) {return student->studType() == "PHD" && student->getNumCourses() == 0; });
            for_each(students.begin(),students.end(), [](Student* student) { student->print(); });
            //הדפסת כל הרשימה אחרי מחיקת האיברים
            break;
        };
        cout << "enter 0-7\n";
        cin >> op;
    }
    return 0;
}
/**
הרצה לדוגמה
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last nameand number Of Courses
123 abe avraham 3
enter 3 grades
90 100 90
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last nameand number Of Courses
234 yitzhak avrahamson 10
enter 10 grades
100 100 90 100 90 100 90 100 90 100
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last nameand number Of Courses
345
yaacov jacobson 7
enter 7 grades
90 100 90 100 90 100 90
enter 1 if the student does research and 0 if not
0
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last nameand number Of Courses
456
sara emanu 7
enter 7 grades
100 90 100 100 90 90 90
enter 1 if the student does research and 0 if not
1
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last nameand number Of Courses
567 rivka imanu 1
enter number of research hours
30
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last nameand number Of Courses
678 rachel jacobs 0
enter number of research hours
20
enter 0 - 7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last nameand number Of Courses
789 leah jacobs 2
enter number of research hours
30
enter 0 - 7
2
ID: 234
first name : yitzhak
last name : avrahamson
num courses : 10
grades : 100 100 90 100 90 100 90 100 90 100
ID : 456
first name : sara
last name : emanu
num courses : 7
grades : 100 90 100 100 90 90 90
research : yes
ID : 789
first name : leah
last name : jacobs
num courses : 2
hours : 30
enter 0 - 7
3
PHD studnet with most research hours : rivka imanu
enter 0 - 7
4
#BA studnets for milga: 1
enter 0 - 7
5
list of no research MA students : yaacov jacobson
enter 0 - 7
6
no student takes more than 15 courses
enter 0 - 7
7
ID : 123
first name : abe
last name : avraham
num courses : 3
grades : 90 100 90
ID : 234
first name : yitzhak
last name : avrahamson
num courses : 10
grades : 100 100 90 100 90 100 90 100 90 100
ID : 345
first name : yaacov
last name : jacobson
num courses : 7
grades : 90 100 90 100 90 100 90
research : no
ID : 456
first name : sara
last name : emanu
num courses : 7
grades : 100 90 100 100 90 90 90
research : yes
ID : 567
first name : rivka
last name : imanu
num courses : 1
hours : 30
ID : 789
first name : leah
last name : jacobs
num courses : 2
hours : 30
enter 0 - 7
0
**/