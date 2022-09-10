#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

float values[5];
float *vp;

int main()
{
	for (vp = &values[5]; vp > &values[0];)
	{
		*--vp = 0;
	}

	for (vp = &values[5 - 1]; vp >= &values[0]; vp--)
	{
		*vp = 0;
	}
	//两种写法虽然结果都一样，但是应该避免第二种写法，因为标准并不可行，理由是标准规定允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。
	
}


int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);  //数组名等于首元素（的首）地址
	return 0;
}


int main()
{
	int arr[10] = { 0 };
	int *p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		//printf("%p <==> %p\n", &arr[i], p + i);//说明arr[i]和p+i结果一致
		*(p+i)=i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
	}

	return 0;
}



int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = arr;
	printf("%d\n", 2[arr]);
	printf("%d\n", arr[2]);//[]是个操作符，内外可交换
	printf("%d\n", p[2]);//说明p[2]也是转化为*（p+2）
	//因为编译器在处理arr[2]的时候，实际上是将arr[2]编译为*(arr+2),所以可以交换。


	//arr[2] --> *(arr+2) --> *(2+arr) --> 2[arr]
	//arr[2] <==> *(arr+2) <==> *(p+2) <==> *(2+p)
	//arr[2] <==> 2[arr]
	return 0;
}



int main()
{
	int a = 10;
	int *pa = &a;//pa是指针变量，pa是一级指针
	int **ppa = &pa;//pa也是一个变量，ppa是一个二级指针变量，&pa取出pa在内存中的地址

    //二级指针有两层指向关系
	//*ppa == pa     *pa == a     所以**ppa == a
	//以此类推还有三级指针（***pppa）等等，但是很少用到
	return 0;
}


int main()
{
	int arr[10];//整型数组——存放整形的数组就是整型数组
	char ch[5];//字符数组——存放字符的数组就是字符数组
	//指针数组——存放指针的数组
	int* parr[5];//整型指针的数组
	char* par[5];//字符指针的数组
	return 0;
}


//数组：一组相同类型元素的集合
//结构体：也是一些值的集合，但是值的类型可以不同，而这些值就称为成员变量

struct Stu
{
	char name[20];//名字
	int age;//年龄
	char id[20];//学号
	struct Stu sb;//结构体的成员可以是标量、数组、指针，也可以是另一个结构体
} s1, s2;//这里的s1和s2也是结构体变量，但区别就是在这里是全局变量，而下面的s是局部变量，所以不同的创建方式带来的效果也不一样
//struct是结构体关键字，注意大括号之后还有分号
//结构体的成员也可以是另一个结构体


int main()
{
	struct Stu s;//struct Stu是类型，s是对象
	return 0;
}

