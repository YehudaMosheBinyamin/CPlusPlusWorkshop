#include "Clock.h"
#include "Account.h"

enum action
{
    stop,
    balance,
    deposit,
    withdraw,
    sumDeposit,
    sumWithdraw
};
action menu()
{
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to deposit money" << endl;
    cout << "enter 3 to withdraw money" << endl;
    cout << "enter 4 to see the sum of all withdraws" << endl;
    cout << "enter 5 to see the sum of all Deposits" << endl;
    cout << "enter 0 to stop" << endl;
    int x;
    cin >> x;
    return (action)x;
}
int findAccount(Account* bank, int size)
{

    int number, code;
    cout << "please enter account number: ";
    cin >> number;
    int i = 0;
    while (i < size && bank[i].getAccountNumber() != number)
        i++;
    //i=Size will be accessing element after last element in bank array...
    if (i == size)
    {
        throw "ERROR: no such account number!";
    }
    cout << "please enter the code: ";
    cin >> code;
    if (bank[i].getCode() == code)
    {
        return i;
    }
    else
    {
        throw "ERROR:wrong code!";
    }
}


void printTransaction(Account a, action ac, Clock& c)
{
    cout << c << "\t";
    ;
    switch (ac)
    {
    case balance: cout << "account #: " << a.getAccountNumber() << "\t";
        cout << "balance: " << a.getBalance() << endl;
        break;
    case deposit:
    case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
        cout << "new balance: " << a.getBalance() << endl;
        break;
    case sumDeposit:
        cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
        break;
    case sumWithdraw:
        cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
        break;
    }
}
void getBalance(Account* bank, int size, Clock& c)
{
    try {
        int i = findAccount(bank, size);
        c += 20;
        printTransaction(bank[i], balance, c);
    }
    catch (const char* errorMessage)
    {
        cout << c << " " << errorMessage << endl;
    }
}
void cashDeposit(Account* bank, int size, Clock& c)
{
    try {
        int i = findAccount(bank, size);
        float amount;
        cout << "enter the amount of the check: ";
        cin >> amount;
        bank[i].deposit(amount);
        c += 30;
        printTransaction(bank[i], deposit, c);
    }
    catch (const char* errorMessage)
    {
        cout << c << " " << errorMessage << endl;
    }
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
    try {
        int i = findAccount(bank, size);
        float amount;
        cout << "enter the amount of money to withdraw: ";
        cin >> amount;
        bank[i].withdraw(amount);
        c += 50;
        printTransaction(bank[i], withdraw, c);
    }
    catch (const char* errorMessage)
    {
        cout << c << " " << errorMessage << endl;
    }
}
float Account::sumDeposit = 0.0f;
float Account::sumWithdraw = 0.0f;
/**
* Yehuda Moshe Binyamin
 * Driver function that receives 10 account details, and allows operations defined in enum action.
 * In case of error, the error will caught and be printed on the screen.
 * Main.cpp is code of the lecturer.
 * @return
*/
int main()
{
    Clock c(8);
    Account bank[10];
    cout << "enter account number and code for 10 accounts:\n";
    for (int i = 0; i < 10; i++)
    {

        try {
            cin >> bank[i];
            for (int j = 0; j < i; j++)
                if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
                    throw "ERROR: account number must be unique!\n";
        }
        catch (const char* msg)
        {
            cout << c << '\t' << msg;
            i--;
        }
    }
    action ac = menu();
    while (ac)
    {
        switch (ac)
        {
        case balance: getBalance(bank, 10, c);
            break;
        case withdraw:cashWithdraw(bank, 10, c);
            break;
        case deposit:cashDeposit(bank, 10, c);
            break;
        case sumDeposit:c += 60;
            printTransaction(bank[0], sumDeposit, c);
            break;
        case sumWithdraw:c += 60;
            printTransaction(bank[0], sumWithdraw, c);

        }
        ac = menu();
    }
    return 0;
}
/**Sample Execution:
enter account number and code for 10 accounts:
1000 2
08 : 00 : 00        ERROR : code must be of 4 digits!
10001 1000
1000 1000
1001 1001
1002 1002
1003 1003
1004 1004
1005 1005
1006 1006
1007 1007
1008 1008
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number : 53445
08 : 00 : 00 ERROR : no such account number!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number : 1000
please enter the code : 1000
08 : 00 : 20        account # : 1000 balance : 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number : 1000
please enter the code : 1000
enter the amount of the check : 8900
08 : 00 : 50        account # : 1000 new balance : 8900
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
3
please enter account number : 1000
please enter the code : 1000
enter the amount of money to withdraw : 345
08 : 01 : 40        account # : 1000 new balance : 8555
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number : 1003
please enter the code : 1003
enter the amount of the check : 7800
08 : 02 : 10        account # : 1003 new balance : 7800
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
4
08:03 : 10        sum of all deposits : 16700
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
5
08:04 : 10        sum of all withdraws : 345
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
0
**/


