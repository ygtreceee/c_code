/*
#include <stdio.h>
int main()
{
	int n = 0;
	int i,a;
	int ret = 1;
	while (scanf_s("%d ", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			if (i != n - 1)
			{
				scanf_s("%d ", &a);
			}
			else if(i == n - 1)
			{
				scanf_s("%d", &a);
			}
			if (a % 2 == 1)
			{
				ret *= a;
			}
		}
		printf("%d\n", ret);
		ret = 1;
	}
}
*/




#include <stdio.h>
int main()
{
	int m, n;
	int odd = 0;
	int even = 0;
	int i = 0;
	while (scanf_s("%d %d", &m, &n) != EOF)
	{
		for (i = m; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				odd += i * i * i;
			}
			if (i % 2 == 0)
			{
				even +=i*i;
			}
		}
		printf("%d %d\n", even,odd);
		odd = 0;
		even = 0;
	}
	return 0;
}




/*
#include <stdio.h>
#include <math.h>
int main()
{
	double n, m;
	int i;
	double sum = 0;
	while (scanf_s("%lf %lf",&n,&m) != EOF)
	{
		sum = n;
		for (i = 1; i < m; i++)
		{
			sum += sqrt(n);
			n = sqrt(n);
		}
		printf("%.2f\n", sum);
		sum = 0;
	}
	return 0;
}
*/
























