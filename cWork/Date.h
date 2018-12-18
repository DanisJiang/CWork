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
/*    �ж����꺯��(4��һ��,100�겻��,400������)                         */
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
	/*        �����������ں���,��С�����ڸ�mindate,��������ڸ�maxdate     */
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
	/* ��Ҫ˼·:��2002-8-8   2005-2-22��˵                                  */
	/*   ��2004-8-8---2005-2-22----2005-7-8                                 */
	/*һǰһ��պ�N��,���2005-2-22��2005-7-8������,Ȼ��������*36(5|6)����) */
	/*          2002-9-8      2005-11-22                                    */
	/*          2002-9-8-----2005-9-8-----2005-11-22(����Ǽ��Ϻ�������)    */
	/*����ж��Ǽӻ��Ǽ���?������С��,���Ǽ�,��������flag��ʾ             */
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
	/*  ��mindate.year��ʼ�ۼӵ�maxdate.year                                */
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
	/* ��minmonth�ۼӵ�maxmonth,�������ƽ��                                */
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