#pragma once
/*ȫ�ֱ������궨��*/


#define MAX 20			//������ֶ�
#define MAXLENGTH 999	//�����ͼ��
#define MAXPERSON 20	//���ѧ������
#define BRORROW 5		//ѧ��������ͼ�鱾��
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
	NOVEL,ESSAY,POEM,TECH,
}TYPE;