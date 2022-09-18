//
//
////超重青蛙
// #include <stdio.h>
//int main()
//{
//	int t = 0;
//	scanf_s("%d", &t);//有t个测试实例
//	int i, j, n;
//	int count=0;
//	int arr[100];
//	int aver=0;
//	int total=0;
//	for (i = 0; i < t; i++)
//	{
//		scanf_s("%d", &n);//这一组青蛙的数量
//		for (j = 0; j < n; j++)
//		{
//			scanf_s("%d",&arr[j]);//青蛙的体重
//			total += arr[j];
//		}
//			aver = total / n;
//		for (j = 0; j < n; j++)
//		{
//			if (arr[j] > aver)
//				count++;
//		}
//		printf("%d", count);//输出每一组青蛙中，超出平均体重的青蛙个数
//	}
//	return 0;
//}
//
//
//
////输入两个正整数，输出其最大公倍数(1)
//int main()
//{
//	int a=0, b=0;
//	scanf_s("%d %d", &a, &b);
//	int min = a > b ? a : b;
//	while (1)
//	{
//		if (min % a == 0 && min % b == 0)
//		{
//			printf("%d", min);
//			break;
//		}
//		else
//			min++;
//	}
//	return 0;
//}
//
//
////输入两个正整数，输出其最大公倍数(2)
//int main()
//{
//	int a, b;
//	scanf_s("%d %d", &a, &b);
//	int i = 1;
//	for (i = 1;; i++)
//	{
//		if (a * i % b == 0)
//		{
//			printf("%d", a * i);
//			break;
//		}
//	}
//	return 0;
//}
//
//
//
////将一句话的单词进行倒置，标点不倒置
//#include <stdio.h>
//#include <string.h>
//void reverse(char* left, char* right)
//{
//	while(left<right)
//	{
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	//输入
//	gets(arr);
//	//三步翻转法
//	//1.字符串整体倒置
//	int len = strlen(arr);
//	reverse(arr, arr + len - 1);
//	//2.每个单词逆序
//	char* start = arr;
//	while (*start)
//	{
//		char* end = start;
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		reverse(start, end-1);
//		if (*end == ' ')
//		{
//			start = end + 1;
//		}
//		else
//			start = end;
//	}
//	printf("%s\n", arr);
//	return 0;
//}


#include <stdio.h>
int main()
{
	int M = 0;
	int N, K;
	scanf_s("%d %d", &N, &K);
	int sum,i,price;
	int year = 0;
	for (i = 1;; i++)
	{
		sum = i * N;
		price = 200 * (1 + K*0.01);
		year++;
		if (sum > price && year <= 20)
		{
			M = sum / price;
			printf("%d", M);
			break;
		}
		else(year > 20);
		{
			printf("Impossible");
			break;
		}
	}
	return 0;
}