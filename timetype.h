#pragma once
#include"time.h"


//����ͨ��ʱ�࣬���캯��Ϊ���֣�Ĭ����ʹ�õ�ǰʱ�䣬Ҳ�ɽ��и�ֵ�����������գ�ʱ����(ע����������ʱ���������ͣ�����Ҫת������ʱӦ�ȸ�Ϊdouble��)
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
		tt = time(NULL); /*���time_t�ṹ��ʱ�䣬UTCʱ��*/
		localtime_s(&p, &tt); /*ת��Ϊstruct tm�ṹ��UTCʱ��*/
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

//�����������࣬����������ʣ���������ֵ��ΧΪ0-1��һ���ڵ�������
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

//����gpsʱ�࣬����������ʣ���������ֵ��ΧΪ0-1��һ���ڵ�������
class gpst
{
public:
	int week;
	double second;
	gpst(int mweek,double msecond) 
	{
		week = mweek;
		second = msecond; //һ����������ȡֵ��Χ��0-1
	}
private:

};

//����������࣬������ǰ��ݣ�������ʣ���������ֵ��ΧΪ0-1��һ���ڵ�������
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
		tt = time(NULL); /*���time_t�ṹ��ʱ�䣬UTCʱ��*/
		localtime_s(&p, &tt); /*ת��Ϊstruct tm�ṹ��UTCʱ��*/
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