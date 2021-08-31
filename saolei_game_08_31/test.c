#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void game()
{
	
	//1.布置好雷的消息
	char mine[ROWS][COLS] = { 0 };
	//2.排查好雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化函数
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	displayboard(mine, ROW, COL);
	/*displayboard(show, ROW, COL);*///传的时候需要传原始的数组,但是修改什么可以有自己决定
	//布置雷
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine,show,ROW,COL);//操作的是中间9*9的
}
void menu()
{
	printf("*******************************************\n");
	printf("**************请选择是否开始游戏*************\n");
	printf("*******1.play*****************0.exit********\n");
	printf("*******************************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));//只执行一次所以放在这里
	int input;//使得default仍能重新输入,//不给定值也行.
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://此处应有空格
			game();
			/*printf("开始游戏\n");*/
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新选择\n");
			break;
		}
			
	} while (input);//当input=1时候进行循环,input=0时候退出,满足了条件.
	
}
int main()
{
	test();

}