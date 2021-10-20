#include <iostream>
using namespace std;
#include <fstream>
#include "Student.h"

/**
 * @brief OPtions for main menu
*/

enum Options
{
    EXIT,//Exit menu
    ADD_STUDENT,//Adds student to end of file
    DELETE_STUDENT,//Sets 0 to id of student
    UPDATE_STUDENT,//Update boolean values for all courses of a student
    CHECK_ENLISTED,//Check if student is enlisted in a course
    PRINT_STUDENT,//Print student's details
    PRINT_IN_COURSE//Print names of students in course

};

/**
 * @brief Initialize file with blank students
 * @param fs A file stream open for writing
*/

void initializeBinaryFile(fstream*& fs)
{
    fs->clear();
    fs->seekp(0);
    for (int i = 0; i < 100; ++i)
    {
        Student stud = Student();
        fs->write((char*)&stud, sizeof(Student));
    }
}

/**
 * @brief Check if a student with with id studId exists in system
 * @param fs A pointer to a file stream open for reading
 * @param studId id of student
 * @return location of beginning of record if exists in file stream, else -1
*/

int findStudent(fstream*& fs, int studId)
{
    Student stud;
    fs->clear();
    fs->seekg(0);
    fs->read((char*)&stud, sizeof(Student));
    while (!fs->eof())
    {
        if (stud.getStudId() == studId)
        {
            int place = fs->tellg();

            fs->clear();
            /*Return student read previously,
            since we moved to next one*/
            return (place - sizeof(stud));
        }
        fs->read((char*)&stud, sizeof(Student));
    }

    return -1;
}

/**
 * @brief Add new student to file stream fs
 * @param fs A file stream open for reading and writing
*/

void addNewStudent(fstream*& fs)
{
    fs->clear();
    fs->seekg(0);
    int id;
    char firstName[20];
    char lastName[20];
    bool inCourses[5];
    char endL;
    cout << "Please enter id, first name,last name and 1(true)/0(false) for participance in each course of the five courses for a new student" << endl;
    cin >> id;
    int findStud = findStudent(fs, id);
    if (findStud != -1)
    {
        cout << "The student exists already in the system" << endl;
        return;
    }
    cin.ignore();
    cin.getline(firstName, 19);
    cin.getline(lastName, 19);
    for (int i = 0; i < 5; ++i)
    {
        cin >> inCourses[i];
    }
    Student stud = Student(id, firstName, lastName, inCourses);
    fs->clear();
    fs->seekp(0, ios::end);
    fs->write((char*)&stud, sizeof(Student));

}

/**
 * @brief Print student with id studId's details from file stream fs
 * @param A pointer to a file stream that's open for reading
 * @param studId a student id number
*/

void printStudentDetails(fstream*& fs, int studId)
{
    fs->clear();
    Student stud;
    int studLocationInFile = findStudent(fs, studId);
    if (studLocationInFile != -1)
    {
        fs->seekg(studLocationInFile);
        fs->read((char*)&stud, sizeof(Student));
        cout << stud;
    }
    else
    {
        cout << "Student doesn't exist on the system" << endl;
    }

}

/**
 * @brief Deletes student with id studId from file stream fs by setting the student's id to zero
 * @param fs A pointer to a file stream that's open for reading and writing
 * @param studId A student id
*/

void deleteStudent(fstream*& fs, int studId)
{
    fs->clear();
    Student stud;
    int studLocationInFile = findStudent(fs, studId);
    if (studLocationInFile == -1)
    {
        cout << "Impossible to delete " << studId << " since the student doesn't  exist on the system" << endl;
        return;
    }
    fs->seekg(studLocationInFile);
    fs->read((char*)&stud, sizeof(Student));
    /*Delete student by setting id to 0*/
    int getIdDeleted = stud.getStudId();
    stud.setStudId(0);
    fs->seekp(studLocationInFile);
    fs->write((char*)&stud, sizeof(Student));
    cout << "Student no. " << getIdDeleted << " deleted successfully" << endl;

}

/**
 * @brief Updates the information about enrollment in courses for student studNum from file stream fs
 * @param fs
 * @param courseNum A number between 1 to 5. In the case it's different, an error message will appear and the operation will fail.
 * @param studNum  number of  a student id
*/

void updateStudent(fstream*& fs, int studNum)
{
    fs->clear();
    Student stud;
    int studLocationInFile = findStudent(fs, studNum);
    bool inCourse = false;
    if (studLocationInFile == -1)
    {
        cout << "Cannot update " << studNum << " since the student doesn't exist on the system" << endl;
        return;
    }
    fs->seekg(studLocationInFile);
    fs->read((char*)&stud, sizeof(Student));
    cout << "Enter 0/1 for each of the 5 courses" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cin >> inCourse;
        stud.setCourseI(inCourse, i);
    }
    fs->seekp(studLocationInFile);
    fs->write((char*)&stud, sizeof(Student));

}

