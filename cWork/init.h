#pragma once
#include<malloc.h>
#include<Windows.h>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include "GLOBAL.h"
#include "List.h"
#include "User.h"
#include "File.h"
int state = LOGOUT; //当前状态


/*
*@method: 打印教师页面
*@param: 
*@return: 
*@others:
*/
void AdminPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("请选择操作:\n"); Sleep(10);
	printf("1.查找图书\n"); Sleep(10);
	printf("2.查看所有图书\n"); Sleep(10);
	printf("3.添加图书\n"); Sleep(10);
	printf("4.删除图书\n"); Sleep(10);
	printf("5.查看学生\n"); Sleep(10);
	printf("6.查看管理员信息\n"); Sleep(10);
	printf("7.登出\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: 打印初始页面
*@param:
*@return:
*@others:
*/
void initPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("图书管理系统V1.1\n");  Sleep(10);
	printf("请选择功能:\n");  Sleep(10);
	printf("1.查询书本\n"); Sleep(10);
	printf("2.登录(学生&教师通道)\n"); Sleep(10);
	printf("3.登录(管理员通道)\n");  Sleep(10);
	printf("4.开发者信息\n");  Sleep(10);
	printf("5.保存数据并退出.（直接关闭程序将丢失数据！！！）\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: 打印学生&教师页面
*@param:
*@return:
*@others:
*/
void loginInitPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("请选择操作:\n"); Sleep(10);
	printf("1.查询书本\n"); Sleep(10);
	printf("2.我要借书\n"); Sleep(10);
	printf("3.我要还书\n"); Sleep(10);
	printf("4.查看个人情况\n"); Sleep(10);
	printf("5.登出.\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: 打印作者信息
*@param:
*@return:
*@others:
*/
void printAuthor() {
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
	printf("    ____     __      __                      __           __                                        \n"); Sleep(100);
	printf("   /'___\\  /'__`\\  /'_ `\\                   /\\ \\       __/\\ \\                                       \n"); Sleep(100);
	printf("  /\\ \\__/ /\\ \\/\\ \\/\\ \\L\\ \\                  \\ \\ \\     /\\_\\ \\ \\____  _ __    __     _ __   __  __    \n"); Sleep(100);
	printf("  \\ \\  _``\\ \\ \\ \\ \\/_> _ <_  _______  _______\\ \\ \\  __\\/\\ \\ \\ '__`\\/\\`'__\\/'__`\\  /\\`'__\\/\\ \\/\\ \\   \n"); Sleep(100);
	printf("   \\ \\ \\L\\ \\ \\ \\_\\ \\/\\ \\L\\ \\/\\______\\/\\______\\\\ \\ \\L\\ \\\\ \\ \\ \\ \\L\\ \\ \\ \\//\\ \\L\\.\\_\\ \\ \\/ \\ \\ \\_\\ \\  \n"); Sleep(100);
	printf("    \\ \\____/\\ \\____/\\ \\____/\\/______/\\/______/ \\ \\____/ \\ \\_\\ \\_,__/\\ \\_\\\\ \\__/.\\_\\\\ \\_\\  \\/`____ \\ \n"); Sleep(100);
	printf("     \\/___/  \\/___/  \\/___/                     \\/___/   \\/_/\\/___/  \\/_/ \\/__/\\/_/ \\/_/   `/___/> \\\n"); Sleep(100);
	printf("                                                                                              /\\___/\n"); Sleep(100);
	printf("                                                                                              \\/__/ \n"); Sleep(100);
}


/*
*@method: 管理员登录主函数
*@param:
*@return:
*@others:
*/
void loginInitAdmin(char* ID,PNode List) {
	int i = getIndex(ID,"tea");
	Person person = persons[i];
	Admin Admin = Admins[i];
	printf("管理员%s登陆成功!\n", Admins[i].name);
	state = LOGINTEA;
	int mode;
	while (state==LOGINTEA)
	{
		AdminPrint();
		scanf("%d", &mode);
		switch (mode)
		{
		case 1: {  //查询图书
			char ID[MAX];
			printf("请输入书的编号:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			break;
		}
		case 2: {  //查看所有图书
			Traverse(List);
			break;
		}
		case 3: {  //添加图书
			Insert(List);
			break;
		}
		case 4: {	//删除图书
			char ID[MAX];
			printf("请输入待删除的ID：\n");
			scanf("%s", ID);
			Delete(List, ID);
			break;
		}	
		case 5: {	//查看学生&教师信息
			char ID[MAX];
			printf("请输入学生ID：\n");
			scanf("%s", ID);
			int i = getIndex(ID, "stu");
			Person person = persons[i];
			printPerson(&person);
			break;
		}
		case 6: {  //查看管理员信息
			printAdmin(&Admin);
			break;
		}
		case 7: {	//登出系统
			printf("登出\n");
			state = LOGOUT;
			break;
		}
		default:
			printf("尚无此功能,请重新输入!\n");
			break;
		}
	}
}


/*
*@method: 学生&教师登录主函数
*@param:
*@return:
*@others:
*/
void loginInit(char* ID,PNode List) {
	int i = getIndex(ID,"stu");
	Person person = persons[i];
	printf("学生or教师%s登录成功!\n", persons[i].name);
	state = LOGINSTU;
	int mode;
	while (state == LOGINSTU)
	{
		loginInitPrint();
		scanf("%d", &mode);
		switch (mode)
		{
		case 1: {		//搜索图书
			char ID[MAX];
			printf("请输入书的编号:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			break;
		}
		case 2: {	//借阅图书
			char ID[MAX];
			printf("请输入书的编号:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			if (book->left > 0) {
				int flag;
				printf("是否借阅该书?(1:是,0:否)\n");
				scanf("%d", &flag);
				if (flag == 1)
				{
					Borrow(&person, book);
				}
			}
			else {
				printf("库存不足\n");
			}
			break;
		}	
		case 3://归还图书
		{
			char id[MAX];
			printf("请输入你要归还的图书编号：\n");
			scanf("%s", id);
			if (returnBook(&person, id))
				printf("还书成功\n");
			else {
				printf("还书失败!\n");
			}
			break;
		}
		case 4:		//查看个人资料
			printPerson(&person);
			break;
		case 5:		//登出系统
			printf("登出\n");
			state = LOGOUT;
			break;
		default:
			printf("尚无此功能,请重新输入!\n");
			break;
		}
	}
}


/*
*@method: 初始化登录界面函数
*@param:
*@return:
*@others:
*/
void Init() {
	PNode head = intializeProgram();
	Traverse(head);
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
	int mode;
	char ID[MAX];
	while (state != EXIT) {
			initPrint();
			scanf("%d", &mode);
			switch (mode) {
			case 1: {
				char ID[MAX];
				printf("请输入书的编号:");
				scanf("%s", ID);
				pBook book = SearchBook(head, ID);
				printBook(book);
				break;
			}
					case 2:	//登录系统（学生&教师）
					printf("请输入你的ID：");
					scanf("%s", ID);
					if (Login(ID,"stu")) {
						loginInit(ID,head);
					}
					else {
						printf("登录失败\n");
					}
					break;
			case 3: {	//登录系统（管理员）
				char ID[MAX];
				printf("请输入你的管理员ID：\n");
				scanf("%s", ID);
				if (Login(ID,"tea"))
				{
					loginInitAdmin(ID, head);
				}
				else {
					printf("登录失败\n");
				}
				break;
			}

					
				case 4: //查看开发者信息
					printAuthor();
					break;
				case 5: //退出程序
					closeProgram(head);
					state = EXIT;
					break;
				default: 
					printf("尚无此功能,请重新输入!\n");
					break;
		}
	}
}

