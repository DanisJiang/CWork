#pragma once

#include <stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
/*int main(void)
{
	int isPrime(int year);
	int dateDiff(struct date mindate, struct date maxdate);
	struct date mindate, maxdate;
	int days;

	printf("please input the one date:");
	scanf("%i-%i-%i", &mindate.year, &mindate.month, &mindate.day);
	printf("please input other day:");
	scanf("%i-%i-%i", &maxdate.year, &maxdate.month, &maxdate.day);

	days = dateDiff(mindate, maxdate);
	printf("the day is:%d\n", days);
	return 0;
}*/

/************************************************************************/
/*    判断闰年函数(4年一润,100年不润,400年再润)                         */
/************************************************************************/
int isPrime(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int dateDiff(struct date mindate, struct date maxdate)
{
	int days = 0, flag = 1;
	const int primeMonth[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const int notPrimeMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	/************************************************************************/
	/*        交换两个日期函数,将小的日期给mindate,将大的日期给maxdate     */
	/************************************************************************/
	struct date tmp;
	if ((mindate.year > maxdate.year) || (mindate.year == maxdate.year&&mindate.month > maxdate.month) || (mindate.year == maxdate.year&&mindate.month == maxdate.month&&mindate.day > maxdate.day))
	{
		tmp = mindate;
		mindate = maxdate;
		maxdate = tmp;
	}

	int maxmonth, minmonth;
	/************************************************************************/
	/* 主要思路:拿2002-8-8   2005-2-22来说                                  */
	/*   将2004-8-8---2005-2-22----2005-7-8                                 */
	/*一前一后刚好N年,算出2005-2-22到2005-7-8的天数,然后用总年*36(5|6)减掉) */
	/*          2002-9-8      2005-11-22                                    */
	/*          2002-9-8-----2005-9-8-----2005-11-22(这次是加上后面天数)    */
	/*如何判断是加还是减呢?年大而月小的,则是减,程序中用flag标示             */
	/************************************************************************/
	if (maxdate.month < mindate.month)
	{
		maxmonth = mindate.month;
		minmonth = maxdate.month;
		flag = -1;
	}
	else
	{
		maxmonth = maxdate.month;
		minmonth = mindate.month;
		flag = 1;
	}

	/************************************************************************/
	/*  从mindate.year开始累加到maxdate.year                                */
	/************************************************************************/
	for (int j = mindate.year; j < maxdate.year; ++j)
	{
		if (isPrime(j) == 1)
		{
			days += 366;
		}
		else
			days += 365;
	}

	/************************************************************************/
	/* 从minmonth累加到maxmonth,分闰年和平年                                */
	/************************************************************************/
	int day;
	if (isPrime(maxdate.year) == 1)
	{

		for (int i = minmonth; i < maxmonth; i++)
		{
			day = primeMonth[i - 1] * flag;
			days = days + day;
		}
		days = days + maxdate.day - mindate.day;
	}
	else
	{
		for (int i = minmonth; i < maxmonth; i++)
		{
			day = notPrimeMonth[i - 1] * flag;
			days = days + day;
		}
		days = days + maxdate.day - mindate.day;
	}
	return days;
}