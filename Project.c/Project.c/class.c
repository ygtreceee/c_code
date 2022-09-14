

//超重青蛙
#include <stdio.h>
int main()
{
	int t = 0;
	scanf_s("%d", &t);//有t个测试实例
	int i, j, n;
	int count=0;
	int arr[100];
	int aver=0;
	int total=0;
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);//这一组青蛙的数量
		for (j = 0; j < n; j++)
		{
			scanf_s("%d",&arr[j]);//青蛙的体重
			total += arr[j];
		}
			aver = total / n;
		for (j = 0; j < n; j++)
		{
			if (arr[j] > aver)
				count++;
		}
		printf("%d", count);//输出每一组青蛙中，超出平均体重的青蛙个数
	}
	return 0;
}