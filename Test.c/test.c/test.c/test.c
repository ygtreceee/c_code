#include <stdio.h>
int main()
{
	int n,min;
	int tmp = 0;
	int arr[100] = { 0 };
	int i = 0;
	while (scanf("%d", &n) != EOF){
		if (n == 0){
			break;
		}
		for (i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		min = arr[0];
		for (i = 0; i < n; i++){
			if (arr[i] < min){
				tmp = i;
				min = arr[i];
			}
		}
		arr[tmp] = arr[0];
		arr[0] = min;
		for (i = 0; i < n; i++){
			if (i != 0)printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}







