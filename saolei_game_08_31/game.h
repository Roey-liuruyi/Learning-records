#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_count 10//�׵ĸ���
#include<stdio.h>
#include<time.h>
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);//���һ��Ҫ��mine����ı���һ��,
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
