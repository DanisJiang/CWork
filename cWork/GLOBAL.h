#pragma once

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


typedef struct date
{
	int year;
	int month;
	int day;
};

extern int bookID = 0; 
extern date today;
extern int borrowDDL = 30;