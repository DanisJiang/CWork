#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include "GLOBAL.h"


//��ʦ��Ϣ
typedef struct Teacher {
	char ID[MAX];
	char name[MAX];
	int priority;
}Teacher;


//ѧ����Ϣ
typedef struct Person {
	int priority;  //���ȼ�
	char ID[MAX];  //ѧ��ID
	char name[MAX];  //ѧ������
	int count;		//ѧ���ѽ���Ŀ
	pBook borrow[BRORROW];  //ѧ�������鱾����
	int overTime;	//��ʱ�鱾
}Person,*pPerson;


int length = 5;
Person persons[5] = {
	{1,"1","Jack",0},
	{1,"2","Tom",0},
	{1,"3","Bruce",0},
	{1,"4","Alex",0},
	{1,"5","JQY",0}
};


int lengthT = 1;
Teacher teachers[1] = {
	{"1","Tea1",0}
};


/*
*@method: ��ӡ��ʦ��Ϣ
*@param:
*@return:
*@others:
*/
void printTeacher(int index) {
	Teacher teacher = teachers[index];
	printf("-----------------------------\n");
	printf("ID:%3s\n", teacher.ID);
	printf("����:%3s\n", teacher.name);
	printf("-----------------------------\n");
}


/*
*@method: ��ӡѧ����Ϣ
*@param:
*@return:
*@others:
*/
void printPerson(int index) {
	printf("-----------------------------\n");
	printf("ID:%3s\n", persons[index].ID);
	printf("����:%3s\n", persons[index].name);
	printf("�ѽ����鱾:%3d\n", persons[index].count);
	printf("�ɽ����鱾:%3d\n",BRORROW-persons[index].count);
	printf("���ĳ�ʱ�鱾:%3d\n", persons[index].overTime);
	printf("------------------------------\n");
}


/*
*@method: ��¼ϵͳ����
*@param:
*@return:
*@others:
*/
bool Login(char* ID,const char* type) {
	if (strcmp(type,"stu")==0)
	{
		for (int i = 0; i < length; i++) {
			if (strcmp(persons[i].ID, ID) == 0) {
				printf("��¼�ɹ�!\n");
				return true;
			}
		}
		return false;
	}
	else if (strcmp(type, "tea") == 0) {
		for (int i = 0; i < lengthT; i++) {
			if (strcmp(teachers[i].ID, ID) == 0) {
				printf("��¼�ɹ�!\n");
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}


/*
*@method: ��ȡ�����û�
*@param:
*@return:
*@others:
*/
int getIndex(char* ID,const char type[]) {
	if (strcmp(type,"stu")==0)
	{
		for (int i = 0; i < length; i++) {
			if (strcmp(persons[i].ID, ID) == 0) {
				return i;
			}
		}
		printf("δ�ҵ�\n");
		return -1;
	}
	else if (strcmp(type, "tea") == 0) {
		for (int i = 0; i < lengthT; i++) {
			if (strcmp(teachers[i].ID, ID) == 0) {
				return i;
			}
		}
		printf("δ�ҵ�\n");
		return -1;
	}
	else {
		return -1;
	}
}


/*
*@method: ����
*@param:
*@return:
*@others:
*/
void Borrow(int index, pBook book) {
	Person person = persons[index];
	person.borrow[person.count] = book;
	book->left--;
	person.count++;
	printf("���ĳɹ�,�鱾ʣ��%d\n",book->left);
}


/*
*@method: ����
*@param:
*@return:
*@others:
*/
bool returnBook(Person person,char ID[]) {
	for (int i = 0; i < person.count; i++) {
		pBook book = person.borrow[i];
		if (book->ID==ID)
		{
			book->left++;
			person.count--;
			person.borrow[i] = NULL;
			return true;
		}
	}
	return false;
}