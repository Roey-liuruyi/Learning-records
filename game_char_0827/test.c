#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**********请选择是否开始游戏************\n");
	printf("********1.开始游戏***0.退出游戏*********\n");
	printf("***************************************\n");
}
void game()//游戏代码的实现
{
	char board [ROW][COL] = { 0 };//希望数组里面都是空格,零是不可打印字符
	//初始化棋盘, 防止出现问题.
	initboard(board, ROW, COL);
	displayboard(board,ROW,COL);
	char ret;
	while (1)
	{
		//玩家下棋
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断用户是否赢
		ret = ISwin(board, ROW, COL);
		 if (ret != 'C')
		 {
			 break;
		 }
		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret = ISwin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	 srand((unsigned int)time(NULL));//时间戳的随机值生成器
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//不能加\n
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误,请重新输入\n");
				break;
			}
	} while (input);
}
int main()
{
	test();


	return 0;
}
