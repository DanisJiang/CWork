#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"userlist.h"
#include "List.h"
#include "GLOBAL.h"
#include"Date.h"



//管理员信息
typedef struct Admin {
	char ID[MAX];
	char name[MAX];
	char password[MAX];
	int priority;
}Admin;

typedef struct borrow {
	char ID[MAX];
	date borrowTime;
	int DDL;
};

//用户信息
typedef struct Person {
	int priority;  //优先级
	char ID[MAX];  //用户ID
	char name[MAX];  //用户姓名
	char classes[MAX];  //用户班级
	char studentID[MAX];  //学号
	char password[MAX];  //用户密码
	int count;		//用户已借书目
	borrow borrowBook[BORROW];  //用户借阅书本集合

	int overTime;	//超时书本
}Person, *pPerson;

typedef struct PersonNode {
	pPerson person;
	struct PersonNode* next;
}personNode, *pPersonNode;

int length = 5;
Person persons[100];


int lengthT = 1;
Admin Admins[1] = {
	{"1","Master","123456",0}
};


/*
*@method: 打印管理员信息
*@param:
*@return:
*@others:
*/
void printAdmin(Admin* Admin) {
	printf("-----------------------------\n");
	printf("ID：%3s\n", Admin->ID);
	printf("姓名：%3s\n", Admin->name);
	printf("密码：%s\n", Admin->password);
	printf("-----------------------------\n");
}


/*
*@method: 打印学生信息
*@param:
*@return:
*@others:
*/
void printPerson(pPerson person,PNode List) {
	extern double penalty;
	extern int DDLTime;
	double money = 0;
	printf("-----------------------------\n");
	printf("ID:%3s\n", person->ID);
	printf("姓名:%3s\n", person->name);
	printf("已借阅书本:%3d\n", person->count);
	printf("可借阅书本:%3d\n", BORROW - person->count);
	printf("借阅超时书本:%3d\n", person->overTime);
	printf("-----------------------------\n");
	for (int i = 0; i < BORROW; i++) {
		if (person->borrowBook[i].DDL == 1) {
			printf("超时书本ID：%s\n", person->borrowBook[i].ID);
			printf("借阅时间：%d/%d/%d\n", person->borrowBook[i].borrowTime.year, person->borrowBook[i].borrowTime.month, person->borrowBook[i].borrowTime.day);
			PNode p = List->next;
			while (p != NULL) {
				if (strcmp(person->borrowBook[i].ID, p->book->ID) == 0) {
					money = p->book->price*penalty*(dateDiff(person->borrowBook[i].borrowTime, today) - DDLTime);
					printf("需罚款：%g\n", money);
					break;
				}
			}
		}
		else if (person->borrowBook[i].borrowTime.year != 0)
		{
			printf("未超时书本ID:%s\n", person->borrowBook[i].ID);
			printf("借阅时间：%d/%d/%d\n", person->borrowBook[i].borrowTime.year, person->borrowBook[i].borrowTime.month, person->borrowBook[i].borrowTime.day);
		}
	}
	printf("------------------------------\n");
}
/*
*@method: 学生登录系统函数
*@param:
*@return:
*@others:
*/
bool studentLogin(char*ID, char*password, pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	while (p != NULL && strcmp(p->person->ID, ID))
		p = p->next;
	if (p != NULL) {
		if (strcmp(p->person->password, password)==0) {
			printf("登录成功!\n");
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
/*
*@method: 管理员登录系统函数
*@param:
*@return:
*@others:
*/
bool adminLogin(char* ID, char*password) {

	for (int i = 0; i < lengthT; i++) {
		if ((strcmp(Admins[i].ID, ID) || strcmp(Admins[i].password, password)) == 0) {
			printf("登录成功!\n");
			return true;
		}
	}
	return false;
}


/*
*@method: 获取用户的index
*@param:
*@return:
*@others:
*/
int getIndex(char* ID, const char type[]) {
	if (strcmp(type, "stu") == 0)
	{
		for (int i = 0; i < length; i++) {
			if (strcmp(persons[i].ID, ID) == 0) {
				return i;
			}
		}
		printf("未找到\n");
		return -1;
	}
	else if (strcmp(type, "tea") == 0) {
		for (int i = 0; i < lengthT; i++) {
			if (strcmp(Admins[i].ID, ID) == 0) {
				return i;
			}
		}
		printf("未找到\n");
		return -1;
	}
	else {
		return -1;
	}
}


/*
*@method: 借书
*@param: index:用户序号(不是学号);book:待借书本
*@return:
*@others:
*/
void Borrow(pPerson person, pBook book) {
	extern date today;
	int k = 0;
	while (strcmp(person->borrowBook[k].ID, "0")) {
		if (k > BORROW) {
			printf("你现在借阅书籍已满，不可借阅！\n");
			return;
		}
			
			k++;
	}
	strcpy(person->borrowBook[k].ID, book->ID);
	person->borrowBook[k].borrowTime = today;
	person->borrowBook[k].DDL = 0;
	book->left--;
	book->total++;
	int t = book->count - book->left;
	for (int i = 0; i <t; i++) {
		if (book->info[i].available==true)
		{
			strcpy(book->info[i].ID, person->ID);
			book->info[i].available = false;
			book->info[i].borrowDate = today;
			person->count++;
			printf("借阅成功,书本剩余%d\n", book->left);
			return;
		}
	}
	printf("借书失败！\n");
}


/*
*@method: 还书
*@param:person: 还书的用户;ID:待还书的ID
*@return: 还书是否成功
*@others:
*/
bool returnBook(pPerson person, char ID[MAX], PNode bookList) {
	pBook book = SearchBook(bookList, ID);
	if (book == NULL) {
		printf("\n-------------------------------------------\n"); Sleep(10);
		printf("没有这本书！！！\n"); Sleep(10);
		printf("(；′⌒`)  (；′⌒`)  (；′⌒`)\n"); Sleep(10);
		printf("-------------------------------------------\n"); Sleep(10);
		return false;
	}
	int i = 0;
	while (strcmp(book->info[i].ID, person->ID)) {
		i++;
		if (i > MAXLENGTH) {
			printf("你没有借阅此书！\n");
			return false;
		}
	}
	book->info[i].available = true;
	strcpy(book->info[i].ID, "0");
	book->info[i].borrowDate.year = 0;
	book->info[i].borrowDate.month = 0;
	book->info[i].borrowDate.day = 0;
	book->left++;
	person->count--;
	int k = 0;
	while (strcmp(person->borrowBook[k].ID, ID)) {
		k++;
	}
	if (person->borrowBook[k].DDL == 1)
		printf("图书借阅超时！需要罚款——%g 元\n", book->price*penalty*(dateDiff(person->borrowBook[i].borrowTime, today) - DDLTime));
	person->borrowBook[k].borrowTime = { 0,0,0 };
	strcpy(person->borrowBook[k].ID, "0");
	return true;
}