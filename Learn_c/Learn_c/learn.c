#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

float values[5];
float *vp;
//123
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
//	//����д����Ȼ�����һ��������Ӧ�ñ���ڶ���д������Ϊ��׼�������У������Ǳ�׼�涨����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚϣ����ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽϡ�
//	
//}


//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);  //������������Ԫ�أ����ף���ַ
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int *p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%p <==> %p\n", &arr[i], p + i);//˵��arr[i]��p+i���һ��
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



//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *p = arr;
//	printf("%d\n", 2[arr]);
//	printf("%d\n", arr[2]);//[]�Ǹ�������������ɽ���
//	printf("%d\n", p[2]);//˵��p[2]Ҳ��ת��Ϊ*��p+2��
//	//��Ϊ�������ڴ���arr[2]��ʱ��ʵ�����ǽ�arr[2]����Ϊ*(arr+2),���Կ��Խ�����
//
//
//	//arr[2] --> *(arr+2) --> *(2+arr) --> 2[arr]
//	//arr[2] <==> *(arr+2) <==> *(p+2) <==> *(2+p)
//	//arr[2] <==> 2[arr]
//	return 0;
//}



int main()
{

	return 0;
}