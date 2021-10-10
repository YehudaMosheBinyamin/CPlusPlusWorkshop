#include "Account.h"
#include <iostream>
using namespace std;
Account::Account()
{
    accountNumber = 0, code = 0, balance = 0.0f;
}

int Account::getAccountNumber()
{
    return accountNumber;
}

int Account::getCode()
{
    return code;
}


float Account::getBalance()
{
    return balance;
}

Account::Account(int accountNumber, int code)
{
    if (code < 999 || code>9999)
    {
        throw "ERROR: code must be of 4 digits!\n";
    }
    this->accountNumber = accountNumber;
    this->code = code;
    this->balance = 0.0f;
}

void Account::withdraw(float nis)
{

    try {
        if (nis > 2500)
        {
            throw "ERROR: cannot withdraw more than 2500 NIS!\n";
        }

        if (balance - nis < 6000)
        {
            throw "ERROR: cannot have less than - 6000 NIS!\n";
        }
        this->balance -= nis;
        sumWithdraw += nis;
    }
    catch (const char* errorMsg)
    {
        cout << errorMsg;
    }

}

void Account::deposit(float nis)
{
    try
    {
        if (nis > 10000)
        {
            throw "ERROR: cannot deposit more than 10000 NIS!\n";
        }
        balance += nis;
        sumDeposit += nis;
    }
    catch (const char* errorMsg)
    {
        cout << errorMsg;
    }
}


istream& operator>>(istream& s, Account& acc)
{
    s >> acc.accountNumber >> acc.code;
    if (acc.code < 999 || acc.code>9999)
        throw "ERROR: code must be of 4 digits!\n";
    return s;
}
