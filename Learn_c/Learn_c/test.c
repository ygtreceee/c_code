#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof (arr) / sizeof (arr[0]);
	for (i = 0; i < sz; i++)
	{
		arr[i] = i + 1;
	}
	return 0;
}