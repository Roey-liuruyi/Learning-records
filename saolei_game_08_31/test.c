#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void game()
{
	
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	displayboard(mine, ROW, COL);
	/*displayboard(show, ROW, COL);*///����ʱ����Ҫ��ԭʼ������,�����޸�ʲô�������Լ�����
	//������
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine,show,ROW,COL);//���������м�9*9��
}
void menu()
{
	printf("*******************************************\n");
	printf("**************��ѡ���Ƿ�ʼ��Ϸ*************\n");
	printf("*******1.play*****************0.exit********\n");
	printf("*******************************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));//ִֻ��һ�����Է�������
	int input;//ʹ��default������������,//������ֵҲ��.
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://�˴�Ӧ�пո�
			game();
			/*printf("��ʼ��Ϸ\n");*/
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,������ѡ��\n");
			break;
		}
			
	} while (input);//��input=1ʱ�����ѭ��,input=0ʱ���˳�,����������.
	
}
int main()
{
	test();

}