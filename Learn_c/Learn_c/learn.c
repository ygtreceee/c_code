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
	struct B sb;//结构体的成员可以是标量、数组、指针，也可以是另一个结构体
	char name[20];//名字
	int age;//年龄
	char id[20];//学号
} s1, s2;//这里的s1和s2也是结构体变量，但区别就是在这里是全局变量，而下面的s是局部变量，所以不同的创建方式带来的效果也不一样
//struct是结构体关键字，注意大括号之后还有分号
//结构体的成员也可以是另一个结构体

struct B
{
	char c;
	short s;
	double d;
};

int main()
{
	struct Stu s = { { 'w', 20, 3.14 }, "zhangsan", 30, "202200202" };//struct Stu是类型，s是对象,对其进行初始化
	return 0;
}

struct Point
{
	int x;
	int y;
};

struct Node
{
	int data;
	struct Point p;
	struct Node* next;
}n1 = { 10, { 4, 5 }, NULL };//结构体嵌套初始化

struct Node n2 = { 20, { 4, 5 }, NULL };//结构体嵌套初始化


//结构体成员的访问
int main()
{
	struct Stu s = { { 'w', 20, 3.14 }, "zhangsan", 30, "202200202" };//struct Stu是类型，s是对象,对其进行初始化
	//.  ->
	printf("%c ", s.sb.c);
	printf("%s ", s.id);

	struct Stu *ps = &s;
	printf("%c ", (*ps).sb.c);
	printf("%c ", ps->sb.c);//->用于指针
	return 0;
}


//结构体传参
void print1(struct Stu t)
{
	printf("%c %d %lf %s %d %s", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.id);
}

void print2(struct Stu *ps)
{
	printf("%c %d %lf %s %d %s", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
}

int main()
{
	struct Stu s = { { 'w', 20, 3.14 }, "zhangsan", 30, "202200202" };
	//写一个函数打印s的内容
	print1(s);//传值调用（在时间和空间上产生浪费），函数传参的时候，参数是需要压栈的，如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，会导致性能的下降
	print2(&s);//传址调用（效率高且便于改变），是最优选择
	return 0;
}

//涉及到关于“压栈”问题
//栈是一种数据结构，是一种只能在一端进行插入和删除操作的特殊线性表。它按照先进后出的原则存储数据，先进入的数据被压入栈底，最后的数据在栈顶，需要读数据的时候从栈顶开始弹出数据（最后放入的数据被最先读出来）
//栈帧：C语言中，每个栈帧对应着一个未运行完的函数；栈帧中保存了该函数的返回地址和局部变量
//内存分区：内存中主要分为栈区，堆区，静态区，以及其他部分
//    栈区：由高地址往低地址增长，主要用来存放局部变量，函数调用开辟的空间，与堆共享一段空间
//    堆区：由低地址向高地址增长，动态开辟的空间就在这里（malloc，realloc，calloc，free），与栈共享一段空间
//    静态区：主要存放全局变量和静态变量
////栈帧创建与销毁
//此处还需注意内存空间的栈和数据结构的栈是不同的，内存空间是真实存在的物理区，而数据结构的栈可以理解为是数据存储结构

//数组随着下标的增长地址由低到高变化，栈区内存的使用习惯是由高到低


////学习调试
//调试的基本步骤：
//发现程序错误的存在
//以隔离、消除等方式对错误进行定位
//确定错误产生的原因
//提出纠正错误的解决方法
//对程序错误予以纠正，重新测试
//常见错误：编译型错误、链接型错误、运行时错误

//代码中加上assert（断言）可以帮助快速找到代码的问题所在

//const修饰变量，这个变量就变成常变量，不可被修改，但是本质还是变量
//const修饰指针变量的时候，如果放在*左边，例如const int* p  修饰的是*p，表示指针指向的内容，是不能通过指针来改变的,但是指针变量本身是可以修改的，例如p=&n；
//     如果放在*右边，例如int* const p,修饰的是p，表示指针变量p本身，则p不能被改变，即不能够p=&n，但是它所指向的内容是可以改变的，例如*p=10；但是还可以双const，例如int const* const p


//模拟实现strcpy
#include <assert.h>
char* my_strcpy(char* dest,const char* sour)
{
	assert(*dest != NULL);//断言
	assert(*sour != NULL);
	char* ret = dest;
	while (*dest++ = *sour++)
	{
		;//hello的拷贝
	}
	return ret;//返回目标空间的起始地址
}
//源代码
char* _cdecl strcpy(char* dst, const char* src)
{
	char* cp = dst;
	while (*dst++ = *src++);
	return (dst);
}

int main()
{
	char arr1[20] = "xxxxxxxxxx";
	char arr2[] = "hello";
	//1.目标空间的起始地址 2.源空间的起始地址
	printf("%s\n", my_strcpy(arr1, arr2));//链式访问
	return 0;
}


//模拟实现strlen
size_t my_strlen(const char* str)//size_t是unsigned int ,表示无符号整型，即count不可能为负数
{
	assert(*str != NULL);
	size_t count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[] = "Hello world";
	printf("%d\n", my_strlen(arr));
	return 0;
}

//数组名是首元素地址，而且对于这个地址，是不可变的，即为常量，存放于静态区


//声明外部符号用extern



