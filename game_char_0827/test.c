#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**********��ѡ���Ƿ�ʼ��Ϸ************\n");
	printf("********1.��ʼ��Ϸ***0.�˳���Ϸ*********\n");
	printf("***************************************\n");
}
void game()//��Ϸ�����ʵ��
{
	char board [ROW][COL] = { 0 };//ϣ���������涼�ǿո�,���ǲ��ɴ�ӡ�ַ�
	//��ʼ������, ��ֹ��������.
	initboard(board, ROW, COL);
	displayboard(board,ROW,COL);
	char ret;
	while (1)
	{
		//�������
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж��û��Ƿ�Ӯ
		ret = ISwin(board, ROW, COL);
		 if (ret != 'C')
		 {
			 break;
		 }
		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = ISwin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	 srand((unsigned int)time(NULL));//ʱ��������ֵ������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//���ܼ�\n
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�������,����������\n");
				break;
			}
	} while (input);
}
int main()
{
	test();


	return 0;
}
