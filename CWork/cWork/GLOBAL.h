#pragma once
#include"Date.h"
/*ȫ�ֱ������궨��*/


#define MAX 20			//������ֶ�
#define MAXLENGTH 10	//�����ͼ��
#define MAXPERSON 20	//���ѧ������
#define BORROW 5		//ѧ��������ͼ�鱾��
#define TIME 30			//���ν�����¼�
#define RENEWTIMES 2	//����ͼ����������

/*
״̬����
*/
#define LOGINSTU 1		//ѧ����¼
#define LOGINTEA 2		//��ʦ��¼
#define LOGOUT 0		//�ǳ�
#define EXIT -1			//�˳�ϵͳ


/*
����
*/
typedef enum TYPE{  //ͼ������ö��
	BOOK,PERIODICAL,PRESS
}TYPE;

/*
����
*/
struct tm {
	int tm_mday;      /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	int tm_mon;       /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
	int tm_year;      /* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 */
	int tm_yday;	  /* ��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ����� */
};

int bookID = 0; 
date today;
int DDLTime = 30;
double penalty = 0.1;