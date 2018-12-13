#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"userlist.h"
#include "List.h"
#include "GLOBAL.h"
#include"Date.h"



//����Ա��Ϣ
typedef struct Admin {
	char ID[MAX];
	char name[MAX];
	char password[MAX];
	int priority;
}Admin;

typedef struct borrow {
	char ID[MAX];
	date borrowTime;
};

//�û���Ϣ
typedef struct Person {
	int priority;  //���ȼ�
	char ID[MAX];  //�û�ID
	char name[MAX];  //�û�����
	char classes[MAX];  //�û��༶
	char studentID[MAX];  //ѧ��
	char password[MAX];  //�û�����
	int count;		//�û��ѽ���Ŀ
	borrow borrowBook[BORROW];  //�û������鱾����

	int overTime;	//��ʱ�鱾
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
*@method: ��ӡ����Ա��Ϣ
*@param:
*@return:
*@others:
*/
void printAdmin(Admin* Admin) {
	printf("-----------------------------\n");
	printf("ID��%3s\n", Admin->ID);
	printf("������%3s\n", Admin->name);
	printf("���룺%s\n", Admin->password);
	printf("-----------------------------\n");
}


/*
*@method: ��ӡѧ����Ϣ
*@param:
*@return:
*@others:
*/
void printPerson(pPerson person) {
	printf("-----------------------------\n");
	printf("ID:%3s\n", person->ID);
	printf("����:%3s\n", person->name);
	printf("�ѽ����鱾:%3d\n", person->count);
	printf("�ɽ����鱾:%3d\n", BORROW - person->count);
	printf("���ĳ�ʱ�鱾:%3d\n", person->overTime);
	printf("------------------------------\n");
}
/*
*@method: ѧ����¼ϵͳ����
*@param:
*@return:
*@others:
*/
bool studentLogin(char*ID, char*password, pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	while (p->next != NULL && strcmp(p->next->person->ID, ID))
		p = p->next;
	if (p != NULL) {
		if (strcmp(p->person->password, password)==0) {
			printf("��¼�ɹ�!\n");
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
/*
*@method: ����Ա��¼ϵͳ����
*@param:
*@return:
*@others:
*/
bool adminLogin(char* ID, char*password) {

	for (int i = 0; i < lengthT; i++) {
		if ((strcmp(Admins[i].ID, ID) || strcmp(Admins[i].password, password)) == 0) {
			printf("��¼�ɹ�!\n");
			return true;
		}
	}
	return false;
}


/*
*@method: ��ȡ�û���index
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
		printf("δ�ҵ�\n");
		return -1;
	}
	else if (strcmp(type, "tea") == 0) {
		for (int i = 0; i < lengthT; i++) {
			if (strcmp(Admins[i].ID, ID) == 0) {
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
*@param: index:�û����(����ѧ��);book:�����鱾
*@return:
*@others:
*/
void Borrow(pPerson person, pBook book) {
	extern date today;
	int k = 0;
	while (strcmp(person->borrowBook[k].ID, "0")) {
		if (k > BORROW) {
			printf("�����ڽ����鼮���������ɽ��ģ�\n");
			return;
		}
			
			k++;
	}
	strcpy(person->borrowBook[k].ID, book->ID);
	person->borrowBook[k].borrowTime = today;
	book->left--;
	book->total++;
	int t = book->count - book->left;
	for (int i = 0; i <t; i++) {
		if (book->info[i].available==true)
		{
			strcpy(book->info[i].ID, person->ID);
			book->info[i].available = false;
			book->info[i].borrowDate = today;
			break;
		}
	}
	person->count++;
	printf("���ĳɹ�,�鱾ʣ��%d\n", book->left);
}


/*
*@method: ����
*@param:person: ������û�;ID:�������ID
*@return: �����Ƿ�ɹ�
*@others:
*/
bool returnBook(pPerson person, char ID[MAX], PNode bookList) {
	pBook book = SearchBook(bookList, ID);
	int i = 0;
	while (strcmp(book->info[i].ID, person->ID)) {
		i++;
		if (i > MAXLENGTH) {
			printf("��û�н��Ĵ��飡\n");
			return false;
		}
	}
	i--;
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
	person->borrowBook[k].borrowTime = { 0,0,0 };
	strcpy(person->borrowBook[k].ID, "0");
	return true;
}