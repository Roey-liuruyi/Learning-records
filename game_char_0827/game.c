#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include"game.h"
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//打印这一行的数据
			if (j < col - 1)
			{
				printf("|");//打印分格列
			}
		}
		printf("\n");
		if (i < row - 1)//最后一行下面不用打印
		{
			for (j = 0; j < col; j++)
			{
printf("---");//打印分割行
if (j < col - 1)
{
	printf("|");//打印分割列
}
			}
		}
		printf("\n");//最后一行下面也需要换行
	}
}

////打印一行数据
//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
////打印分隔符
//if (i < row - 1)
//{
//	printf("---|---|---\n");
//}

//   |   |    
//---|---|---
//   |   |   
//---|---|---
//   |   |   

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请玩家下棋\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);//输入坐标
		//判断x,y的坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)//按照用户习惯进行设置
		{
			if (board[x - 1][y - 1] == ' ')//用户友好型
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用");
			}
		}
		else
		{
			printf("坐标非法,请重新输入!!!");
		}
	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋:>\n");
	//x = rand() % row;//之后的余数是0到row-1;需要放在while循环里否则只生成了一次
	//y = rand() % col;//同理,所以两个值都不会非法
	while (1)
	{
		x = rand() % row;//之后的余数是0到row-1;
		y = rand() % col;//同理,所以两个值都不会非法
		if (board[x][y] == ' ')//用户友好型不再适合
		{
			board[x][y] = '#';
			break;
		}
		/*else
		{
			printf("该坐标已被占用");//因为这是电脑下棋嘛.
		}*/
	}
}
int ISfull(char board[ROW][COL], int row, int col)//返回1表示棋盘满了,返回0表示棋盘没满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}
char ISwin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[2][j]==board[1][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
    }
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (1 == ISfull(board, ROW, COL))
	{
		return'Q';
	}
	return 'C';
}
