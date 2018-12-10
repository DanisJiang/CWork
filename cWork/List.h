#pragma once
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<Windows.h>
#include "GLOBAL.h"

typedef struct Info {
	char ID[MAX];
	int index;
	bool available;
	struct tm time;
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
	for (int i = 0; i < MAXLENGTH; i++) {
		book->info[i].available = true;
		strcpy(book->info[i].ID,"0") ;
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
		printf("\n-------------------------------------------\n"); Sleep(10);
		printf("没有这本书！！！\n"); Sleep(10);
		printf("(；′⌒`)  (；′⌒`)  (；′⌒`)\n"); Sleep(10);
		printf("-------------------------------------------\n"); Sleep(10);
		return;
	}
	int t = book->count - book->left;
	printf("-------------------------------------------\n"); Sleep(10);
	printf("编号：%14s\n", book->ID); Sleep(10);
	printf("书名：%14s\n", book->name); Sleep(10);
	printf("类型：");
	switch (book->type)
	{
		case 0:
			printf("          书籍\n");
			break;
		case 1:
			printf("          期刊\n");
			break;
		case 2:
			printf("          报刊\n");
			break;
		default:
			break;
	}
	printf("作者：%14s\n", book->author); Sleep(10);
	printf("价格：%14g\n", book->price); Sleep(10);
	printf("出版商：%12s\n", book->publisher); Sleep(10);
	printf("总量：%14d\n", book->count); Sleep(10);
	printf("库存：%14d\n", book->left); Sleep(10);
	printf("该书已借出%d次\n", book->total); Sleep(10);
	for (int i = 0; i <t; i++) {
		if (book->info[i].available==false) {
			printf("第%d本书借给了ID为%s的同学\n", i + 1, book->info[i].ID); Sleep(10);
		}
	}
	if (book->left > 0) {
		printf("可借阅\n"); Sleep(10);
	}
	else {
		printf("已借出\n"); Sleep(10);
	}
	printf("-------------------------------------------\n"); Sleep(10);
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
		printf("请输入第%d本书的书名：", i);
		scanf("%s", name);
		printf("请输入第%d本书的作者：", i);
		scanf("%s", author);
		printf("请输入第%d本书的编号：", i);
		scanf("%s", ID);
		printf("请输入第%d本书的数量：", i);
		scanf("%d", &count);
		printf("请输入第%d本书出版商：", i);
		scanf("%s", publisher);
		printf("请输入第%d本书发行日期：", i);
		scanf("%s", date);
		printf("请输入第%d本书价格：", i);
		scanf("%lf", &price);
		printf("请输入第%d本书类型：", i);
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
		printf("当前目录为空！！！\n");
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
		printf("分配失败！\n");
		exit(-1);
	}
	//插入节点
	tmp->book = (pBook)malloc(sizeof(Book));
	printf("请输入书名：");
	scanf("%s", name);
	printf("请输入书的作者：");
	scanf("%s", author);
	printf("请输入书的编号：");
	scanf("%s", ID);
	printf("请输入书类型：(书籍——0；期刊——1；报刊——2）");
	scanf("%d", &type);
	printf("请输入书的数量：");
	scanf("%d", &count);
	printf("请输入书出版商：");
	scanf("%s", publisher);
	printf("请输入书发行日期：");
	scanf("%s", date);
	printf("请输入书价格：");
	scanf("%lf", &price);

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
	while (p->next != NULL && strcmp(p->next->book->ID,ID)!=0) {
		p = p->next;
	}
	printBook(p->next->book);
	printf("确认删除？\n");
	printf("1.是 2.否\n");
	int i = 0;
	scanf("%d", &i);
	if (1 == i) {
		PNode tmp = p;
		p = p->next;
		tmp->next = p->next;
		free(p->book);
		free(p);
		printf("图书删除成功!\n");
	}
	else
		return;
}
/*
*@method: 清空图书链表
*@param: 待清空的链表
*@return: 无
*@others:
*/
void Clear(PNode List) {
	PNode p = List->next, tmp;
	while (p->next != NULL) {
		tmp = p->next;
		free(p->book);
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