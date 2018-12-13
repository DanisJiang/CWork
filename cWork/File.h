#pragma once
#include"GLOBAL.h"
#include<io.h>
/*
*@method: ��ʼ��ͼ���������ļ�ʱ��
*@param: ��
*@return: ͼ�������ͷָ��
*@others:
*/
PNode initializeBook(void)
{
	/* �鱾���Զ��忪ʼ
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // ͼ������
	*/ //�鱾���Զ������
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
	int sum = 0;
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
		record = strtok(NULL, ",");  // �۸�
		sscanf(record, "%lf", &pNew->book->price);
		record = strtok(NULL, ",");  // ����
		sscanf(record, "%d", &pNew->book->type);
		record = strtok(NULL, ",");  // ʣ������
		sscanf(record, "%d", &pNew->book->left);
		record = strtok(NULL, ",");  // �ܽ������
		sscanf(record, "%d", &pNew->book->total);
		for (int k = 0; k < MAXLENGTH; k++) {
			record = strtok(NULL, ",");  // ״̬
			sscanf(record, "%d", &pNew->book->info[k].available);
			record = strtok(NULL, ",");  // ID
			strcpy(pNew->book->info[k].ID, record);
			record = strtok(NULL, ",");  // ������
			sscanf(record, "%d", &pNew->book->info[k].borrowDate.year);
			record = strtok(NULL, ",");  // ����·�
			sscanf(record, "%d", &pNew->book->info[k].borrowDate.month);
			record = strtok(NULL, ",");  // �������
			sscanf(record, "%d", &pNew->book->info[k].borrowDate.day);
		}
		/*int temp = strlen(pNew->book->info[9].ID)-1;
		pNew->book->info[9].ID[temp] = '\0';*/
		record = strtok(NULL, ",");
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		sum += pNew->book->count;
	}
	printf("-------------------------------------------\n"); Sleep(10);
	printf("��ǰ��608-Library������%d���飡\n",sum);

	return head;
}

