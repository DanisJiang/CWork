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
	// �鱾���Զ��忪ʼ
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // ͼ������
	// �鱾���Զ������
	// �ļ���ȡ���忪ʼ
	char *line, *record;
	char buffer[1024];
	// �ļ���ȡ�������
	FILE *csvBook;
	csvBook = fopen("Book.csv", "r");
	if (NULL == csvBook) {
		printf("�ļ���ȡʧ��\n");
		exit(-1);
	}
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("����ʧ��!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	line = fgets(buffer, sizeof(buffer), csvBook);  // ������һ��
	int i = 0;
	while ((line = fgets(buffer, sizeof(buffer), csvBook)) != NULL) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL){
			printf("����ʧ��!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(Book)); //�����鱾
		record = strtok(line, ",");
		strcpy(pNew->book->name, record);
		record = strtok(line, ",");
		strcpy(pNew->book->author, record);
		record = strtok(line, ",");
		strcpy(pNew->book->ID, record);
		record = strtok(line, ",");  // ��������Ҫת��
		record = strtok(line, ",");
		strcpy(pNew->book->publisher, record);
		record = strtok(line, ",");
		strcpy(pNew->book->date, record);
		record = strtok(line, ",");  // �۸���Ҫת��
		record = strtok(line, ",");  // ���ͣ���Ҫת��
		record = strtok(line, ",");  // ʣ����������Ҫת��
		record = strtok(line, ",");  // �ܽ����������Ҫת��
		for (int k = 0; k < MAXLENGTH; K++) {

		}
	}
	/*FILE *xlsBook;
	xlsBook = fopen("xlsBook.xls", "r");
	if (NULL == xlsBook)
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
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
		printf("��%d������ӳɹ�!\n",i);
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		i++;
	}

	fclose(xlsBook);*/

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
	remove("xlsBook.csv");
	xlsBook = fopen("xlsBook.csv", "w");
	if (NULL == xlsBook)
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
	fprintf(xlsBook, "����,����,���,����,������,��������,�۸�,����,ʣ������,");
	fprintf(xlsBook, "�ܹ��������,��1״̬,��1ID,��2״̬,");
	fprintf(xlsBook, "��2ID,��3״̬,��3ID,��4״̬,");
	fprintf(xlsBook, "��4ID,��5״̬,��5ID,��6״̬,��6ID,��7״̬,��7ID,��8״̬,");
	fprintf(xlsBook, "��8ID,��9״̬,��9ID,��10״̬,��10ID\n");  // ��ʼ������ļ�
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
		bookHead = Create();
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