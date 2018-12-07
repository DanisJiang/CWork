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
	// 书本属性定义开始
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // 图书种类
	// 书本属性定义结束
	// 文件读取定义开始
	char *line, *record;
	char buffer[1024];
	// 文件读取定义结束
	FILE *csvBook;
	csvBook = fopen("Book.csv", "r");
	if (NULL == csvBook) {
		printf("文件读取失败\n");
		exit(-1);
	}
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	line = fgets(buffer, sizeof(buffer), csvBook);  // 跳过第一行
	int i = 0;
	while ((line = fgets(buffer, sizeof(buffer), csvBook)) != NULL) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL){
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(Book)); //创建书本
		record = strtok(line, ",");
		strcpy(pNew->book->name, record);
		record = strtok(line, ",");
		strcpy(pNew->book->author, record);
		record = strtok(line, ",");
		strcpy(pNew->book->ID, record);
		record = strtok(line, ",");  // 数量，需要转换
		record = strtok(line, ",");
		strcpy(pNew->book->publisher, record);
		record = strtok(line, ",");
		strcpy(pNew->book->date, record);
		record = strtok(line, ",");  // 价格，需要转换
		record = strtok(line, ",");  // 类型，需要转换
		record = strtok(line, ",");  // 剩余数量，需要转换
		record = strtok(line, ",");  // 总借出次数，需要转换
		for (int k = 0; k < MAXLENGTH; K++) {

		}
	}
	/*FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "r");
	if (NULL == xlsBook)
	{
		printf("文件读取失败\n");
		exit(0);
	}
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
		int temp[MAXLENGTH];
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
		printf("%d %s %d %s %d %s %d %s %d %s %d %s %d %s %d %s %d %s %d %s\n"
			, temp[0], pNew->book->info[0].ID
			, temp[1], pNew->book->info[1].ID
			, temp[2], pNew->book->info[2].ID
			, temp[3], pNew->book->info[3].ID
			, temp[4], pNew->book->info[4].ID
			, temp[5], pNew->book->info[5].ID
			, temp[6], pNew->book->info[6].ID
			, temp[7], pNew->book->info[7].ID
			, temp[8], pNew->book->info[8].ID
			, temp[9], pNew->book->info[9].ID);
		for (int j = 0; j < MAXLENGTH; j++) {
			pNew->book->info[j].available =(TYPE)temp[j] ;
		}
		printf("%s %s", name, author);
		createBook(pNew->book, ID, name, author, count, price, date, (TYPE)type, publisher);
		printf("第%d本书添加成功!\n",i);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		i++;
	}

	fclose(xlsBook);*/

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
	remove("xlsBook.csv");
	xlsBook = fopen("xlsBook.csv", "w");
	if (NULL == xlsBook)
	{
		printf("文件读取失败\n");
		exit(0);
	}
	fprintf(xlsBook, "书名,作者,编号,数量,出版商,发行日期,价格,类型,剩余数量,");
	fprintf(xlsBook, "总共借出次数,书1状态,书1ID,书2状态,");
	fprintf(xlsBook, "书2ID,书3状态,书3ID,书4状态,");
	fprintf(xlsBook, "书4ID,书5状态,书5ID,书6状态,书6ID,书7状态,书7ID,书8状态,");
	fprintf(xlsBook, "书8ID,书9状态,书9ID,书10状态,书10ID\n");  // 初始化表格文件
	PNode p = head->next;
	while (p != NULL)
	{
		fprintf(xlsBook, "%s,%s,%s,%d,%s,%s,%lf,%d,%d,%d,", p->book->name, p->book->author,
			p->book->ID, p->book->count, p->book->publisher, 
			p->book->date, p->book->price, p->book->type, p->book->left, p->book->total);
		int temp[MAX];
		for (int j = 0; j < MAX; j++) {
			temp[j] = (int)p->book->info[j].available;
		}
		fscanf(xlsBook, "%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s\n"
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

		
	}

	fclose(xlsBook);
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
		bookHead = Create();
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