/*
*@method: ��ʼ���û������ļ�ʱ��
*@param: ��
*@return: ͼ�������ͷָ��
*@others:
*/
pPersonNode intializeStudent()
{
	// �ļ���ȡ���忪ʼ
	char *line, *record;
	char buffer[1024];
	// �ļ���ȡ�������
	FILE *csvBook;
	csvBook = fopen("Student.csv", "r");
	if (NULL == csvBook) {
		printf("�ļ���ȡʧ��\n");
		exit(-1);
	}
	pPersonNode head = (pPersonNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("����ʧ��!\n");
		exit(-1);
	}
	pPersonNode tail = head;
	tail->next = NULL;
	line = fgets(buffer, sizeof(buffer), csvBook);  // ������һ��
	int sum = 0;
	while ((line = fgets(buffer, sizeof(buffer), csvBook)) != NULL) {
		pPersonNode pNew = (pPersonNode)malloc(sizeof(personNode));
		if (pNew == NULL) {
			printf("����ʧ��!\n");
			exit(-1);
		}
		pNew->person = (pPerson)malloc(sizeof(Person)); //�����˺�
		pNew->person->priority = 0;
		record = strtok(line, ",");
		strcpy(pNew->person->ID, record);  //ID
		record = strtok(NULL, ",");
		strcpy(pNew->person->name, record);  //����
		record = strtok(NULL, ",");
		strcpy(pNew->person->classes, record);  //�༶
		record = strtok(NULL, ",");
		strcpy(pNew->person->studentID, record);  //ѧ��
		record = strtok(NULL, ",");
		strcpy(pNew->person->password, record);  //����
		record = strtok(NULL, ",");
		sscanf(record, "%d", &pNew->person->count);  //�ѽ���Ŀ
		for (int i = 0; i < BORROW; i++) {
			record = strtok(NULL, ",");
			strcpy(pNew->person->borrowBook[i].ID, record);
			record = strtok(NULL, ",");
			sscanf(record, "%d", &pNew->person->borrowBook[i].borrowTime.year);
			record = strtok(NULL, ",");
			sscanf(record, "%d", &pNew->person->borrowBook[i].borrowTime.month);
			record = strtok(NULL, ",");
			sscanf(record, "%d", &pNew->person->borrowBook[i].borrowTime.day);
			record = strtok(NULL, ",");
			sscanf(record, "%d", &pNew->person->borrowBook[i].DDL);
		}
		pNew->person->overTime = 0;
		record = strtok(NULL, ",");
		tail->next = pNew;
		pNew->next = NULL;
		tail = pNew;
		sum++;
	}
	printf("-------------------------------------------\n"); Sleep(10);
	printf("��ǰ��608-Library������%dע���û���\n", sum);
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
	fprintf(csvBook, "����,����,���,����,������,��������,�۸�,����,ʣ������,�ܹ��������,");
	fprintf(csvBook, "��1״̬,��1ID,��1�����,��1�����,��1�����,");
	fprintf(csvBook, "��2״̬,��2ID,��2�����,��2�����,��2�����,");
	fprintf(csvBook, "��3״̬,��3ID,��3�����,��3�����,��3�����,");
	fprintf(csvBook, "��4״̬,��4ID,��4�����,��4�����,��4�����,");
	fprintf(csvBook, "��5״̬,��5ID,��5�����,��5�����,��5�����,");
	fprintf(csvBook, "��6״̬,��6ID,��6�����,��6�����,��6�����,");
	fprintf(csvBook, "��7״̬,��7ID,��7�����,��7�����,��7�����,");
	fprintf(csvBook, "��8״̬,��8ID,��8�����,��8�����,��8�����,");
	fprintf(csvBook, "��9״̬,��9ID,��9�����,��9�����,��9�����,");
	fprintf(csvBook, "��10״̬,��10ID,��10�����,��10�����,��10�����\n");
 // ��ʼ������ļ�
	PNode p = head->next;
	int i = 0;
	while (p != NULL)
	{
		fprintf(csvBook, "%s,%s,%s,%d,%s,%s,%lf,%d,%d,%d,", p->book->name, p->book->author,
			p->book->ID, p->book->count, p->book->publisher, 
			p->book->date, p->book->price, p->book->type, p->book->left, p->book->total);
		int temp[MAXLENGTH];
		for (int j = 0; j < MAXLENGTH; j++) {
			temp[j] = (int)p->book->info[j].available;
		}
		for (int j = 0; j < MAXLENGTH; j++) {
			fprintf(csvBook, "%d,%s,%d,%d,%d,", temp[j], p->book->info->ID,p->book->info[j].borrowDate.year, p->book->info[j].borrowDate.month, p->book->info[j].borrowDate.day);
		}
		fprintf(csvBook, "\n");
		p = p->next;
		i++;
		
	}
	printf("�ѳɹ�����%d���飡\n", i);

	fclose(csvBook);
}

/*
*@method: ����ѧ���ļ��������˳�ʱ��
*@param: ѧ�������ͷָ��
*@return: ��
*@others:
*/
void saveStudent(pPersonNode head) {
	FILE *csvStudent;
	remove("Student.csv");
	csvStudent = fopen("Student.csv", "w");
	if (NULL == csvStudent)
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
	fprintf(csvStudent, "ID,����,�༶,ѧ��,����,�ѽ���Ŀ����,");
	fprintf(csvStudent, "��1ID,��1������,��1������,��1������,");
	fprintf(csvStudent, "��2ID,��2������,��2������,��2������,");
	fprintf(csvStudent, "��3ID,��3������,��3������,��3������,");
	fprintf(csvStudent, "��4ID,��4������,��4������,��4������,");
	fprintf(csvStudent, "��5ID,��5������,��5������,��5������\n");
	pPersonNode p = head->next;
	int i = 0;
	char tmp[MAX];
	while (p != NULL)
	{
		fprintf(csvStudent, "%s,%s,%s,", p->person->ID, p->person->name, p->person->classes);
		
		_itoa(p->person->count, tmp, 10);
		fprintf(csvStudent, "%s,%s,%s,", p->person->studentID, p->person->password, tmp);
		for (int k = 0; k < BORROW; k++) {
			fprintf(csvStudent, "%s,", p->person->borrowBook[k].ID);
			_itoa(p->person->borrowBook[k].borrowTime.year, tmp, 10);
			fprintf(csvStudent, "%s,", tmp);
			_itoa(p->person->borrowBook[k].borrowTime.month, tmp, 10);
			fprintf(csvStudent, "%s,", tmp);
			_itoa(p->person->borrowBook[k].borrowTime.day, tmp, 10);
			fprintf(csvStudent, "%s,", tmp);
			_itoa(p->person->borrowBook[k].DDL, tmp, 10);
			fprintf(csvStudent, "%s,", tmp);
		}
		fprintf(csvStudent, "\n");
		p = p->next;
		i++;
	}
	printf("�ѳɹ�����%dλ�û���\n", i);

	fclose(csvStudent);
}

