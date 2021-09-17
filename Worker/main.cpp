#include <iostream>
#include "Worker.h"
using namespace std;
/**
*328972427
*A program that receives details about the workers and prints the id and name of both the hardest worker(the worker who worked the most hours) 
*and the highest salaried worker
**/
//driver function
int main()
{
    Worker* workers = new Worker[1000];
    int extraHours;
    int hoursWorked;
    float salaryPerHour;
    int idNumber;
    char name[20];
    int i = 0;//index for Worker elements in workers array
    cout << "enter details, to end enter 0" << endl;
    while (true)
    {
        cin >> idNumber;
        if (idNumber == 0)
        {
            break;
        }
        cin >> name;
        cin >> salaryPerHour;
        if (salaryPerHour < 0)
        {
            cout << "ERROR" << endl;
            continue;
        }
        cin >> hoursWorked;
        if (hoursWorked < 0)
        {
            cout << "ERROR" << endl;
            continue;
        }
        cin >> extraHours;
        if (extraHours < 0)
        {
            cout << "ERROR" << endl;
            continue;
        }
        workers[i].setIdNumber(idNumber);
        workers[i].setName(name);
        workers[i].setSalaryPerHour(salaryPerHour);
        workers[i].setHoursWorked(hoursWorked);
        workers[i].setExtraHours(extraHours);
        i++;
    }
    int mostHours = workers[0].getAllHours();
    int hardestWorkerIndex = 0;
    int totalHours;
    for (int j = 1; j < i; j++)
    {
        totalHours = workers[j].getAllHours();
        if (totalHours > mostHours)
        {
            mostHours = totalHours;
            hardestWorkerIndex = j;
        }
    }

    float biggestSalary = workers[0].getTotalSalary();
    int highestSalariedWorkerIndex = 0;
    float totalSalary;
    for (int j = 1; j < i; j++)
    {
        totalSalary = workers[j].getTotalSalary();
        if (totalSalary > biggestSalary)
        {
            biggestSalary = totalSalary;
            highestSalariedWorkerIndex = j;
        }
    }
    cout << "highest salary:" << " \t" << workers[highestSalariedWorkerIndex].getIdNumber() << "\t" << workers[highestSalariedWorkerIndex].getName() << endl;
    cout << "hardest worker:" << " \t" << workers[hardestWorkerIndex].getIdNumber() << "\t" << workers[hardestWorkerIndex].getName() << endl;

    delete[] workers;
    return 0;
}

/**Sample Execution:
enter details, to end enter 0
123456789 avrakam 50 40 2
135792468 yaakov 100 30 0
975312468 sara 30 45 10
0
highest salary : 135792468       yaakov
hardest worker : 975312468       sara
**/