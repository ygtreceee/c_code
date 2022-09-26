//#include <stdio.h>
//int main()
//{
//	char arr[100],max;
//	while (gets(arr)!= EOF)
//	{
//		max = arr[0];
//		for (int i = 0;arr[i] !='\0'; i++)
//		{
//			if (arr[i] > max)
//			{
//				max = arr[i];
//			}
//		}
//		for (int i = 0; arr[i] != '\0'; i++)
//		{
//			printf("%c", arr[i]);
//			if (arr[i]==max)printf("(max)");
//		}
//		printf("\n");
//	}
//	return 0;
//}



#include <stdio.h>
int main()
{
	char arr[100];
	gets(arr);
	printf("%s", arr);
	return 0;
}