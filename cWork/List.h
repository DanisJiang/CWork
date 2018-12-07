﻿#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include "GLOBAL.h"

typedef struct Info {
	char ID[MAX];
	int index;
	bool available;
}*pInfo, Info;

typedef struct BookTotal {

}BookTotal, *pBookTotal;
//图书信息
typedef struct Book {
	char ID[MAX];	//编号
	char name[MAX];  //图书名
	char author[MAX];	//作者
	int count;		//总库存
	int left;		//剩余数量
	double price;	//图书单价
	char date[MAX];	//出版日期
	TYPE type;   //图书分类
	char publisher[MAX];  //出版商
	int total;  //总共借出的次数
	Info info[MAXLENGTH];  //维护每一本图书借给了谁
}Book, *pBook;

//图书链表
typedef struct ListNode {
	pBook book;  //图书信息
	struct ListNode* next;
}Node, *PNode;


/*
*@method: 添加图书函数
*@param:
*@return: 无
*@others:
*/
void createBook(pBook book, char ID[MAX], char name[MAX], char author[MAX], int count, double price,
	char date[], TYPE type, char publisher[]) {
	strcpy(book->name, name);
	strcpy(book->ID, ID);
	strcpy(book->author, author);
	strcpy(book->publisher, publisher);
	strcpy(book->date, date);
	book->count = count;
	book->price = price;
	book->left = count;
	book->total = 0;
	book->type = type;
	for (int i = 0; i < count; i++) {
		book->info[i].available = true;
		strcpy(book->info[i].ID,"0") ;
	}
	for (int i = count; i < MAXLENGTH; i++) {
		book->info->available = false;
		strcpy(book->info[i].ID, "0");
	}
}
/*
*@method: 打印图书函数
*@param: book:待打印的图书
*@return: 无
*@others:
*/
void printBook(pBook book) {
	if (NULL == book) {
		printf("\n-------------------------------------------\n");
		printf("没有这本书！！！\n");
		printf("(；′⌒`)  (；′⌒`)  (；′⌒`)\n");
		printf("-------------------------------------------\n");
		return;
	}
	int t = book->count - book->left;
	printf("-------------------------------------------\n");
	printf("编号:%8s\n", book->ID);
	printf("书名:%8s\n", book->name);
	printf("作者:%8s\n", book->author);
	printf("价格:%8g\n", book->price);
	printf("出版商:%8s\n", book->publisher);
	printf("总量:%8d\n", book->count);
	printf("库存:%8d\n", book->left);
	printf("该书已借出%d次\n", book->total);
	for (int i = 0; i <t; i++) {
		if (book->info[i].available==false) {
			printf("第%d本书借给了ID为%s的同学\n", i + 1, book->info[i].ID);
		}
	}
	if (book->left > 0) {
		printf("可借阅\n");
	}
	else {
		printf("已借出\n");
	}
	printf("-------------------------------------------\n");
}
/*
*@method: 创建图书链表并初始化
*@param: 无
*@return: 创建的图书链表的头指针
*@others:
*/
PNode Create() {
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int len, count;
	double price;
	TYPE type;
	printf("请输入初始的书本:");
	scanf("%d", &len);
	PNode head = (PNode)calloc(1,sizeof(Node));
	if (head == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	for (int i = 1; i <= len; i++) {
		PNode pNew = (PNode)calloc(1,sizeof(Node));
		if (pNew == NULL)
		{
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->book = (pBook)calloc(1,sizeof(Book)); //创建书本
		printf("请输入第%d本书的书名", i);
		scanf("%s", name);
		printf("请输入第%d本书的作者", i);
		scanf("%s", author);
		printf("请输入第%d本书的编号", i);
		scanf("%s", ID);
		printf("请输入第%d本书的数量", i);
		scanf("%d", &count);
		printf("请输入第%d本书出版商", i);
		scanf("%s", publisher);
		printf("请输入第%d本书发行日期", i);
		scanf("%s", date);
		printf("请输入第%d本书价格", i);
		scanf("%lf", &price);
		printf("请输入第%d本书类型", i);
		scanf("%d", &type);
		createBook(pNew->book, ID, name, author, count, price, date, type, publisher);
		printf("第%d本书添加成功!\n", i);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
	}
	return head;
}
/*
*@method: 遍历图书链表
*@param: List：待遍历的链表
*@return: 无
*@others:
*/
void Traverse(PNode List) {
	PNode p = List->next;
	int i = 1;
	if (p == NULL)
		printf("当前目录为空\n");
	while (p != NULL)
	{
		printf(">>>>>>>>>>>>>第%d本书<<<<<<<<<<<<\n", i);
		printBook(p->book);
		p = p->next;
		i++;
	}
}
/*
*@method: 插入图书
*@param: List:带插入的链表;
*@return:void
*@others: 修改为尾插
*/
void Insert(PNode List) {
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int count;
	double price;
	TYPE type;
	int position = 0;
	PNode p = List;
	while (p->next != NULL)
	{
		p = p->next;
	}
	PNode tmp = (PNode)malloc(sizeof(PNode));
	if (tmp == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	//插入节点
	tmp->book = (pBook)malloc(sizeof(Book));
	printf("请输入书名");
	scanf("%s", name);
	printf("请输入书的作者");
	scanf("%s", author);
	printf("请输入书的编号");
	scanf("%s", ID);
	printf("请输入书的数量");
	scanf("%d", &count);
	printf("请输入书出版商");
	scanf("%s", publisher);
	printf("请输入书发行日期");
	scanf("%s", date);
	printf("请输入书价格");
	scanf("%lf", &price);
	printf("请输入书类型");
	scanf("%d", &type);

	createBook(tmp->book, ID, name, author, count, price, date, type, publisher);
	tmp->next = p->next;
	p->next = tmp;
	printf("图书添加成功!\n");
}
/*
*@method: 删除指定位置的图书
*@param: List:待删除的图书链表;ID: 待删除的图书ID编号
*@return: Void
*@others:  修改为根据ID删除图书
*/
void Delete(PNode List,char* ID) {
	PNode p = List;
	while (p != NULL && strcmp(p->book->ID,ID)!=0) {
		p = p->next;
	}
	//待删除节点
	PNode tmp = p->next;
	p->next = tmp->next;
	free(tmp);
	tmp = NULL;
	printf("图书删除成功!\n");
}
/*
*@method: 清空图书链表
*@param: 待清空的链表
*@return: 无
*@others:
*/
void Clear(PNode List) {
	PNode p = List->next, tmp;
	while (p != NULL) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
	printf("图书清理完成\n");
}
/*
*@method: 搜索图书函数
*@param: List:待搜索的链表;ID:待搜索图书的编号
*@return: 搜索到的图书节点
*@others:
*/
pBook SearchBook(PNode List, char* ID) {
	PNode p = List->next;
	while (p != NULL && strcmp(p->book->ID, ID) != 0) {
		p = p->next;
	}
	if (p != NULL)
	{
		return p->book;
	}
	else {
		return NULL;
	}
}