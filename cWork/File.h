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
		record = strtok(NULL, ",");
		strcpy(pNew->book->author, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->ID, record);
		record = strtok(NULL, ",");  // 数量，需要转换
		sscanf(record, "%d", &pNew->book->count);
		record = strtok(NULL, ",");
		strcpy(pNew->book->publisher, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->date, record);
		record = strtok(NULL, ",");  // 价格，需要转换
		sscanf(record, "%lf", &pNew->book->price);
		record = strtok(NULL, ",");  // 类型，需要转换
		sscanf(record, "%d", &pNew->book->type);
		record = strtok(NULL, ",");  // 剩余数量，需要转换
		sscanf(record, "%d", &pNew->book->left);
		record = strtok(NULL, ",");  // 总借出次数，需要转换
		sscanf(record, "%d", &pNew->book->total);
		for (int k = 0; k < MAXLENGTH; k++) {
			record = strtok(NULL, ",");  // 状态
			sscanf(record, "%d", &pNew->book->info[k].available);
			record = strtok(NULL, ",");  // ID
			strcpy(pNew->book->info[k].ID, record);
		}
		int temp = strlen(pNew->book->info[9].ID)-1;
		pNew->book->info[9].ID[temp] = '\0';
		record = strtok(NULL, ",");
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		i++;
	}

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
	FILE *csvBook;
	remove("Book.csv");
	csvBook = fopen("Book.csv", "w");
	if (NULL == csvBook)
	{
		printf("文件读取失败\n");
		exit(0);
	}
	fprintf(csvBook, "书名,作者,编号,数量,出版商,发行日期,价格,类型,剩余数量,");
	fprintf(csvBook, "总共借出次数,书1状态,书1ID,书2状态,");
	fprintf(csvBook, "书2ID,书3状态,书3ID,书4状态,");
	fprintf(csvBook, "书4ID,书5状态,书5ID,书6状态,书6ID,书7状态,书7ID,书8状态,");
	fprintf(csvBook, "书8ID,书9状态,书9ID,书10状态,书10ID\n");  // 初始化表格文件
	PNode p = head->next;
	int i = 0;
	while (p != NULL)
	{
		fprintf(csvBook, "%s,%s,%s,%d,%s,%s,%lf,%d,%d,%d,", p->book->name, p->book->author,
			p->book->ID, p->book->count, p->book->publisher, 
			p->book->date, p->book->price, p->book->type, p->book->left, p->book->total);
		int temp[MAX];
		for (int j = 0; j < MAX; j++) {
			temp[j] = (int)p->book->info[j].available;
		}
		fprintf(csvBook, "%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s,%d,%s\n"
			, temp[0], p->book->info[0].ID
			, temp[1], p->book->info[1].ID
			, temp[2], p->book->info[2].ID
			, temp[3], p->book->info[3].ID
			, temp[4], p->book->info[4].ID
			, temp[5], p->book->info[5].ID
			, temp[6], p->book->info[6].ID
			, temp[7], p->book->info[7].ID
			, temp[8], p->book->info[8].ID
			, temp[9], p->book->info[9].ID
		);
		p = p->next;
		i++;
		
	}
	printf("已成功保存%d本书！\n", i);

	fclose(csvBook);
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
	if (_access("Book.csv", 0))  // 未查找到文件
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
	saveBook(head); Sleep(200);
	Clear(head); Sleep(200);
}