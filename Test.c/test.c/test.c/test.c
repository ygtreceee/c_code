

//#include <stdio.h>
//int main()
//{
//	printf("Hello, World!");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%c", (char)a);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("        ********\n");
//	printf("       ************\n");
//	printf("       ####....#.\n");
//	printf("     #..###.....##....\n");
//	printf("     ###.......######\n");
//	printf("        ...........\n");
//	printf("       ##*#######\n");
//	printf("    ####*******######\n");
//	printf("   ...#***.****.*###....\n");
//	printf("   ....**********##.....\n");
//	printf("   ....****    *****....\n");
//	printf("     ####        ####   \n");
//	printf("   ######        ######\n");
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int A, B;
//	scanf("%d %d", &A, &B);
//	printf("%d", A + B);
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    int A, B;
//    scanf("%d %d", &A, &B);
//    printf("%d", A * B);
//    return 0;
//}



//#include <stdio.h>
//int main()
//{
//	printf("************");
//	printf("Welcome");
//	printf("************");
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int F;
//	scanf_s("%d", &F);
//	printf("Celsius = %d", 5 * (F - 32) / 9);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int math, eng, comp, average;
//	scanf_s("%d %d %d", &math, &eng, &comp);
//	average = (math + eng + comp) / 3;
//	printf("math = %d, eng = %d, comp = %d, average = %d", math, eng, comp, average);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int x;
//	scanf_s("%d", &x);
//	if (x == 0)
//	{
//		printf("f(0.0) = 0.0");
//	}
//	else
//	{
//		printf("f(%.1f) = %.1f",x/1.0,1.0/x);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int N;
//	scanf_s("%d", &N);
//	if (N >= 100 && N <= 999)
//	{
//		int g, s, b;
//		b = N / 100;
//		s = (N % 100) / 10;
//		g = N % 10;
//		printf("%d = %d + %d*10 + %d*100", N, g, s, b);
//	}
//	else
//	{
//		printf("Invalid Value.");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a1, a2,dst,n;
//	scanf("%d %d %d", &a1, &a2,&n);
//	dst = a2 - a1;
//	printf("%d", a1 + (n - 1) * dst);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n <= 999 && n >= 100)
//	{
//		int g, s, b;
//		b = n / 100;
//		s = (n % 100) / 10;
//		g = n % 10;
//		printf("%d%d%d", g, s, b);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	int i = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("%d", b);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	double x;
//	scanf("%lf", &x);
//	printf("%.3f", x);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	double x;
//	scanf_s("%lf", &x);
//	printf("%.12f", x);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	double total, death;
//	scanf_s("%lf %lf", &total, &death);
//	printf("%.3f%%", death/total*100.000);
//	return 0;
//}

/*
#include <stdio.h>
int main()
{
    int score = 0;
	while (scanf_s("%d",&score) != EOF)
	{
		if (score >= 0 && score <= 100)
		{
			switch (score/10)
			{
			case 9:
				printf("A\n");
				break;
			case 8:
				printf("B\n");
				break;
			case 7:
				printf("C\n");
				break;
			case 6:
				printf("D\n");
				break;
			default:
				printf("E\n");
				break;
			}
		}
		else
		{
			printf("Score is error!\n");
		}
	}
	return 0;
}
*/


/*
#include <stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);
	if (n % 2 == 0)
		printf("even");
	else
		printf("odd");
	return 0;
}
*/


/*
#include <stdio.h>
int main()
{
	int i,n;
	scanf_s("%d", &n);
	int ret = 1;
	for (i = 0; i < n; i++)
	{
		ret *= 2;
	}
	printf("%d", ret);
	return 0;
}
*/











