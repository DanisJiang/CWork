#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"List.h"
#include"GLOBAL.h"

/*
*@method: 初始化图书链表（程序启动时）
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
PNode initializeBook()
{
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	TYPE type;  // 图书种类
	FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "r");
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	fscanf(xlsBook, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");  //  跳转至第二行
	for (int i = 1; i <= 2; i++) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(pBook)); //创建书本
		fscanf(xlsBook, "%s\t%s\t%s\t%d\t%s\t%s\t%lf\t%d\n", name, author, ID, &count, publisher, date, &price, &type);
		createBook(pNew->book, ID, name, author, count, price, date, type, publisher);
		printf("添加成功!\n");
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
	}

	fclose(xlsBook);

	return head;
}