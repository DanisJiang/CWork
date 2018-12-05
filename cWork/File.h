#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"List.h"
#include"GLOBAL.h"

/*
*@method: ��ʼ��ͼ��������������ʱ��
*@param: ��
*@return: ͼ�������ͷָ��
*@others:
*/
PNode initializeBook()
{
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	TYPE type;  // ͼ������
	FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "r");
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("����ʧ��!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	fscanf(xlsBook, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");  //  ��ת���ڶ���
	for (int i = 1; i <= 2; i++) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("����ʧ��!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(pBook)); //�����鱾
		fscanf(xlsBook, "%s\t%s\t%s\t%d\t%s\t%s\t%lf\t%d\n", name, author, ID, &count, publisher, date, &price, &type);
		createBook(pNew->book, ID, name, author, count, price, date, type, publisher);
		printf("��ӳɹ�!\n");
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
	}

	fclose(xlsBook);

	return head;
}