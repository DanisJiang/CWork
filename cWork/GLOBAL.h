#pragma once
#include"Date.h"
/*全局变量及宏定义*/


#define MAX 20			//最长名字字段
#define MAXLENGTH 10	//最多存放图书
#define MAXPERSON 20	//最多学生数量
#define BORROW 5		//学生最多借阅图书本数
#define TIME 30			//单次借阅最长事件
#define RENEWTIMES 2	//单本图书最长续借次数

/*
状态变量
*/
#define LOGINSTU 1		//学生登录
#define LOGINTEA 2		//教师登录
#define LOGOUT 0		//登出
#define EXIT -1			//退出系统


/*
其他
*/
typedef enum TYPE{  //图书种类枚举
	BOOK,PERIODICAL,PRESS
}TYPE;

/*
日期
*/
struct tm {
	int tm_mday;      /* 一个月中的日期 - 取值区间为[1,31] */
	int tm_mon;       /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int tm_year;      /* 年份，其值等于实际年份减去1900 */
	int tm_yday;	  /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
};

int bookID = 0; 
date today;