/*
*@method: ��ʼ��ѧ��ϵͳ
*@param: ��
*@return: ѧ�������ͷָ��
*@others:
*/
pPersonNode intializeStudentSystem() {
	pPersonNode head;
	if (_access("Student.csv", 0))  // δ���ҵ��ļ�
	{
		head = creatStudent();
	}
	else
		head = intializeStudent();
	printf("-------------------------------------------\n"); Sleep(10);
	printf("��608-Library����ʼ����ɣ�\n");
	return head;
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
	printf("\n");
	printf("   $$$$$$\\   $$$$$$\\   $$$$$$\\                  $$\\       $$\\ $$\\                                              \n"); Sleep(100);
	printf("  $$  __$$\\ $$$ __$$\\ $$  __$$\\                 $$ |      \\__|$$ |                                             \n"); Sleep(100);
	printf("  $$ /  \\__|$$$$\\ $$ |$$ /  $$ |                $$ |      $$\\ $$$$$$$\\   $$$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ \n"); Sleep(100);
	printf("  $$$$$$$\\  $$\\$$\\$$ | $$$$$$  |$$$$$$\\ $$$$$$\\ $$ |      $$ |$$  __$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$ |  $$ |\n"); Sleep(100);
	printf("  $$  __$$\\ $$ \\$$$$ |$$  __$$< \\______|\\______|$$ |      $$ |$$ |  $$ |$$ |  \\__|$$$$$$$ |$$ |  \\__|$$ |  $$ |\n"); Sleep(100);
	printf("  $$ /  $$ |$$ |\\$$$ |$$ /  $$ |                $$ |      $$ |$$ |  $$ |$$ |     $$  __$$ |$$ |      $$ |  $$ |\n"); Sleep(100);
	printf("   $$$$$$  |\\$$$$$$  /\\$$$$$$  |                $$$$$$$$\\ $$ |$$$$$$$  |$$ |     \\$$$$$$$ |$$ |      \\$$$$$$$ |\n"); Sleep(100);
	printf("   \\______/  \\______/  \\______/                 \\________|\\__|\\_______/ \\__|      \\_______|\\__|       \\____$$ |\n"); Sleep(100);
	printf("                                                                                                     $$\\   $$ |\n"); Sleep(100);
	printf("                                                                                                     \\$$$$$$  |\n"); Sleep(100);
	printf("                                                                                                      \\______/ \n"); Sleep(100);
	if (_access("Book.csv", 0))  // δ���ҵ��ļ�
	{
		bookHead = Create();
		Traverse(bookHead);

	}
	else  // ���ҵ��ļ���¼��
	{
		bookHead = initializeBook();
	}
	printf("��ӭʹ�á�608-Library��������\n");
	printf("-------------------------------------------\n"); Sleep(10);
	return bookHead;
}

/*
*@method: �˳�����
*@param: ͼ�������ͷָ��
*@return:
*@others:
*/
void closeProgram(PNode head,pPersonNode studentHead)
{
	saveBook(head); Sleep(200);
	Clear(head); Sleep(200);
	saveStudent(studentHead); Sleep(200);
	studentClear(studentHead); Sleep(200);
}