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
int state = LOGOUT; //��ǰ״̬


/*
*@method: ��ӡ��ʦҳ��
*@param: 
*@return: 
*@others:
*/
void teacherPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("��ѡ�����:\n");
	printf("1.�鿴����ͼ��\n");
	printf("2.���ͼ��\n");
	printf("3.ɾ��ͼ��\n");
	printf("4.�鿴ѧ��\n");
	printf("5.�鿴��ʦ��Ϣ\n");
	printf("6.�ǳ�\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}


/*
*@method: ��ӡ��ʼҳ��
*@param:
*@return:
*@others:
*/
void initPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(30);
	printf("ͼ�����ϵͳV1.0\n");  Sleep(30);
	printf("��ѡ����:\n");  Sleep(30);
	printf("1.��ѯ�鱾\n"); Sleep(30);
	printf("2.��¼(ѧ��ͨ��)\n"); Sleep(30);
	printf("3.��¼(��ʦͨ��)\n");  Sleep(30);
	printf("4.��������\n");  Sleep(30);
	printf("5.�˳�.\n"); Sleep(30);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(30);
}


/*
*@method: ��ӡѧ��ҳ��
*@param:
*@return:
*@others:
*/
void loginInitPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("��ѡ�����:\n");
	printf("1.��ѯ�鱾\n");
	printf("2.��Ҫ����\n");
	printf("3.��Ҫ����\n");
	printf("4.�鿴�������\n");
	printf("5.�ǳ�.\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}


/*
*@method: ��ӡ������Ϣ
*@param:
*@return:
*@others:
*/
void printAuthor() {
	printf(" $$$$$$\\   $$$$$$\\   $$$$$$\\                  $$\\       $$\\ $$\\                                              \n"); Sleep(100);
	printf("$$  __$$\\ $$$ __$$\\ $$  __$$\\                 $$ |      \\__|$$ |                                             \n"); Sleep(100);
	printf("$$ /  \\__|$$$$\\ $$ |$$ /  $$ |                $$ |      $$\\ $$$$$$$\\   $$$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ \n"); Sleep(100);
	printf("$$$$$$$\\  $$\\$$\\$$ | $$$$$$  |$$$$$$\\ $$$$$$\\ $$ |      $$ |$$  __$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$ |  $$ |\n"); Sleep(100);
	printf("$$  __$$\\ $$ \\$$$$ |$$  __$$< \\______|\\______|$$ |      $$ |$$ |  $$ |$$ |  \\__|$$$$$$$ |$$ |  \\__|$$ |  $$ |\n"); Sleep(100);
	printf("$$ /  $$ |$$ |\\$$$ |$$ /  $$ |                $$ |      $$ |$$ |  $$ |$$ |     $$  __$$ |$$ |      $$ |  $$ |\n"); Sleep(100);
	printf(" $$$$$$  |\\$$$$$$  /\\$$$$$$  |                $$$$$$$$\\ $$ |$$$$$$$  |$$ |     \\$$$$$$$ |$$ |      \\$$$$$$$ |\n"); Sleep(100);
	printf(" \\______/  \\______/  \\______/                 \\________|\\__|\\_______/ \\__|      \\_______|\\__|       \\____$$ |\n"); Sleep(100);
	printf("                                                                                                   $$\\   $$ |\n"); Sleep(100);
	printf("                                                                                                   \\$$$$$$  |\n"); Sleep(100);
	printf("                                                                                                    \\______/ \n"); Sleep(100);
	printf("  ____     __      __                      __           __                                        \n"); Sleep(100);
	printf(" /'___\\  /'__`\\  /'_ `\\                   /\\ \\       __/\\ \\                                       \n"); Sleep(100);
	printf("/\\ \\__/ /\\ \\/\\ \\/\\ \\L\\ \\                  \\ \\ \\     /\\_\\ \\ \\____  _ __    __     _ __   __  __    \n"); Sleep(100);
	printf("\\ \\  _``\\ \\ \\ \\ \\/_> _ <_  _______  _______\\ \\ \\  __\\/\\ \\ \\ '__`\\/\\`'__\\/'__`\\  /\\`'__\\/\\ \\/\\ \\   \n"); Sleep(100);
	printf(" \\ \\ \\L\\ \\ \\ \\_\\ \\/\\ \\L\\ \\/\\______\\/\\______\\\\ \\ \\L\\ \\\\ \\ \\ \\ \\L\\ \\ \\ \\//\\ \\L\\.\\_\\ \\ \\/ \\ \\ \\_\\ \\  \n"); Sleep(100);
	printf("  \\ \\____/\\ \\____/\\ \\____/\\/______/\\/______/ \\ \\____/ \\ \\_\\ \\_,__/\\ \\_\\\\ \\__/.\\_\\\\ \\_\\  \\/`____ \\ \n"); Sleep(100);
	printf("   \\/___/  \\/___/  \\/___/                     \\/___/   \\/_/\\/___/  \\/_/ \\/__/\\/_/ \\/_/   `/___/> \\\n"); Sleep(100);
	printf("                                                                                            /\\___/\n"); Sleep(100);
	printf("                                                                                            \\/__/ \n"); Sleep(100);
}


/*
*@method: ��ʦ��¼������
*@param:
*@return:
*@others:
*/
void loginInitTeacher(char* ID,PNode List) {
	int i = getIndex(ID,"tea");
	Person person = persons[i];
	Teacher teacher = teachers[i];
	printf("��ʦ%s��½�ɹ�!\n", teachers[i].name);
	state = LOGINTEA;
	int mode;
	while (state==LOGINTEA)
	{
		teacherPrint();
		scanf("%d", &mode);
		switch (mode)
		{
		case 1: {  //��ѯͼ��
			char ID[MAX];
			printf("��������ı��:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			break;
		}
		case 2: {  //���ͼ��
			Insert(List);
			break;
		}
		case 3: {	//ɾ��ͼ��
			char ID[MAX];
			printf("�������ɾ����ID\n");
			scanf("%s", ID);
			Delete(List, ID);
			break;
		}	
		case 4: {	//�鿴ѧ����Ϣ
			char ID[MAX];
			printf("������ѧ��ID\n");
			scanf("%s", ID);
			int i = getIndex(ID, "stu");
			Person person = persons[i];
			printPerson(&person);
			break;
		}
		case 5: {  //�鿴��ʦ��Ϣ
			printTeacher(&teacher);
			break;
		}
		case 6: {	//�ǳ�ϵͳ
			printf("�ǳ�\n");
			state = LOGOUT;
			break;
		}
		default:
			printf("���޴˹���,����������!\n");
			break;
		}
	}
}


/*
*@method: ѧ����¼������
*@param:
*@return:
*@others:
*/
void loginInit(char* ID,PNode List) {
	int i = getIndex(ID,"stu");
	Person person = persons[i];
	printf("ѧ��%s��¼�ɹ�!\n", persons[i].name);
	state = LOGINSTU;
	int mode;
	while (state == LOGINSTU)
	{
		loginInitPrint();
		scanf("%d", &mode);
		switch (mode)
		{
		case 1: {		//����ͼ��
			char ID[MAX];
			printf("��������ı��:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			break;
		}
		case 2: {	//����ͼ��
			char ID[MAX];
			printf("��������ı��:");
			scanf("%s", ID);
			pBook book = SearchBook(List, ID);
			printBook(book);
			if (book->left > 0) {
				int flag;
				printf("�Ƿ���ĸ���?(1:��,0:��)\n");
				scanf("%d", &flag);
				if (flag == 1)
				{
					Borrow(&person, book);
				}
			}
			else {
				printf("��治��\n");
			}
			break;
		}	
		case 3://�黹ͼ��
		{
			char id[MAX];
			printf("��������Ҫ�黹��ͼ����\n");
			scanf("%s", id);
			if (returnBook(&person, id))
				printf("����ɹ�\n");
			else {
				printf("����ʧ��!\n");
			}
			break;
		}
		case 4:		//�鿴��������
			printPerson(&person);
			break;
		case 5:		//�ǳ�ϵͳ
			printf("�ǳ�\n");
			state = LOGOUT;
			break;
		default:
			printf("���޴˹���,����������!\n");
			break;
		}
	}
}


/*
*@method: ��ʼ����¼���溯��
*@param:
*@return:
*@others:
*/
void Init() {
	PNode head = intializeProgram();
	Traverse(head);
	printf(" $$$$$$\\   $$$$$$\\   $$$$$$\\                  $$\\       $$\\ $$\\                                              \n"); Sleep(100);
	printf("$$  __$$\\ $$$ __$$\\ $$  __$$\\                 $$ |      \\__|$$ |                                             \n"); Sleep(100);
	printf("$$ /  \\__|$$$$\\ $$ |$$ /  $$ |                $$ |      $$\\ $$$$$$$\\   $$$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ \n"); Sleep(100);
	printf("$$$$$$$\\  $$\\$$\\$$ | $$$$$$  |$$$$$$\\ $$$$$$\\ $$ |      $$ |$$  __$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$ |  $$ |\n"); Sleep(100);
	printf("$$  __$$\\ $$ \\$$$$ |$$  __$$< \\______|\\______|$$ |      $$ |$$ |  $$ |$$ |  \\__|$$$$$$$ |$$ |  \\__|$$ |  $$ |\n"); Sleep(100);
	printf("$$ /  $$ |$$ |\\$$$ |$$ /  $$ |                $$ |      $$ |$$ |  $$ |$$ |     $$  __$$ |$$ |      $$ |  $$ |\n"); Sleep(100);
	printf(" $$$$$$  |\\$$$$$$  /\\$$$$$$  |                $$$$$$$$\\ $$ |$$$$$$$  |$$ |     \\$$$$$$$ |$$ |      \\$$$$$$$ |\n"); Sleep(100);
	printf(" \\______/  \\______/  \\______/                 \\________|\\__|\\_______/ \\__|      \\_______|\\__|       \\____$$ |\n"); Sleep(100);
	printf("                                                                                                   $$\\   $$ |\n"); Sleep(100);
	printf("                                                                                                   \\$$$$$$  |\n"); Sleep(100);
	printf("                                                                                                    \\______/ \n"); Sleep(100);
	int mode;
	char ID[MAX];
	while (state != EXIT) {
			initPrint();
			scanf("%d", &mode);
			switch (mode) {
			case 1: {
				char ID[MAX];
				printf("��������ı��:");
				scanf("%s", ID);
				pBook book = SearchBook(head, ID);
				printBook(book);
				break;
			}
					case 2:	//��¼ϵͳ��ѧ����
					printf("���������ѧ��");
					scanf("%s", ID);
					if (Login(ID,"stu")) {
						loginInit(ID,head);
					}
					else {
						printf("��¼ʧ��\n");
					}
					break;
			case 3: {	//��¼ϵͳ����ʦ��
				char ID[MAX];
				printf("��������Ľ�ʦ��\n");
				scanf("%s", ID);
				if (Login(ID,"tea"))
				{
					loginInitTeacher(ID, head);
				}
				else {
					printf("��¼ʧ��\n");
				}
				break;
			}

					
				case 4: //�鿴��������Ϣ
					printAuthor();
					break;
				case 5: //�˳�����
					closeProgram(head);
					state = EXIT;
					break;
				default: 
					printf("���޴˹���,����������!\n");
					break;
		}
	}
}

