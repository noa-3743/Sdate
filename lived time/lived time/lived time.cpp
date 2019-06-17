// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
protected:
	int year;
	int month;
	int day;

public:
	CMyDate();
	CMyDate(int y, int m, int d);
};
CMyDate::CMyDate()
{
	year = 2019;
	month = 1;
	day = 1;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

class CTime :public CMyDate
{
public:
	CTime();
	CTime(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
	int check();
};
CTime::CTime()
{
	year = 2019;
	month = 1;
	day = 1;
}
CTime::CTime(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
	}

}
int CTime::setDate(int y, int m, int d)
{

	cout << "请输入你的生日:" << endl;
	cin >> year >> month >> day;
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}
	return 0;

}
void CTime::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CTime::check()
{
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
int CTime::getYear()
{
	return year;
}
int CTime::getMonth()
{
	return month;
}
int CTime::getDay()
{
	return day;
}
void CTime::addOneDay()
{
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
int main()
{
	CTime od;
	int i;
	int count = 1;
	od.setDate(2000, 1, 26);
	od.displayDate();
	while (!((od.getYear() == 2019) && (od.getMonth() == 6) && (od.getDay()) == 17))
	{
		od.addOneDay();
		count++;
	}
	cout << "您活了" << count << "年" << endl;
	return 0;
}