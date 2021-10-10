#include <iostream>
using namespace std;
class Account
{
	int  accountNumber;
	/*Code of account. Must be unique, and 4 long*/
	int code;
	float balance;
public:
	/*Sum of all withdrawels of all customers*/
	static float sumWithdraw;
	/*Sum of all deposits of all customers*/
	static float sumDeposit;
	//Constructors
	Account();
	Account(int accountNumber, int code);
	/*Getters*/
	static float getSumWithdraw() { return sumWithdraw; }
	static float getSumDeposit() { return sumDeposit; }
	int getAccountNumber();
	int getCode();
	float getBalance();
	/**
	 * @brief Withdraws until 2500 from bank, if the person will have more than 6000 nis after this operation will be completed.
	 * @param nis 
	*/
	void withdraw(float nis);
	/**
	 * @brief Deposits up to 10000 nis to bank 
	 * @param nis 
	*/
	void deposit(float nis);
	/**
	 * @brief Receives account number and code from user.
	 * @param s 
	 * @param acc 
	 * @return s
	*/
	friend istream& operator>>(istream& s, Account& acc);
};

