#include <stdio.h>
#include <math.h>
int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int i;
		int count = 0;
		for (i = m; i <= n; i++)
		{
			int num = 0;
			int tmp = i;
			while (tmp)
			{
				num++;
				tmp = tmp / 10;
			}
			int sum = 0;
			tmp = i;
			while(tmp)
			{
				sum += pow(tmp % 10, num);
				tmp = tmp / 10;
			}
			if (sum == i && count==0)
			{
				printf("%d", i);
				count++;
			}
			else if (sum == i && count !=0)
			{
				printf(" %d", i);
				count++;

			}
		}
		if (count == 0)
		{
			printf("no\n");
		}
		else
		{
			printf("\n");
		}
	}
	return;
}










