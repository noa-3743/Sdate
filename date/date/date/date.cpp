// date.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CYider
{
protected:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	CYider();
	void exportYider();
	void addTime();
	int SetDate(int y, int m, int d, int h, int min, int s);
};
CYider::CYider()
{
	year = 2019;
	month = 1;
	day = 1;
	hour = 0;
	minute = 0;
	second = 0;
}
int CYider::SetDate(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	second = s;
	addTime();
	return 0;
}
void CYider::addTime()
{
	
	if (second > 60 || second < 1)
	{
		minute = minute + second / 60;
		second = second % 60;
	}
	if (minute > 60 || minute < 1)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}
	if (hour > 24 || hour < 1)
	{
		day = day + hour / 24;
		hour = hour % 24;
	}
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = day%31;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = day%30;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
void CYider::exportYider()
{
	cout << year << "年" << month << "月" << day << "日" << hour << "时" << minute << "分" << second << "秒" << endl;
}
class CTest :public CYider
{
public:
	CTest();
	void exportYider();
	void addTime();
	int SetDate(int y, int m, int d, int h, int min, int s);
}; 
CTest::CTest()
{
	year = 2019;
	month = 1;
	day = 1;
	hour = 0;
	minute = 0;
	second = 0;
}
int CTest::SetDate(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	second = s;
	addTime();
	return 0;
}
void CTest::addTime()
{

	if (second > 60 || second < 1)
	{
		minute = minute + second / 60;
		second = second % 60;
	}
	if (minute > 60 || minute < 1)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}
	if (hour > 24 || hour < 1)
	{
		day = day + hour / 24;
		hour = hour % 24;
	}
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = day % 31;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = day % 30;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
void CTest::exportYider()
{
	cout << year << "年" << month << "月" << day << "日" << hour << "时" << minute << "分" << second << "秒" << endl;
}
int main()
{
	CTest ob;
	ob.SetDate(2019, 13, 32, 25, 54, 71);
	ob.exportYider();
    return 0;
}

