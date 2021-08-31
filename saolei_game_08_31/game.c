#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//ע���Сд������,ԭ�������������Ӽӵİ�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//��Ϊ��ʼ����ʱ��������
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf(" 0 ");
	for (i = 1; i <= row; i++)
	{//��ӡ����
		printf("#%d#", i);
	}
	printf("\n");//���ֿ�����
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
		int x = (rand() % row )+ 1;//ʵ��1-9�Ŀ���
		int y = (rand() % col) + 1;//ͬ��
		if (board[x][y] == '0')//�ַ���,����Ҫ�е�����.��˼�������δ������
		{
			board[x][y] = '1';//����,�ַ�1.
			count--;//Ӧ�ò������ټ�
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
		printf("���������׵�����:>");
		scanf("%d%d", &x, &y);
		//�������ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col&&show[x][y]=='*')
		{
			if (mine[x][y] == '1')//����!!!!!!!!�ַ�1����������������
			{
				printf("���ź�,�㱻ը����\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else//������
			{
				//����x,y������Χ�ж��ٸ���
				int count = get_mine_count(mine, x, y);//'1'-'0'=0
				show[x][y] = count + '0';//'count'�õ����ַ���ʽ��
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("������Ƿ����ѱ�ռ��,����������!\n");  
		}
		if (win == (col * row - Easy_count))
		{
			printf("��ϲ��,���׳ɹ�\n");
			displayboard(mine, ROW, COL);
			break;//break������ȱ��.
	    } 
	}
	
}