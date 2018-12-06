#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"List.h"
#include"GLOBAL.h"
#include<io.h>

/*
*@method: ��ʼ��ͼ���������ļ�ʱ��
*@param: ��
*@return: ͼ�������ͷָ��
*@others:
*/
PNode initializeBook()
{
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // ͼ������
	FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "r");
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("����ʧ��!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	fscanf(xlsBook, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");  // ������һ��
	int i = 1;
	while(feof(xlsBook)==0){
	//for (int i = 1; i <= 2; i++) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("����ʧ��!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(Book)); //�����鱾
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
		printf("��%d��ӳɹ�!\n",i);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		i++;
	}

	fclose(xlsBook);

	return head;
}

/*
*@method: ����ͼ���ļ��������˳�ʱ��
*@param: ͼ�������ͷָ��
*@return: ��
*@others:
*/
void saveBook(PNode head)
{
	FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "w");
	fprintf(xlsBook, "����\t����\t���\t����\t������\t��������\t�۸�\t����\tʣ������\t");
	fprintf(xlsBook,"�ܹ��������\t��1״̬\t��1ID\t��2״̬\t"
		, "��2ID\t��3״̬\t��3ID\t��4״̬\t");
	fprintf(xlsBook, "��4ID\t��5״̬\t��5ID\t��6״̬\t��6ID\t��7״̬\t��7ID\t��8״̬\t");
	fprintf(xlsBook, "��8ID\t��9״̬\t��9ID\t��10״̬\t��10ID\n");  // ��ʼ������ļ�
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
*@method: ��ʼ������
*@param: ��
*@return: ͼ�������ͷָ��
*@others:
*/
PNode intializeProgram()
{
	PNode bookHead;
	if (_access("xlsBook.xls", 0))  // δ���ҵ��ļ�
	{
		bookHead = CreateNew();
	}
	else  // ���ҵ��ļ���¼��
	{
		bookHead = initializeBook();
	}

	return bookHead;
}

/*
*@method: �˳�����
*@param: ͼ�������ͷָ��
*@return:
*@others:
*/
void closeProgram(PNode head)
{
	saveBook(head);
	Clear(head);
}