#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_count 10//雷的个数
#include<stdio.h>
#include<time.h>
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);//这个一定要与mine数组的保持一致,
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
