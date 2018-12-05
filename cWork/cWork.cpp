#include "pch.h"
#include <stdio.h>
#include "List.h"
#include "init.h"
//#include "File.h"

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
		printf("%s %s %s %d %s %s %lf %d\n", name, author,
			ID, count, publisher, date, price, type);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
	}

	fclose(xlsBook);

	return head;
}

int main()
{
	//Init();
	PNode head, p;
	head = initializeBook();
	p = head->next;
	printf("%s %s %s %d %s %s %lf %d\n", p->book->name, p->book->author,
		p->book->ID, p->book->count, p->book->publisher, p->book->date, p->book->price, p->book->type);
	p = p->next;
	printf("%s %s %s %d %s %s %lf %d\n", p->book->name, p->book->author,
		p->book->ID, p->book->count, p->book->publisher, p->book->date, p->book->price, p->book->type);

	
}
