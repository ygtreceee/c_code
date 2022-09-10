#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

float values[5];
float *vp;
//
//int main()
//{
//	for (vp = &values[5]; vp > &values[0];)
//	{
//		*--vp = 0;
//	}
//
//	for (vp = &values[5 - 1]; vp >= &values[0]; vp--)
//	{
//		*vp = 0;
//	}
//	//两种写法虽然结果都一样，但是应该避免第二种写法，因为标准并不可行，理由是标准规定允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。
//	
//}


//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);  //数组名等于首元素（的首）地址
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int *p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%p <==> %p\n", &arr[i], p + i);//说明arr[i]和p+i结果一致
//		*(p+i)=i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//
//	return 0;
//}



int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = arr;
	printf("%d\n", 2[arr]);
	printf("%d\n", arr[2]);//[]是个操作符，内外可交换
	//因为编译器在处理arr[2]的时候，实际上是将arr[2]编译为*(arr+2),所以可以交换。
	return 0;
}