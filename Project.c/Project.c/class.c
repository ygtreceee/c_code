

//��������
#include <stdio.h>
int main()
{
	int t = 0;
	scanf_s("%d", &t);//��t������ʵ��
	int i, j, n;
	int count=0;
	int arr[100];
	int aver=0;
	int total=0;
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);//��һ�����ܵ�����
		for (j = 0; j < n; j++)
		{
			scanf_s("%d",&arr[j]);//���ܵ�����
			total += arr[j];
		}
			aver = total / n;
		for (j = 0; j < n; j++)
		{
			if (arr[j] > aver)
				count++;
		}
		printf("%d", count);//���ÿһ�������У�����ƽ�����ص����ܸ���
	}
	return 0;
}