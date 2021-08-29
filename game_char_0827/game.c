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
			printf(" %c ", board[i][j]);//��ӡ��һ�е�����
			if (j < col - 1)
			{
				printf("|");//��ӡ�ָ���
			}
		}
		printf("\n");
		if (i < row - 1)//���һ�����治�ô�ӡ
		{
			for (j = 0; j < col; j++)
			{
printf("---");//��ӡ�ָ���
if (j < col - 1)
{
	printf("|");//��ӡ�ָ���
}
			}
		}
		printf("\n");//���һ������Ҳ��Ҫ����
	}
}

////��ӡһ������
//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
////��ӡ�ָ���
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
	printf("���������\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);//��������
		//�ж�x,y������ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�����û�ϰ�߽�������
		{
			if (board[x - 1][y - 1] == ' ')//�û��Ѻ���
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ��");
			}
		}
		else
		{
			printf("����Ƿ�,����������!!!");
		}
	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������:>\n");
	//x = rand() % row;//֮���������0��row-1;��Ҫ����whileѭ�������ֻ������һ��
	//y = rand() % col;//ͬ��,��������ֵ������Ƿ�
	while (1)
	{
		x = rand() % row;//֮���������0��row-1;
		y = rand() % col;//ͬ��,��������ֵ������Ƿ�
		if (board[x][y] == ' ')//�û��Ѻ��Ͳ����ʺ�
		{
			board[x][y] = '#';
			break;
		}
		/*else
		{
			printf("�������ѱ�ռ��");//��Ϊ���ǵ���������.
		}*/
	}
}
int ISfull(char board[ROW][COL], int row, int col)//����1��ʾ��������,����0��ʾ����û��
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
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//������
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[2][j]==board[1][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
    }
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == ISfull(board, ROW, COL))
	{
		return'Q';
	}
	return 'C';
}
