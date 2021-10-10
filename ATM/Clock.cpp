#include "Clock.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructors
Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Clock::Clock(int hour, int minute, int second)
{

	try {
		this->hour = hour;
		if (this->hour < 0)
		{
			throw "Invalid time - negative number of hours.";
		}
		if (this->hour > 24)
		{
			throw "Invalid time-more than 24 hours.";
		}

		this->minute = minute;
		if (this->minute < 0)
		{
			throw "Invalid time - negative number of minutes.";
		}
		if (this->minute > 60)
		{
			throw "Invalid time - more than 60 minutes.";
		}

		this->second = second;
		if (this->second > 60)
		{
			throw "Invalid time-more than 60 seconds.";
		}
		if (this->second < 0)
		{
			throw "invalid time-negative number of seconds.";
		}
		if (this->second == 60 || this->minute == 60 || this->hour == 24)
		{
			throw 1;
		}

	}

	catch (const char* errorMsg)
	{
		cout << errorMsg << endl;
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}

	catch (...)
	{
		cout << "Wrong time format." << endl;
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}
}

Clock::Clock(const Clock& other)
{
	this->hour = other.hour;
	this->minute = other.minute;
	this->second = other.second;
}
int Clock::setHour(int hour)
{
	try {
		this->hour = hour;
		if (this->hour < 0)
		{
			throw "Invalid time - negative number of hours.";
		}
		if (this->hour > 24)
		{
			throw "Invalid time-more than 24 hours.";
		}
		if (this->hour == 24)
		{
			throw 1;
		}

	}

	catch (const char* errorMsg)
	{
		cout << errorMsg << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}

	catch (...)
	{
		cout << "Wrong time format." << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}
}

int Clock::getHour()
{
	return hour;
}

void Clock::setMinute(int minute)
{
	try {
		

		this->minute = minute;
		if (this->minute < 0)
		{
			throw "Invalid time - negative number of minutes.";
		}
		if (this->minute > 60)
		{
			throw "Invalid time - more than 60 minutes.";
		}

		if (this->minute == 60)
		{
			throw 1;
		}

	}
	catch (const char* errorMsg)
	{
		cout << errorMsg << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}

	catch (...)
	{
		cout << "Wrong time format." << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}

}

int Clock::getMinute()
{
	return minute;
}

void Clock::setSecond(int second)
{

	try {
		this->second = second;
		if (this->second > 60)
		{
			throw "Invalid time-more than 60 seconds.";
		}
		if (this->second < 0)
		{
			throw "invalid time-negative number of seconds.";
		}
		if (this->second == 60)
		{
			throw 1;
		}

	}

	catch (const char* errorMsg)
	{
		cout << errorMsg << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}

	catch (...)
	{
		cout << "Wrong time format." << endl;
		hour = 0;
		minute = 0;
		second = 0;
	}
}

int Clock::getSecond()
{
	return second;
}

Clock Clock::operator+=(int seconds)
{
	second +=seconds;
	while(second > 59||minute>59||hour>23)
	{
		while(second > 59)
		{
			second = second - 60;
			minute++;
		}
		while(minute>59)
		{
			minute -=60;
			hour++;
		}
		while(hour > 23)
		{
			hour = hour - 24;
		}
	}
	return *this;
}

ostream& operator<<(ostream &C_out, Clock &z)
{
	C_out <<setfill('0')<<setw(2)<<z.hour << ":" << setfill('0') << setw(2)<< z.minute << ":" <<setfill('0') << setw(2) << z.second;
	return C_out;
}

istream& operator>>(istream &C_in, Clock &z)
{
	C_in >> z.hour >> z.minute >> z.second;
	try {
		if (z.hour < 0)
		{
			throw "Invalid time - negative number of hours.";
		}
		if (z.hour > 24)
		{
			throw "Invalid time-more than 24 hours.";
		}
		if (z.minute < 0)
		{
			throw "Invalid time - negative number of minutes.";
		}
		if (z.minute > 60)
		{
			throw "Invalid time - more than 60 minutes.";
		}
		if (z.second > 60)
		{
			throw "Invalid time-more than 60 seconds.";
		}
		if (z.second < 0)
		{
			throw "invalid time-negative number of seconds.";
		}
		if (z.second == 60 || z.minute == 60 || z.hour == 24)
		{
			throw 1;
		}

	}

	catch (const char* errorMsg)
	{
		cout << errorMsg << endl;
		z.hour = 0;
		z.minute = 0;
		z.second = 0;
	}

	catch (...)
	{
		cout << "Wrong time format." << endl;
		z.hour = 0;
		z.minute = 0;
		z.second = 0;
	}
	return C_in;
}

