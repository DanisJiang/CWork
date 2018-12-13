#pragma once




/*
*@method: ���ѧ������
*@param:
*@return: ��
*@others:
*/
void newStudent(pPerson person, char ID[MAX], char name[MAX], char classes[MAX], char studentID[MAX],
	char password[MAX], int count, pBook borrow[BORROW],int overTime) {
	strcpy(person->ID, ID);
	strcpy(person->name,name);
	strcpy(person->classes, classes);
	strcpy(person->studentID, studentID);
	strcpy(person->password, password);
	person->priority = 0;
	person->count=0;
	for (int i = 0; i < BORROW; i++) {
		person->borrowBook[i].borrowTime = { 0,0,0 };
		strcpy(person->borrowBook[i].ID, "0");
		person->borrowBook[i].DDL = 0;
	}
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
	printf("����֤�ţ�%10s\n", person->ID); Sleep(10);
	printf("������%14s\n", person->name); Sleep(10);
	printf("�༶��%14s\n", person->classes); Sleep(10);
	printf("ѧ�ţ�%14s\n", person->studentID); Sleep(10);
	printf("���룺%14s\n", person->password); Sleep(10);
	printf("Ŀǰ����%d����\n", person->count); Sleep(10);
	printf("Ŀǰ��ʱ%d����\n", person->overTime); Sleep(10);
	for (int i = 0; i < BORROW; i++) {
		printf("��%dID��%s\n", i, person->borrowBook[i].ID);
		if (person->borrowBook[i].DDL == 1)
			printf("�鱾״̬����ʱ\n");
		else
			printf("�鱾״̬��δ��ʱ\n");
	}
	printf("-------------------------------------------\n"); Sleep(10);
	//����Ҫ ��ʱ�鱾 ��Ҫ������
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

/*
*@method: ����ѧ��
*@param: studentList:�����������;
*@return:void
*@others: �޸�Ϊβ��
*/
void studentInsert(pPersonNode studentList) {
	char ID[MAX], name[MAX], classes[MAX], studentID[MAX], password[MAX];
	pPersonNode p = studentList;
	while (p->next != NULL) {
		p = p->next;
	}
	pPersonNode tmp = (pPersonNode)malloc(sizeof(pPersonNode));
	if (tmp == NULL) {
		printf("����ʧ�ܣ�\n");
		exit(-1);
	}
	//����ڵ�
	tmp->person = (pPerson)malloc(sizeof(Person));
	int id;
	sscanf(p->person->ID, "%d", &id);
	id++;
	_itoa(id, ID, 10);
	printf("���������֣�");
	scanf("%20s", name);
	printf("������༶��");
	scanf("%20s", classes);
	printf("������ѧ�ţ�");
	scanf("%20s", studentID);
	printf("���������룺");
	scanf("%20s", password);
	newStudent(tmp->person, ID, name, classes, studentID, password, 0, NULL, 0);
	tmp->next = p->next;
	p->next = tmp;
	printf("ע��ɹ�����ӭʹ��608-Library!!!\n");
	printStudent(p->next->person);
}
/*
*@method: ɾ��ָ��λ�õ�ѧ��
*@param: studentList:��ɾ����ͼ������;ID: ��ɾ����ѧ��ID���
*@return: Void
*@others:  �޸�Ϊ����IDɾ��ѧ��
*/
void studentDelete(pPersonNode studentList, char *ID) {
	pPersonNode p = studentList;
	while (p->next != NULL && (strcmp(p->next->person->ID,ID)!=0)) {
		p=p->next;
	}
	if (p->next != NULL) {
		printStudent(p->next->person);
		printf("ȷ��ɾ����\n");
		printf("1.�� 2.��\n");
		int i = 0;
		scanf("%d", &i);
		if (1 == i) {
			if (p->next->person->count > 0) {
				printf("��ѧ��������δ�黹��ɾ���˺�ʧ�ܣ�����\n");
				return;
			}
			pPersonNode tmp = p;
			p = p->next;
			tmp->next = p->next;
			free(p->person);
			//free(p);
			printf("ɾ���˺ųɹ���\n");
		}
		else
			return;
	}
	else {
		printf("û���ҵ���ѧ����\n");
		return;
	}
}
/*
*@method: ���ѧ������
*@param: ����յ�����
*@return: ��
*@others:
*/
void studentClear(pPersonNode studentList) {
	pPersonNode p = studentList->next, tmp;
	while (p->next != NULL) {
		tmp = p->next;
		free(p->person);
		p = tmp;
	}
	printf("�˺��������\n");
}
/*
*@method: ����ѧ������
*@param: studentList:������������;ID:������ѧ����ID
*@return: ��������ѧ���ڵ�
*@others:
*/
pPerson SearchStudent(pPersonNode studentList, char *ID) {
	pPersonNode p = studentList->next;
	while (p != NULL && strcmp(p->person->ID, ID) != 0) {
		p = p->next;
	}
	if (p != NULL)
	{
		return p->person;
	}
	else {
		return NULL;
	}
}

/*
*@method: ����ѧ��������
*@param:
*@return: ѧ������ͷ�ڵ�
*@others:
*/
pPersonNode creatStudent() {
	pPersonNode head=(pPersonNode)calloc(1,sizeof(PersonNode));
	head->person = (pPerson)calloc(1, sizeof(Person));
	_itoa(0, head->person->ID, 10);
	head->next = NULL;
	return head;
}
/*
*@method: ��ȡ�û���index
*@param:
*@return:
*@others:
*/
void getStudentIndex(char *ID, pPersonNode studentHead) {
	pPersonNode p = studentHead->next;
	while (p->next != NULL && strcmp(p->next->person->ID, ID))
	{
		p = p->next;
	}
	printStudent(p->person);
}