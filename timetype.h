#pragma once
#include"time.h"


//定义通用时类，构造函数为两种，默认是使用当前时间，也可进行赋值，包含年月日，时分秒(注意的是这里的时分是整数型，后面要转换成秒时应先改为double型)
class ut 
{
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	double second;
	ut() 
	{
		time_t tt;
		struct tm  p;
		tt = time(NULL); /*获得time_t结构的时间，UTC时间*/
		localtime_s(&p, &tt); /*转换为struct tm结构的UTC时间*/
		year = p.tm_year + 1900;
		month = p.tm_mon + 1;
		day = p.tm_mday;
		hour = p.tm_hour;
		minute = p.tm_min;
		second = p.tm_sec;
	}
	ut(int myear,int mmonth,int mday,int mhour,int mminute,double msecond)
	{
		year = myear;
		month = mmonth;
		day = mday;
		hour = mhour;
		minute = mminute;
		second = msecond;
	}
private:

};

//定义儒略日类，包含天数和剩余的秒数（值范围为0-1，一天内的秒数）
class jdt
{
public:
	int day;
	double second;
	jdt(int mday, double msecond)
	{
		day = mday;
		second = msecond;
	}
private:

};

//定义gps时类，包含周数和剩余的秒数（值范围为0-1，一周内的秒数）
class gpst
{
public:
	int week;
	double second;
	gpst(int mweek,double msecond) 
	{
		week = mweek;
		second = msecond; //一周内秒数，取值范围是0-1
	}
private:

};

//定义年纪日类，包含当前年份，天数和剩余的秒数（值范围为0-1，一天内的秒数）
class act
{
public:
	int year;
	int day;
	double second;
	act() 
	{
		time_t tt;
		struct tm  p;
		tt = time(NULL); /*获得time_t结构的时间，UTC时间*/
		localtime_s(&p, &tt); /*转换为struct tm结构的UTC时间*/
		day = p.tm_yday;
		year = p.tm_year + 1900;
		second = double(p.tm_sec)/3600/24+double(p.tm_min)/60/24+double(p.tm_hour)/24;
	}
	act(int mday, int myear, double msecond) 
	{
		day = mday;
		year = myear;
		second = msecond;
	}
private:

};