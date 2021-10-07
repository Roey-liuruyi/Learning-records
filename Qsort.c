#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Qsort.h"
#include<string.h>
//先引入bbsort()冒泡排序
//int bbsort(int arr[], int sz)
//{
//	int i = 0;//代表趟数
//	for (i = 0; i < sz - 1; i++)//因为i是从0开始,所以i后不带等号
//	{
//		//每趟冒泡排序
//		int j = 0;//这个整的是数组的下标
//		for (j = 0; j < sz - 1 - i; j++)//i=0,10个元素换9回,依次类推
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}//实际上的意思是,每次比较后,再参与下一次比较的都是那个大的数
//		}
//
//	}
//}
//int main()
//{
	//int arr[10] = { 9,8,1,2,3,4,5,6,7,0 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//bbsort(arr,sz);
	//int i = 0;
	//for (i=0;i<sz;i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//return 0;
//}
//而后实现Qsort的手撸版
struct stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整形值
	return *(int*)e1 - *(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 > *(float*)e2)
		return 1;
	else if (*(float*)e1 == *(float*)e2)
		return 0;
	else
		return -1;
	//最好不要对解引用的差值进行强制转换int,这样可能会导致0.5->0;

}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串不能直接进行比较,应当用strcmp()来比较,而strcmp与qsort的返回值的效果相同
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
void swap(int width, char* buf1, char* buf2)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
//写Qsort的程序员并不知道比较数组元素的类型和大小
void Qsort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{//
	int i = 0;//代表趟数
	for (i = 0; i < sz - 1; i++)//因为i是从0开始,所以i后不带等号
	{
		//每趟冒泡排序
		int j = 0;//这个整的是数组的下标
		for (j = 0; j < sz - 1 - i; j++)//i=0,10个元素换9回,依次类推
		{
		    //如何比较
			if (cmp((char*)base+j*width, (char*)base + (j+1) * width)>0)
			{
				swap(width, (char*)base + j * width, (char*)base + (j + 1) * width);
			 //交换
			}//实际上的意思是,每次比较后,再参与下一次比较的都是那个大的数
		}

	}
	//第一个参数 待排序的数组首元素的地址
//第二个参数 待排序的数组的元素个数
//第三个参数 每个元素类型的大小-单位是字节
//第四个函数 比较函数-的函数指针-该函数需要qsort函数使用者自己实现
//函数的参数是:待比较的两个元素的地址
}
//int(*cmp)(const void*e1,const void*e2)
//是函数指针
//函数的返回值为int
//函数的参数是两个指针
//这个函数指针作为qsort()的一个参数

void test1()
{
	int arr[10] = { 9,8,1,2,3,4,5,6,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Qsort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2()
{
	float f[] = { 9.0,8.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,0.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	Qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
	printf("\n");
}
void test3()
{
	struct stu s[3] = { {"zhangsan",20},{"liis",10},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	Qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i].age);
	}
	printf("\n");
}
void test4()
{
	struct stu s[3] = { {"zhangsan",20},{"liis",10},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	Qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}
	printf("\n");
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}