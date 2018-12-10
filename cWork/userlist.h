#include"User.h"
#include"List.h"

typedef struct PersonNode{
	pPerson person;
	struct PersonNode* next;
}personNode,*pPersonNode;

/*
*@method: ���ѧ������
*@param:
*@return: ��
*@others:
*/
void newStudent(pPerson person , int priority, char ID[MAX], char name[MAX], char classes[MAX], char studentID[MAX],
	char password[MAX], int count, pBook borrow[BRORROW],int overTime) {
	strcpy(person->ID, ID);
	strcpy(person->name,name);
	strcpy(person->classes, classes);
	strcpy(person->studentID, studentID);
	strcpy(person->password, password);
	person->priority = 0;
	person->count=0;
	person->borrow[0] = NULL;
	person->borrow[1] = NULL;
	person->borrow[2] = NULL;
	person->borrow[3] = NULL;
	person->borrow[4] = NULL;
	person->overTime = 0;
}

/*
*@method: ��ӡѧ����Ϣ����
*@param: person:����ӡ��ѧ��
*@return: ��
*@others:
*/
void printStudent(pPerson person) {
	if (NULL == person) {
		printf("\n-------------------------------------------\n"); Sleep(10);
		printf("û����λͬѧ������\n"); Sleep(10);
		printf("(�����`)  (�����`)  (�����`)\n"); Sleep(10);
		printf("-------------------------------------------\n"); Sleep(10);
		return;
	}
	printf("-------------------------------------------\n"); Sleep(10);
	printf("����֤�ţ�%14s\n", person->ID); Sleep(10);
	printf("������%14s\n", person->name); Sleep(10);
	printf("�༶��%14s\n", person->classes); Sleep(10);
	printf("ѧ�ţ�%14s\n", person->studentID); Sleep(10);
	printf("Ŀǰ����%d����", person->count); Sleep(10);
	
}

/*
*@method: ����ѧ������
*@param: studentHead��������������
*@return: ��
*@others:
*/
void studentTraverse(pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	int i = 1;
	if (p == NULL)
		printf("��ǰû��ѧ��������\n");
	while (p != NULL) {
		printf(">>>>>>>>>>>>>��%dλͬѧ<<<<<<<<<<<<\n", i);
		printStudent(p->person);
		p = p->next;
		i++;
	}
}