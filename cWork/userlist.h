#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<Windows.h>
#include "GLOBAL.h"
#include "User.h"
#include"init.h"
#include"List.h"



/*
*@method: ���ѧ������
*@param:
*@return: ��
*@others:
*/
void newStudent(pPerson person, char ID[MAX], char name[MAX], char classes[MAX], char studentID[MAX],
	char password[MAX], int count, pBook borrow[BRORROW],int overTime) {
	strcpy(person->ID, ID);
	strcpy(person->name,name);
	strcpy(person->classes, classes);
	strcpy(person->studentID, studentID);
	strcpy(person->password, password);
	person->priority = 0;
	person->count=0;
	person->borrow[0] = NULL;
	person->borrow[1] = NULL;
	person->borrow[2] = NULL;
	person->borrow[3] = NULL;
	person->borrow[4] = NULL;
	person->overTime = 0;
}

/*
*@method: ��ӡѧ����Ϣ����
*@param: person:����ӡ��ѧ��
*@return: ��
*@others:
*/
void printStudent(pPerson person) {
	if (NULL == person) {
		printf("\n-------------------------------------------\n"); Sleep(10);
		printf("û����λͬѧ������\n"); Sleep(10);
		printf("(�����`)  (�����`)  (�����`)\n"); Sleep(10);
		printf("-------------------------------------------\n"); Sleep(10);
		return;
	}
	printf("-------------------------------------------\n"); Sleep(10);
	printf("����֤�ţ�%10s\n", person->ID); Sleep(10);
	printf("������%14s\n", person->name); Sleep(10);
	printf("�༶��%14s\n", person->classes); Sleep(10);
	printf("ѧ�ţ�%14s\n", person->studentID); Sleep(10);
	printf("���룺%14s\n", person->password); Sleep(10);
	printf("Ŀǰ����%d����\n", person->count); Sleep(10);
	//����Ҫ ��ʱ�鱾 ��Ҫ������
}

/*
*@method: ����ѧ������
*@param: studentHead��������������
*@return: ��
*@others:
*/
void studentTraverse(pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	int i = 1;
	if (p == NULL)
		printf("��ǰû��ѧ��������\n");
	while (p != NULL) {
		printf(">>>>>>>>>>>>>��%dλͬѧ<<<<<<<<<<<<\n", i);
		printStudent(p->person);
		p = p->next;
		i++;
	}
}

/*
*@method: ����ѧ��
*@param: studentList:�����������;
*@return:void
*@others: �޸�Ϊβ��
*/
void studentInsert(pPersonNode studentList) {
	char ID[MAX], name[MAX], classes[MAX], studentID[MAX], password[MAX];
	pPersonNode p = studentList;
	while (p->next != NULL) {
		p = p->next;
	}
	pPersonNode tmp = (pPersonNode)malloc(sizeof(pPersonNode));
	if (tmp == NULL) {
		printf("����ʧ�ܣ�\n");
		exit(-1);
	}
	//����ڵ�
	tmp->person = (pPerson)malloc(sizeof(Person));
	int id;
	sscanf(p->person->ID, "%d", &id);
	id++;
	_itoa(id, ID, 10);
	printf("���������֣�");
	scanf("%20s", name);
	printf("������༶��");
	scanf("%20s", classes);
	printf("������ѧ�ţ�");
	scanf("%20s", studentID);
	printf("���������룺");
	scanf("%20s", password);
	newStudent(tmp->person, ID, name, classes, studentID, password, 0, NULL, 0);
	tmp->next = p->next;
	p->next = tmp;
	printf("ע��ɹ�����ӭʹ��608-Library!!!\n");
	printStudent(p->next->person);
}
/*
*@method: ɾ��ָ��λ�õ�ѧ��
*@param: studentList:��ɾ����ͼ������;ID: ��ɾ����ѧ��ID���
*@return: Void
*@others:  �޸�Ϊ����IDɾ��ѧ��
*/
void studentDelete(pPersonNode studentList, char *ID) {
	pPersonNode p = studentList;
	while (p->next != NULL && strcmp(p->person->ID,ID)!= 0) {
		p->next;
	}
	printStudent(p->next->person);
	printf("ȷ��ɾ����\n");
	printf("1.�� 2.��\n");
	int i = 0;
	scanf("%d", &i);
	if (1 == i) {
		if (p->next->person->count > 0) {
			printf("��ѧ��������δ�黹��ɾ���˺�ʧ�ܣ�����\n");
			return;
		}
		pPersonNode tmp = p;
		p = p->next;
		tmp->next = p->next;
		free(p->person);
		free(p);
		printf("ɾ���˺ųɹ���\n");
	}
	else
		return;
}
/*
*@method: ���ѧ������
*@param: ����յ�����
*@return: ��
*@others:
*/
void studentClear(pPersonNode studentList) {
	pPersonNode p = studentList->next, tmp;
	while (p->next != NULL) {
		tmp = p->next;
		free(p->person);
		free(p);
		p = tmp;
	}
	printf("�˺��������\n");
}
/*
*@method: ����ͼ�麯��
*@param: studentList:������������;ID:������ͼ��ı��
*@return: ��������ͼ��ڵ�
*@others:
*/
pPerson SearchStudent(pPersonNode studentList, char *ID) {
	pPersonNode p = studentList->next;
	while (p != NULL && strcmp(p->person->ID, ID) != 0) {
		p = p->next;
	}
	if (p != NULL)
	{
		return p->person;
	}
	else {
		return NULL;
	}
}

/*
*@method: ����ѧ��������
*@param:
*@return: ѧ������ͷ�ڵ�
*@others:
*/
pPersonNode creatStudent() {
	pPersonNode head=(pPersonNode)calloc(1,sizeof(PersonNode));
	head->person = (pPerson)calloc(1, sizeof(Person));
	_itoa(0, head->person->ID, 10);
	head->next = NULL;
	return head;
}