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
	//两种写法虽然结果都一样，但是应该避免第二种写法，因为标准并不可行，理由是标准规定允许指向数组元素的指针与指向数组最后一个元
	//素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。
	
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
	print1(s);//传值调用（在时间和空间上产生浪费），函数传参的时候，参数是需要压栈的，如果传递一个结构体对象的时候，结构体过大，参数
     //          压栈的系统开销比较大，会导致性能的下降
	print2(&s);//传址调用（效率高且便于改变），是最优选择
	return 0;
}

//涉及到关于“压栈”问题
//栈是一种数据结构，是一种只能在一端进行插入和删除操作的特殊线性表。它按照先进后出的原则存储数据，先进入的数据被压入栈底，最后的数据
//      在栈顶，需要读数据的时候从栈顶开始弹出数据（最后放入的数据被最先读出来）
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
//const修饰指针变量的时候，如果放在*左边，例如const int* p  修饰的是*p，表示指针指向的内容，是不能通过指针来改变的,但是指针变
//     量本身是可以修改的，例如p=&n；如果放在*右边，例如int* const p,修饰的是p，表示指针变量p本身，则p不能被改变，即不能够p=&n，
//     但是它所指向的内容是可以改变的，例如*p=10；但是还可以双const，例如int const* const p


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



//判断一个数的二进制中有几个1
//方法一
int Numberof1(int a)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((a >> i) & 1 == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	int num= Numberof1(a);
	printf("%d", num);
	return 0;
}
//方法二
int main()
{
	int count = 0;
	int n = 10;
	while (n)
	{
		n = n & (n - 1);//利用n&（n-1）会使得其二进制数最后一位变为0，直到全部位都变为0即可
		count++;
	}
	printf("%d", count);
	return 0;
}


//判断一个数是不是2的n次方
//n&(n-1)==0即为所求 


//判断两个整数二进制格式有多少个位不同
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++
	{
		(m>>i)&1
	}
	return 0;
}





////深度剖析数据在内存中的存储


//类型的基本归类
//整型家族：char   unsigned char   signed char   （由于字符类型底层存储的时候存储的是这个字符的ASCII码值，ASCII值也是个整数，所以归类
//           的时候把char类型归类到整型）
//         short   unsigned short[int]   signed short[int]     (最大为65535)
//          int    unsigned int    signed int                  (最大为4294967295)
//         long    unsigned long[int]   signed long[int]
//（unsigned代表无符号，适用于创建的数都是正数；signed代表有符号，有正有负）
//浮点数家族：float   double
//构造类型——自定义类型
//          struct结构体类型
//          数组(如arr[10])
//          enum 枚举
//          union 联合体
//指针类型
//          int* pi
//          char* pc
//          float* pf
//          void* pv
//空类型:void表示空类型（无类型），通常用于函数的返回类型void test()、函数的参数void test(void)、指针类型void* pv


//整型在内存中的存储
//数据在内存中以二进制的形式进行存储，对于整数来说，整数二进制有3种表示形式：原码、反码、补码
// 按照数据的数值直接写出的二进制序列就是原码，原码的符号位不变，其他位按位取反，得到的就是反码，反码+1得到的就是补码
//正整数：原码、反码、补码相同
//负整数：原码、反码、补码要进行计算
//整数在内存中存储的是补码，原因是使用补码可以将符号位和数值域统一处理，同时加法和减法也可以统一处理（CPU只有加法处理器），此外，反码和
//    补码相互转换，其运算过程是相同的（补码再次按位取反加一又可以得到原码），不需要额外的硬件电路

int main()
{
	char a = -1;//首先，-1的二进制为10000000000000000000000000000001，在内存中的补码为11111111111111111111111111111111，由于char的大小
			   //是一个字符，所以会发生截断，只能存11111111，然后打印的又是%d，即一个整型，所以又要发生整型提升，由于char是有符号的，
			   //所以提升为11111111111111111111111111111111，再打印出原码就是10000000000000000000000000000001，即-1
	signed char b = -1;//signed表示有符号，所以同上
	unsigned char c = -1;//无符号整型，高位补零，从11111111变成00000000000000000000000011111111，即c=255
	printf("a=%d b=%d c=%d", a, b, c);//a=-1 b=-1 c=255
	return 0;
}

int main()
{
	char a = -128;
	//10000000000000000000000010000000 原码
	//11111111111111111111111101111111 反码
	//11111111111111111111111110000000 补码
	//10000000 储存一个字节
	//11111111111111111111111110000000 char是有符号整型，高位是符号位，整型提升时前面全部补1，而打印是打印unsigned int，所以高位1应该看
	//                                 作运算位，不是符号位(打印的是一个整型，就要进行整型提升，但是无论打印的是有符号还是无符号，整型
	//                                 提升的时候都是按照符号位进行提升的）
	//                                 同时注意，printf打印的是%u，无符号整型认为原码反码补码全相同，但如果是%d，则还需转化为原码
	printf("%u\n", a);//a=4294967168
	return 0;
}

int main()
{
	char a = 128;
	//0000000000000000000000001000000
	//10000000
	//整型提升的时候，是按照原来a的类型，即char来进行提升的，而char是有符号的，所以认为高位是符号位，整型提升为
	//1111111111111111111111111000000 （此时为补码）
	printf("%u\n", a);//a=4294967168
	return 0;
}

int main()
{
	int i = -20;
	//10000000000000000000000000010100
	//11111111111111111111111111101011
	//11111111111111111111111111101100
	unsigned int j = 10;
	//00000000000000000000000000001010
	printf("%d\n", i + j);
	//11111111111111111111111111101100
	//00000000000000000000000000001010
	//11111111111111111111111111110110 -相加得到的补码
	//11111111111111111111111111110101
	//10000000000000000000000000001010  -> -10
	return 0;
}

//有符号的char的取值范围是-128~127

//补充：
//1.char到底是signed char还是unsigned char，c语言标准并没有规定，取决于编译器，且大部分编译器都是signed char；但是int有规定是signed int、
//   short是signed short
//



















//大小端
//大端（存储）模式：是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
//小端（存储）模式：是指数据的低位保存在内存的低地址中，而数据的高位，保存在内存的高地址中；
//
//
//判断机器的字节序
int main()
{
	int a = 1;
	char* pc = (char*)&a;//对指针进行强制类型转换
	if (*pc == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
//or
int check_sys()
{
	int a = 1;
	char* pc = (char*)&a;
	return *pc;
}
int main()
{
	int ret = check_sys();
	if (ret = 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
