/*
班级：XXX班
姓名: 刘如意
学号：2021
日期：2021-07-22
*/
#include<stdio.h>/*这里是用别人的，所以要打个招呼，标准输入输出*/
void main()/*起始点，作为起始密码子开始的，只能有一个*/
{
	const double Pi = 3.1415;
	double C = 0, S = 0, r = 0;
	printf("请输入圆的半径：");/*print f 是库函数，是c语言提供给我们使用的，
					   打印函数，也就是在屏幕上投出来东西*/
	scanf_s("%lf", &r);
	C = 2 * Pi * r;
	S = Pi * r * r;
	printf("圆的周长为： % lf\n圆的面积为： % lf", C, S);
	return 0;/*返回int，也即是整形*/
}