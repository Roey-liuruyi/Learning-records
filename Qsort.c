#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Qsort.h"
#include<string.h>
//������bbsort()ð������
//int bbsort(int arr[], int sz)
//{
//	int i = 0;//��������
//	for (i = 0; i < sz - 1; i++)//��Ϊi�Ǵ�0��ʼ,����i�󲻴��Ⱥ�
//	{
//		//ÿ��ð������
//		int j = 0;//���������������±�
//		for (j = 0; j < sz - 1 - i; j++)//i=0,10��Ԫ�ػ�9��,��������
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}//ʵ���ϵ���˼��,ÿ�αȽϺ�,�ٲ�����һ�αȽϵĶ����Ǹ������
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
//����ʵ��Qsort����ߣ��
struct stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//�Ƚ���������ֵ
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
	//��ò�Ҫ�Խ����õĲ�ֵ����ǿ��ת��int,�������ܻᵼ��0.5->0;

}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ�������ֱ�ӽ��бȽ�,Ӧ����strcmp()���Ƚ�,��strcmp��qsort�ķ���ֵ��Ч����ͬ
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
//дQsort�ĳ���Ա����֪���Ƚ�����Ԫ�ص����ͺʹ�С
void Qsort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{//
	int i = 0;//��������
	for (i = 0; i < sz - 1; i++)//��Ϊi�Ǵ�0��ʼ,����i�󲻴��Ⱥ�
	{
		//ÿ��ð������
		int j = 0;//���������������±�
		for (j = 0; j < sz - 1 - i; j++)//i=0,10��Ԫ�ػ�9��,��������
		{
		    //��αȽ�
			if (cmp((char*)base+j*width, (char*)base + (j+1) * width)>0)
			{
				swap(width, (char*)base + j * width, (char*)base + (j + 1) * width);
			 //����
			}//ʵ���ϵ���˼��,ÿ�αȽϺ�,�ٲ�����һ�αȽϵĶ����Ǹ������
		}

	}
	//��һ������ �������������Ԫ�صĵ�ַ
//�ڶ������� ������������Ԫ�ظ���
//���������� ÿ��Ԫ�����͵Ĵ�С-��λ���ֽ�
//���ĸ����� �ȽϺ���-�ĺ���ָ��-�ú�����Ҫqsort����ʹ�����Լ�ʵ��
//�����Ĳ�����:���Ƚϵ�����Ԫ�صĵ�ַ
}
//int(*cmp)(const void*e1,const void*e2)
//�Ǻ���ָ��
//�����ķ���ֵΪint
//�����Ĳ���������ָ��
//�������ָ����Ϊqsort()��һ������

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