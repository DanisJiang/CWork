#pragma once




/*
*@method: 添加学生函数
*@param:
*@return: 无
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
	printf("借书证号：%10s\n", person->ID); Sleep(10);
	printf("姓名：%14s\n", person->name); Sleep(10);
	printf("班级：%14s\n", person->classes); Sleep(10);
	printf("学号：%14s\n", person->studentID); Sleep(10);
	printf("密码：%14s\n", person->password); Sleep(10);
	printf("目前借阅%d本书\n", person->count); Sleep(10);
	printf("目前超时%d本书\n", person->overTime); Sleep(10);
	for (int i = 0; i < BORROW; i++) {
		printf("书%dID：%s\n", i, person->borrowBook[i].ID);
		if (person->borrowBook[i].DDL == 1)
			printf("书本状态：超时\n");
		else
			printf("书本状态：未超时\n");
	}
	printf("-------------------------------------------\n"); Sleep(10);
	//还需要 超时书本 需要罚款金额
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

/*
*@method: 插入学生
*@param: studentList:带插入的链表;
*@return:void
*@others: 修改为尾插
*/
void studentInsert(pPersonNode studentList) {
	char ID[MAX], name[MAX], classes[MAX], studentID[MAX], password[MAX];
	pPersonNode p = studentList;
	while (p->next != NULL) {
		p = p->next;
	}
	pPersonNode tmp = (pPersonNode)malloc(sizeof(pPersonNode));
	if (tmp == NULL) {
		printf("分配失败！\n");
		exit(-1);
	}
	//插入节点
	tmp->person = (pPerson)malloc(sizeof(Person));
	int id;
	sscanf(p->person->ID, "%d", &id);
	id++;
	_itoa(id, ID, 10);
	printf("请输入名字：");
	scanf("%20s", name);
	printf("请输入班级：");
	scanf("%20s", classes);
	printf("请输入学号：");
	scanf("%20s", studentID);
	printf("请输入密码：");
	scanf("%20s", password);
	newStudent(tmp->person, ID, name, classes, studentID, password, 0, NULL, 0);
	tmp->next = p->next;
	p->next = tmp;
	printf("注册成功！欢迎使用608-Library!!!\n");
	printStudent(p->next->person);
}
/*
*@method: 删除指定位置的学生
*@param: studentList:待删除的图书链表;ID: 待删除的学生ID编号
*@return: Void
*@others:  修改为根据ID删除学生
*/
void studentDelete(pPersonNode studentList, char *ID) {
	pPersonNode p = studentList;
	while (p->next != NULL && (strcmp(p->next->person->ID,ID)!=0)) {
		p=p->next;
	}
	if (p->next != NULL) {
		printStudent(p->next->person);
		printf("确认删除？\n");
		printf("1.是 2.否\n");
		int i = 0;
		scanf("%d", &i);
		if (1 == i) {
			if (p->next->person->count > 0) {
				printf("该学生仍有书未归还！删除账号失败！！！\n");
				return;
			}
			pPersonNode tmp = p;
			p = p->next;
			tmp->next = p->next;
			free(p->person);
			//free(p);
			printf("删除账号成功！\n");
		}
		else
			return;
	}
	else {
		printf("没有找到此学生！\n");
		return;
	}
}
/*
*@method: 清空学生链表
*@param: 待清空的链表
*@return: 无
*@others:
*/
void studentClear(pPersonNode studentList) {
	pPersonNode p = studentList->next, tmp;
	while (p->next != NULL) {
		tmp = p->next;
		free(p->person);
		p = tmp;
	}
	printf("账号清理完成\n");
}
/*
*@method: 搜索学生函数
*@param: studentList:待搜索的链表;ID:待搜索学生的ID
*@return: 搜索到的学生节点
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
*@method: 创建学生链表函数
*@param:
*@return: 学生链表头节点
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
*@method: 获取用户的index
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