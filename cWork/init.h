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
void AdminPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("��ѡ�����:\n"); Sleep(10);
	printf("1.����ͼ��\n"); Sleep(10);
	printf("2.�鿴����ͼ��\n"); Sleep(10);
	printf("3.���ͼ��\n"); Sleep(10);
	printf("4.ɾ��ͼ��\n"); Sleep(10);
	printf("5.�鿴ѧ��\n"); Sleep(10);
	printf("6.�鿴����Ա��Ϣ\n"); Sleep(10);
	printf("7.�ǳ�\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: ��ӡ��ʼҳ��
*@param:
*@return:
*@others:
*/
void initPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("ͼ�����ϵͳV1.1\n");  Sleep(10);
	printf("��ѡ����:\n");  Sleep(10);
	printf("1.��ѯ�鱾\n"); Sleep(10);
	printf("2.��¼(ѧ��&��ʦͨ��)\n"); Sleep(10);
	printf("3.��¼(����Աͨ��)\n");  Sleep(10);
	printf("4.��������Ϣ\n");  Sleep(10);
	printf("5.�������ݲ��˳�.��ֱ�ӹرճ��򽫶�ʧ���ݣ�������\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: ��ӡѧ��&��ʦҳ��
*@param:
*@return:
*@others:
*/
void loginInitPrint() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
	printf("��ѡ�����:\n"); Sleep(10);
	printf("1.��ѯ�鱾\n"); Sleep(10);
	printf("2.��Ҫ����\n"); Sleep(10);
	printf("3.��Ҫ����\n"); Sleep(10);
	printf("4.�鿴�������\n"); Sleep(10);
	printf("5.�ǳ�.\n"); Sleep(10);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); Sleep(10);
}


/*
*@method: ��ӡ������Ϣ
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
*@method: ����Ա��¼������
*@param:
*@return:
*@others:
*/
void loginInitAdmin(char* ID,PNode List) {
	int i = getIndex(ID,"tea");
	Person person = persons[i];
	Admin Admin = Admins[i];
	printf("����Ա%s��½�ɹ�!\n", Admins[i].name);
	state = LOGINTEA;
	int mode;
	while (state==LOGINTEA)
	{
		AdminPrint();
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
		case 2: {  //�鿴����ͼ��
			Traverse(List);
			break;
		}
		case 3: {  //���ͼ��
			Insert(List);
			break;
		}
		case 4: {	//ɾ��ͼ��
			char ID[MAX];
			printf("�������ɾ����ID��\n");
			scanf("%s", ID);
			Delete(List, ID);
			break;
		}	
		case 5: {	//�鿴ѧ��&��ʦ��Ϣ
			char ID[MAX];
			printf("������ѧ��ID��\n");
			scanf("%s", ID);
			int i = getIndex(ID, "stu");
			Person person = persons[i];
			printPerson(&person);
			break;
		}
		case 6: {  //�鿴����Ա��Ϣ
			printAdmin(&Admin);
			break;
		}
		case 7: {	//�ǳ�ϵͳ
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
*@method: ѧ��&��ʦ��¼������
*@param:
*@return:
*@others:
*/
void loginInit(char* ID,PNode List) {
	int i = getIndex(ID,"stu");
	Person person = persons[i];
	printf("ѧ��or��ʦ%s��¼�ɹ�!\n", persons[i].name);
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
			printf("��������Ҫ�黹��ͼ���ţ�\n");
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
				printf("��������ı��:");
				scanf("%s", ID);
				pBook book = SearchBook(head, ID);
				printBook(book);
				break;
			}
					case 2:	//��¼ϵͳ��ѧ��&��ʦ��
					printf("���������ID��");
					scanf("%s", ID);
					if (Login(ID,"stu")) {
						loginInit(ID,head);
					}
					else {
						printf("��¼ʧ��\n");
					}
					break;
			case 3: {	//��¼ϵͳ������Ա��
				char ID[MAX];
				printf("��������Ĺ���ԱID��\n");
				scanf("%s", ID);
				if (Login(ID,"tea"))
				{
					loginInitAdmin(ID, head);
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

