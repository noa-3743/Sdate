// date.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CYider
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int check();
public:
	CYider();
	//int setYider(int y, int m, int d, int h, int min, int s);
	void exportYider();
	void addTime();
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
/*int CYider::setYider(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	second = s;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
		cout << "时间错误，已重至为初始值" << endl;
		return -1;
	}
	return 0;
}*/
int CYider::check()
{
	second = second + second % 60;
	minute = minute%60 + second / 60;
	hour = hour % 24 + minute / 60;
	day = day + hour / 24;
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
void CYider::addTime()
{
	second = second + second % 60;
	minute = minute % 60 + second / 60;
	hour = hour % 24 + minute / 60;
	day = day + hour / 24;
	if (second > 60 || second < 1)
	{
		second = second % 60;
		minute = minute % 60 + second / 60;
	}
	if (minute > 60 || minute < 1)
	{
		minute = minute % 60;
		hour = hour % 24 + minute / 60;
	}
	if (hour > 24 || hour < 1)
	{
		hour = hour % 24;
		day = day + hour / 24;
	}
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
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
int main()
{
	CYider ob;
	int count = 1;
	ob.exportYider();
    return 0;
}