/**
 * @brief Prints students from file stream fs that are enrolled in course number courseNum
  * @param studId a student id
  * @param courseNum A number between 1 to 5. In the case it's different, an error message will appear and the operation will fail.
*/

void printStudentsInCourse(fstream*& fs, int courseNum)
{
    fs->clear();
    fs->seekg(0);
    bool* inCourses;
    if (courseNum < 1 || courseNum>5)
    {
        cout << "course number must be between 1-5(including)" << endl;
        return;
    }
    courseNum--;//because indexes start at 0 and courseNum starts from 1
    Student stud;
    fs->read((char*)&stud, sizeof(Student));
    while (!fs->eof())
    {
        if (stud.getRegisteredToCourse()[courseNum] == true)
        {
            cout << stud.getFirstName() << " " << stud.getLastName() << endl;
        }
        fs->read((char*)&stud, sizeof(Student));
    }

}

/**
 * @brief Check if studId is enrolled in courseNum
 * @param fs A pointer to a file stream
 * @param studId a student id
 * @param courseNum A number between 1 to 5. In the case it's different, an error message will appear and the operation will fail.
 * @return true/false
*/

bool inCourse(fstream*& fs, int studId, int courseNum)
{
    fs->clear();
    fs->seekg(0);
    Student stud;
    if (courseNum < 1 || courseNum>5)
    {
        cout << "course number must be between 1-5(including)" << endl;
        return false;
    }
    courseNum--;//The index of bool arrays starts at 0 so values of enrolled/not enrolled are at indexes 0-4
    int placeStudent = findStudent(fs, studId);
    if (placeStudent == -1)
    {
        cout << "Student does not exist on system" << endl;
        return false;
    }
    fs->seekg(placeStudent);
    fs->read((char*)&stud, sizeof(Student));
    if (stud.getRegisteredToCourse()[courseNum] == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/**
 * @brief Driver code to allow operations on students binary file.
 * @param
 * @return
*/

int main(void)
{
    int option;
    fstream fs;
    fs.open("students.bin", ios::in | ios::out | ios::binary);
    if (!fs)
    {
        cout << "The file cannot be accessed!" << endl;
        exit(-1);
    }
    fstream* pfs = &fs;
    //initializeBinaryFile(pfs);only need to initialize once...
    int id;
    int courseNumber;
    bool enlisted = false;
    cout << "Choose an option:from 0(exit),1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student),6(print in course)" << endl;

    cin >> option;
    while (option)
    {

        switch (option)
        {
        case EXIT:
            break;
        case ADD_STUDENT:
            addNewStudent(pfs);
            break;
        case DELETE_STUDENT:
            cout << "Enter id of student to delete" << endl;
            cin >> id;
            deleteStudent(pfs, id);
            break;
        case UPDATE_STUDENT:
            cout << "Enter id of student to update" << endl;
            cin >> id;
            updateStudent(pfs, id);
            break;
        case CHECK_ENLISTED:
            cout << "Enter id of student and course number to see if they're in it" << endl;
            cin >> id;
            cin >> courseNumber;
            enlisted = inCourse(pfs, id, courseNumber);
            cout << "Student " << id;
            if (enlisted)
            {
                cout << " is enrolled in course: " << courseNumber << endl;
            }
            else {
                cout << " isn't enrolled in course: " << courseNumber << endl;
            }
            break;
        case PRINT_STUDENT:
            cout << "Enter id of student to print" << endl;
            cin >> id;
            printStudentDetails(pfs, id);
            break;
        case PRINT_IN_COURSE:
            cout << "Enter course number" << endl;
            cin >> courseNumber;
            printStudentsInCourse(pfs, courseNumber);
            break;
        }
        cout << "Choose an option:from 0(exit),1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student),6(print in course)" << endl;
        cin >> option;
    } while (option != 0);
    fs.close();
    return 0;
}
/**Sample Execution:
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
1
Please enter id, first name, last name and 1(true) / 0(false) for participance in each course of the five courses for a new student
800
Yehuda
Binyamin
1
1
1
1
1
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
1
Please enter id, first name, last name and 1(true) / 0(false) for participance in each course of the five courses for a new student
345
John
Cohn
1
0
0
1
0
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
3
Enter id of student to update
345
Enter 0 / 1 for each of the 5 courses
1
1
0
1
0
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
4
Enter id of student and course number to see if they're in it
345
2
Student 345 is enrolled in course : 2
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
5
Enter id of student to print
345
345
John
Cohn
Y
Y
N
Y
N
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
6
Enter course number
2
Yehuda Binyamin
John Cohn
Choose an option : from 0(exit), 1(add student), 2(delete student), 3(update student), 4(check enlisted), 5(print student), 6(print in course)
0**/