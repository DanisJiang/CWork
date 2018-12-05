#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"List.h"
#include"GLOBAL.h"
#include<io.h>


/*
*@method: 初始化图书链表（有文件时）
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
PNode initializeBook()
{
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // 图书种类
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
	int i = 1;
	while(feof(xlsBook)==0){
	//for (int i = 1; i <= 2; i++) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(Book)); //创建书本
		fscanf(xlsBook, "%s\t%s\t%s\t%d\t%s\t%s\t%lf\t%d\n", name, author,
			ID, &count, publisher, date, &price, &type);
		createBook(pNew->book, ID, name, author, count, price, date, type, publisher);
		printf("第%d添加成功!\n",i);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		i++;
	}

	fclose(xlsBook);

	return head;
}

/*
*@method: 初始化程序
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
PNode intializeProgram()  // 需要补充——维护每本图书情况的数据（未完成）
{
	PNode bookHead;
	if (_access("xlsBook.xls", 0))  // 未查找到文件
	{
		bookHead = CreateNew();
	}
	else  // 查找到文件，录入
	{
		bookHead = initializeBook();
	}

	return bookHead;
}
