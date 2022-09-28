//
//#include <stdio.h>
//int g(int n, int m)
//{
//	int sum = 0;
//	while (n)
//	{
//		sum += n % m;
//		n = n / m;
//	}
//	return sum;
//}
//int main()
//{
//	int a,b,c,n;
//	while (scanf_s("%d", &n) != EOF && n!=0)
//	{
//		a = g(n, 10);
//		b = g(n, 12);
//		c = g(n, 16);
//		if (a==b && a==c && b==c)
//		{
//			printf("%ld is a Sky Number.\n",n);
//		}
//		else
//		{
//			printf("%ld is not a Sky Number.\n",n);
//		}
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	char arr[30] = { 0 };
//	char a, b;
//	while (scanf("%s", arr) != EOF)
//	{
//		getchar();
//		scanf("%c", &a);
//		getchar();
//		scanf("%c", &b);
//		int i = 0;
//		while(arr[i]!='\0')
//		{
//			if (arr[i] == a)
//			{
//				arr[i] = b;
//			}
//			i++;
//		}
//		printf("%s\n", arr);
//	}
//}



//ถþฮฌสýื้

#include <stdio.h>
int main()
{
	int n = 0,count=0;
	char a[100][200];
	int b[100];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(a[i]);
		for (int j = 0; a[i][j] != '\0'; j++)
		{
			if (a[i][j] == 1)
			{
				count++;
			}
		}
		b[i] = count;
		count = 0;
	}
		int x = 0;
		int tmp=0;
		for (int i=0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[j] > tmp && j != x)
				{
					x = j;
					tmp = b[j];
				}
			}
			printf("%s\n", a[x]);
		}
}