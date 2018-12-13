#pragma once
#include"GLOBAL.h"
#include<io.h>
/*
*@method: 初始化图书链表（有文件时）
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
PNode initializeBook(void)
{
	/* 书本属性定义开始
	char ID[MAX], publisher[MAX], author[MAX], name[MAX], date[MAX];
	int  count;
	double price;
	int type;  // 图书种类
	*/ //书本属性定义结束
	// 文件读取定义开始
	char *line, *record;
	char buffer[1024];
	// 文件读取定义结束
	FILE *csvBook;
	csvBook = fopen("Book.csv", "r");
	if (NULL == csvBook) {
		printf("文件读取失败\n");
		exit(-1);                                                     
	}
	PNode head = (PNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	PNode tail = head;
	tail->next = NULL;
	line = fgets(buffer, sizeof(buffer), csvBook);  // 跳过第一行
	int sum = 0;
	while ((line = fgets(buffer, sizeof(buffer), csvBook)) != NULL) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		if (pNew == NULL){
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->book = (pBook)malloc(sizeof(Book)); //创建书本
		record = strtok(line, ",");
		strcpy(pNew->book->name, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->author, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->ID, record);
		record = strtok(NULL, ",");  // 数量，需要转换
		sscanf(record, "%d", &pNew->book->count);
		record = strtok(NULL, ",");
		strcpy(pNew->book->publisher, record);
		record = strtok(NULL, ",");
		strcpy(pNew->book->date, record);
		record = strtok(NULL, ",");  // 价格
		sscanf(record, "%lf", &pNew->book->price);
		record = strtok(NULL, ",");  // 类型
		sscanf(record, "%d", &pNew->book->type);
		record = strtok(NULL, ",");  // 剩余数量
		sscanf(record, "%d", &pNew->book->left);
		record = strtok(NULL, ",");  // 总借出次数
		sscanf(record, "%d", &pNew->book->total);
		for (int k = 0; k < MAXLENGTH; k++) {
			record = strtok(NULL, ",");  // 状态
			sscanf(record, "%d", &pNew->book->info[k].available);
			record = strtok(NULL, ",");  // ID
			strcpy(pNew->book->info[k].ID, record);
			record = strtok(NULL, ",");  // 借出年份
			sscanf(record, "%d", &pNew->book->info[k].borrowDate.year);
			record = strtok(NULL, ",");  // 借出月份
			sscanf(record, "%d", &pNew->book->info[k].borrowDate.month);
			record = strtok(NULL, ",");  // 借出日期
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
	printf("当前“608-Library”共有%d本书！\n",sum);

	return head;
}

/*
*@method: 初始化用户（有文件时）
*@param: 无
*@return: 图书链表的头指针
*@others:
*/
pPersonNode intializeStudent()
{
	// 文件读取定义开始
	char *line, *record;
	char buffer[1024];
	// 文件读取定义结束
	FILE *csvBook;
	csvBook = fopen("Student.csv", "r");
	if (NULL == csvBook) {
		printf("文件读取失败\n");
		exit(-1);
	}
	pPersonNode head = (pPersonNode)malloc(sizeof(Node));
	if (head == NULL) {
		printf("分配失败!\n");
		exit(-1);
	}
	pPersonNode tail = head;
	tail->next = NULL;
	line = fgets(buffer, sizeof(buffer), csvBook);  // 跳过第一行
	int sum = 0;
	while ((line = fgets(buffer, sizeof(buffer), csvBook)) != NULL) {
		pPersonNode pNew = (pPersonNode)malloc(sizeof(personNode));
		if (pNew == NULL) {
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->person = (pPerson)malloc(sizeof(Person)); //创建账号
		pNew->person->priority = 0;
		record = strtok(line, ",");
		strcpy(pNew->person->ID, record);  //ID
		record = strtok(NULL, ",");
		strcpy(pNew->person->name, record);  //姓名
		record = strtok(NULL, ",");
		strcpy(pNew->person->classes, record);  //班级
		record = strtok(NULL, ",");
		strcpy(pNew->person->studentID, record);  //学号
		record = strtok(NULL, ",");
		strcpy(pNew->person->password, record);  //密码
		record = strtok(NULL, ",");
		sscanf(record, "%d", &pNew->person->count);  //已借数目
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
	printf("当前“608-Library”共有%d注册用户！\n", sum);
	return head;
}

/*
*@method: 保存图书文件（程序退出时）
*@param: 图书链表的头指针
*@return: 无
*@others:
*/
void saveBook(PNode head)
{
	FILE *csvBook;
	remove("Book.csv");
	csvBook = fopen("Book.csv", "w");
	if (NULL == csvBook)
	{
		printf("文件读取失败\n");
		exit(0);
	}
	fprintf(csvBook, "书名,作者,编号,数量,出版商,发行日期,价格,类型,剩余数量,总共借出次数,");
	fprintf(csvBook, "书1状态,书1ID,书1借出年,书1借出月,书1借出天,");
	fprintf(csvBook, "书2状态,书2ID,书2借出年,书2借出月,书2借出天,");
	fprintf(csvBook, "书3状态,书3ID,书3借出年,书3借出月,书3借出天,");
	fprintf(csvBook, "书4状态,书4ID,书4借出年,书4借出月,书4借出天,");
	fprintf(csvBook, "书5状态,书5ID,书5借出年,书5借出月,书5借出天,");
	fprintf(csvBook, "书6状态,书6ID,书6借出年,书6借出月,书6借出天,");
	fprintf(csvBook, "书7状态,书7ID,书7借出年,书7借出月,书7借出天,");
	fprintf(csvBook, "书8状态,书8ID,书8借出年,书8借出月,书8借出天,");
	fprintf(csvBook, "书9状态,书9ID,书9借出年,书9借出月,书9借出天,");
	fprintf(csvBook, "书10状态,书10ID,书10借出年,书10借出月,书10借出天\n");
 // 初始化表格文件
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
	printf("已成功保存%d本书！\n", i);

	fclose(csvBook);
}

/*
*@method: 保存学生文件（程序退出时）
*@param: 学生链表的头指针
*@return: 无
*@others:
*/
void saveStudent(pPersonNode head) {
	FILE *csvStudent;
	remove("Student.csv");
	csvStudent = fopen("Student.csv", "w");
	if (NULL == csvStudent)
	{
		printf("文件读取失败\n");
		exit(0);
	}
	fprintf(csvStudent, "ID,姓名,班级,学号,密码,已借书目数量,");
	fprintf(csvStudent, "书1ID,书1借阅年,书1借阅月,书1借阅日,");
	fprintf(csvStudent, "书2ID,书2借阅年,书2借阅月,书2借阅日,");
	fprintf(csvStudent, "书3ID,书3借阅年,书3借阅月,书3借阅日,");
	fprintf(csvStudent, "书4ID,书4借阅年,书4借阅月,书4借阅日,");
	fprintf(csvStudent, "书5ID,书5借阅年,书5借阅月,书5借阅日\n");
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
	printf("已成功保存%d位用户！\n", i);

	fclose(csvStudent);
}

/*
*@method: 初始化学生系统
*@param: 无
*@return: 学生链表的头指针
*@others:
*/
pPersonNode intializeStudentSystem() {
	pPersonNode head;
	if (_access("Student.csv", 0))  // 未查找到文件
	{
		head = creatStudent();
	}
	else
		head = intializeStudent();
	printf("-------------------------------------------\n"); Sleep(10);
	printf("“608-Library”初始化完成！\n");
	return head;
}

/*
*@method: 初始化程序
*@param: 无
*@return: 图书链表的头指针
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
	if (_access("Book.csv", 0))  // 未查找到文件
	{
		bookHead = Create();
		Traverse(bookHead);

	}
	else  // 查找到文件，录入
	{
		bookHead = initializeBook();
	}
	printf("欢迎使用“608-Library”！！！\n");
	printf("-------------------------------------------\n"); Sleep(10);
	return bookHead;
}

/*
*@method: 退出程序
*@param: 图书链表的头指针
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