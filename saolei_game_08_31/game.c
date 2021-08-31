#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//注意大小写的区别,原来参数是这样子加的啊
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//因为初始化的时候有区别
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf(" 0 ");
	for (i = 1; i <= row; i++)
	{//打印列数
		printf("#%d#", i);
	}
	printf("\n");//区分开棋盘
	for (i = 1; i <=row; i++)
	{
		printf("#%d#", i);
		for (j= 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	while (count)
	{
		int x = (rand() % row )+ 1;//实现1-9的控制
		int y = (rand() % col) + 1;//同上
		if (board[x][y] == '0')//字符零,所以要有单引号.意思是如果还未放置雷
		{
			board[x][y] = '1';//放雷,字符1.
			count--;//应该操作后再减
		}
		
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	 
	return mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] - 8 * '0';
	
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (1) 
	{
		printf("请输入排雷的坐标:>");
		scanf("%d%d", &x, &y);
		//检查坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col&&show[x][y]=='*')
		{
			if (mine[x][y] == '1')//踩雷!!!!!!!!字符1啊啊啊啊啊啊啊啊
			{
				printf("很遗憾,你被炸死了\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else//不是雷
			{
				//计算x,y坐标周围有多少个雷
				int count = get_mine_count(mine, x, y);//'1'-'0'=0
				show[x][y] = count + '0';//'count'得到了字符形式的
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("该坐标非法或已被占用,请重新输入!\n");  
		}
		if (win == (col * row - Easy_count))
		{
			printf("恭喜你,排雷成功\n");
			displayboard(mine, ROW, COL);
			break;//break不可以缺少.
	    } 
	}
	
}