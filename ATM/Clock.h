#pragma once
#include <iostream>
using namespace std;
class Clock
{/*Hour, from 0 to 23*/
	int hour;
	/*Minute, from 0 to 59*/
	int minute;
	/*Second, from 0 to 59*/
	int second;
public:
	/*Constructors*/
	Clock();
	Clock(int hour, int minute=0, int second=0);
	Clock(const Clock& other);
	Clock operator+=(int seconds);
	/*Getters and Setters*/
	int setHour(int hour);
	int getHour();
	void setMinute(int minute);
	int getMinute();
	void setSecond(int second);
	int getSecond();
	/*Prints time in 00:00:00 format*/
	friend ostream& operator<<(ostream &C_out, Clock &z);
	/*Receives time from user*/
	friend istream& operator>>(istream &C_in, Clock &z);
};