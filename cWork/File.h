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
		record = strtok(NULL, ",");
		strcpy(pNew->book->author, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->ID, record);
		record = strtok(NULL, ",");  // ��������Ҫת��
		sscanf(record, "%d", &pNew->book->count);
		record = strtok(NULL, ",");
		strcpy(pNew->book->publisher, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->date, record);
		record = strtok(NULL, ",");  // �۸���Ҫת��
		sscanf(record, "%lf", &pNew->book->price);
		record = strtok(NULL, ",");  // ���ͣ���Ҫת��
		sscanf(record, "%d", &pNew->book->type);
		record = strtok(NULL, ",");  // ʣ����������Ҫת��
		sscanf(record, "%d", &pNew->book->left);
		record = strtok(NULL, ",");  // �ܽ����������Ҫת��
		sscanf(record, "%d", &pNew->book->total);
		for (int k = 0; k < MAXLENGTH; k++) {
			record = strtok(NULL, ",");  // ״̬
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
*@method: ����ͼ���ļ��������˳�ʱ��
*@param: ͼ�������ͷָ��
*@return: ��
*@others:
*/
void saveBook(PNode head)
{
	FILE *csvBook;
	remove("Book.csv");
	csvBook = fopen("Book.csv", "w");
	if (NULL == csvBook)
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
	fprintf(csvBook, "����,����,���,����,������,��������,�۸�,����,ʣ������,");
	fprintf(csvBook, "�ܹ��������,��1״̬,��1ID,��2״̬,");
	fprintf(csvBook, "��2ID,��3״̬,��3ID,��4״̬,");
	fprintf(csvBook, "��4ID,��5״̬,��5ID,��6״̬,��6ID,��7״̬,��7ID,��8״̬,");
	fprintf(csvBook, "��8ID,��9״̬,��9ID,��10״̬,��10ID\n");  // ��ʼ������ļ�
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
	printf("�ѳɹ�����%d���飡\n", i);

	fclose(csvBook);
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
	if (_access("Book.csv", 0))  // δ���ҵ��ļ�
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
	saveBook(head); Sleep(200);
	Clear(head); Sleep(200);
}