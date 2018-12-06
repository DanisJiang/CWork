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
	fscanf(xlsBook, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");  // 跳过第一行
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
		fscanf(xlsBook, "%s\t%s\t%s\t%d\t%s\t%s\t%lf\t%d\t%d\t%d\t", name, author,
			ID, &count, publisher, date, &price, &type,&pNew->book->left,&pNew->book->total);
		int temp[MAX];
		for (int j = 0; j < MAX; j++) {
			temp[j] = (int)pNew->book->info[j].available;
		}
		fscanf(xlsBook, "%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\n"
			, &temp[0], &pNew->book->info[0].ID
			, &temp[1], &pNew->book->info[1].ID
			, &temp[2], &pNew->book->info[2].ID
			, &temp[3], &pNew->book->info[3].ID
			, &temp[4], &pNew->book->info[4].ID
			, &temp[5], &pNew->book->info[5].ID
			, &temp[6], &pNew->book->info[6].ID
			, &temp[7], &pNew->book->info[7].ID
			, &temp[8], &pNew->book->info[8].ID
			, &temp[9], &pNew->book->info[9].ID
		);
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
*@method: 保存图书文件（程序退出时）
*@param: 图书链表的头指针
*@return: 无
*@others:
*/
void saveBook(PNode head)
{
	FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "w");
	fprintf(xlsBook, "书名\t作者\t编号\t数量\t出版商\t发行日期\t价格\t类型\t剩余数量\t");
	fprintf(xlsBook,"总共借出次数\t书1状态\t书1ID\t书2状态\t"
		, "书2ID\t书3状态\t书3ID\t书4状态\t");
	fprintf(xlsBook, "书4ID\t书5状态\t书5ID\t书6状态\t书6ID\t书7状态\t书7ID\t书8状态\t");
	fprintf(xlsBook, "书8ID\t书9状态\t书9ID\t书10状态\t书10ID\n");  // 初始化表格文件
	PNode p = head->next;
	while (p != NULL)
	{
		fprintf(xlsBook, "%s\t%s\t%s\t%d\t%s\t%s\t%lf\t%d\t%d\t%d\t", p->book->name, p->book->author,
			p->book->ID, p->book->count, p->book->publisher, 
			p->book->date, p->book->price, p->book->type, p->book->left, p->book->total);
		int temp[MAX];
		for (int j = 0; j < MAX; j++) {
			temp[j] = (int)p->book->info[j].available;
		}
		fscanf(xlsBook, "%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%s\n"
			, &temp[0], p->book->info[0].ID
			, &temp[1], p->book->info[1].ID
			, &temp[2], p->book->info[2].ID
			, &temp[3], p->book->info[3].ID
			, &temp[4], p->book->info[4].ID
			, &temp[5], p->book->info[5].ID
			, &temp[6], p->book->info[6].ID
			, &temp[7], p->book->info[7].ID
			, &temp[8], p->book->info[8].ID
			, &temp[9], p->book->info[9].ID
		);
		p = p->next;

		fclose(xlsBook);
	}


}

/*
*@method: 初始化程序
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
PNode intializeProgram()
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

/*
*@method: 退出程序
*@param: 图书链表的头指针
*@return:
*@others:
*/
void closeProgram(PNode head)
{
	saveBook(head);
	Clear(head);
}