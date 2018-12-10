#include"User.h"
#include"List.h"

typedef struct PersonNode{
	pPerson person;
	struct PersonNode* next;
}personNode,*pPersonNode;

/*
*@method: 添加学生函数
*@param:
*@return: 无
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
*@method: 打印学生信息函数
*@param: person:待打印的学生
*@return: 无
*@others:
*/
void printStudent(pPerson person) {
	if (NULL == person) {
		printf("\n-------------------------------------------\n"); Sleep(10);
		printf("没有这位同学！！！\n"); Sleep(10);
		printf("(；′⌒`)  (；′⌒`)  (；′⌒`)\n"); Sleep(10);
		printf("-------------------------------------------\n"); Sleep(10);
		return;
	}
	printf("-------------------------------------------\n"); Sleep(10);
	printf("借书证号：%14s\n", person->ID); Sleep(10);
	printf("姓名：%14s\n", person->name); Sleep(10);
	printf("班级：%14s\n", person->classes); Sleep(10);
	printf("学号：%14s\n", person->studentID); Sleep(10);
	printf("目前借阅%d本书", person->count); Sleep(10);
	
}

/*
*@method: 遍历学生链表
*@param: studentHead：待遍历的链表
*@return: 无
*@others:
*/
void studentTraverse(pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	int i = 1;
	if (p == NULL)
		printf("当前没有学生！！！\n");
	while (p != NULL) {
		printf(">>>>>>>>>>>>>第%d位同学<<<<<<<<<<<<\n", i);
		printStudent(p->person);
		p = p->next;
		i++;
	}
}