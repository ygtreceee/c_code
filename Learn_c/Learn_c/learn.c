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
	for (i = 0; i < 32; i++)
	{
		(m >> i) & 1;
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

int main()
{
	int a = -20;
	//10000000000000000000000000010100
	//11111111111111111111111111101011
	//11111111111111111111111111101100
	unsigned int b = 10;
	//00000000000000000000000000001010
	//11111111111111111111111111110110 （此处a+b会使结果默认被强制类型转换为unsigned int，如果打印，则直接打印补码，因为
	//                                   补码等于原码，且高位非符号位）
	//11111111111111111111111111110101
	//10000000000000000000000000001010 （若打印为%d，说明还要进行强制类型转化为int，即要将补码转换为原码，且高位为符号位）
	if (a + b > 0)
	{
		pritnf("a+b>0\n");//此行会被打印，可再次印证上面推论
	}
	printf("%u", a + b);//4294967286
	printf("%d", a + b);//-10（至于此处为什么会变成-10，因为虽然a+b在内存中是无符号整型，但是想要打印出来，还得以%后的类型为准，此处
	//                        为%d，所以无符号再次被强制类型转化为有符号，所以输出是-10）
	return 0;
}

int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;//此处涉及到char类型的二进制存储规律，从00000000到11111111并不是一个从小到大的过程，而是先从00000000到01111111，
//                      逐渐变大，即从0~127，然后01111111加1得到的10000000其实已经变成-128，然后从10000000到11111111是从-128到-1，因为高位
//                      为符号位，所以是一个循环，此题中strlen遇0即停，则从-1，-2，-3，-4，......,-127,-128,127,126,125,......,2,1,0,
//                      一共255个
	}
	printf("%d\n", strlen(a));//找到'\0' -> 0,打印为255
	return 0;
}
//可知：signed char 的取值范围是-128~127  unsigned char 的取值范围是0~255

//补充：char到底是signed char还是unsigned char，c语言标准并没有规定，取决于编译器，且大部分编译器都是signed char；但是int有规定是signed int、
//      short是signed short

#include <stdio.h>
int i;//i是全局变量，不初始化，默认是0
int main()
{
	i--;//i=-1
	//sizeof这个操作符，算出的结果的类型是unsigned int，所以前后比较的时候，会使得前面的i先转换为一个无符号数，是一个很大的数
	//类似于int类型与double类型相加得到double类型数
	if (i > sizeof(i))
	{
		printf(">\n");//be printed
	}
	else
	{
		printf("<\n");
	}
	return 0;
}



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



//浮点型在内存中的存储
//浮点数类型：float    double    long double 
//整型家族的取值范围定义在limits.h，浮点型取值范围定义在float.h
#include <limits.h>
int main()
{
	INT_MAX;//转到定义可以看每种类型的极值
	return 0;
}


//根据国际标准IEEE（电气与电子工程协会）754，任意一个二进制浮点数V可以表示成下面的形式：
//(-1)^S*M*2^E
// (-1)^S表示符号位，当S=0时，V为正数，当S=-1，V为负数
// M表示有效数字，大于等于1，小于2
// 2^E表示指数位
//e.g.浮点数：10.5 --10进制
//           101.1 --二进制（2^(-1)=0.5)
//           (-1)^0*1.01*2^2
//            S=0  M=1.01  E=2
//IEEE 754规定：对于32位的浮点数，最高的一位是符号位s，接着的8位是指数E，剩下的23位为有效数字M；对于64位的浮点数，最高的
//            一位是符号位s，接着的11位是指数E，剩下的52位为有效数字M
//IEEE 754对有效数字M和指数E，还有一些特别规定：前面说过，1<=M<2,也就是说，M可以写成1.xxxxxx的形式，其中xxxxxx表示小数部分。
//            754规定，在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxxxx部分，比如保存1.01时，
//            只保存01，等到读取的时候，再把第一位的1加上去，这样可以节省1位有效数字，以32位浮点数为例，留给M只有23位，将第
//            一位的1舍去以后，等于可以保存24位有效数字。
//            至于指数E，比较复杂：首先E为一个无符号整型（unsigned int),这意味着，如果E为8位，它的取值范围为0~255；如果E为11
//            位，它的取值范围为0~2047.但是，我们知道，科学计数法中的E是可以出现负数的，所以IEEE 754规定，存入内存时E的真实值
//            必须再加上一个中间数，对于8为的E，这个中间数是127，对于11位的E，这个中间数是1023。比如2^10的E是10，所以保存成32
//            位浮点数时，必须保存成10+127=137，即10001001
// e.g.
int main()
{
	float f = 5.5f;
	//101.1
	//1.011*2^2
	//s=0  M=1.011  E=2
	//s=0  M=011    E=2+127
	//0 10000001 01100000000000000000000
	//0100 0000 1011 0000 0000 0000 0000 0000
	//40 b0 00 00
	//查找地址可得00 00 b0 40(小端存储）
	return 0;
 }
//然后，指数E从内存中取出分成三种情况：
//E不为全0或全1：这时，浮点数就采用下面的规则表示，即指数E的计算值减去127（或1023），得到真实值，再将有效数字M前加上第一位的1
//E全为0：这时浮点数的指数E等于1-127（或者1-1023）即为真实值（内存已规定，不必再计算），有效数字M不在加上第一位的1，而是还原为
//        0.xxxxxx的小数，这是内存的特殊规定，是为了表示+-0，以及接近于0的很小的数字
//E全为1：这时表示+-无穷大（正负取决于符号位s）
int main()
{
	int n = 9;
	float* pFloat = (float*)&n;//强制类型转换
	printf("n的值为：%d\n", n);//9
	printf("*pFloat的值为：%f\n", *pFloat);//此时n在内存中存放为00000000000000000000000000001001，以浮点类型打印，则会被以浮点数
	//                                       类型的读取方式进行读取，即0 00000000 00000000000000000001001，得到的是一个极小的数，
	//                                       所以打印出来是0.000000(特别注意：如果要对一个数以另一种类型打印出来，是需要利用一次指针强制类型转换的，不能直接打印，且不可以在printf里面直接转换）
	*pFloat = 9.0;//n变为浮点数类型，二进制为1001.0，即（-1）^0*1.001*2^3,储存为0 10000010 00100000000000000000
	printf("num的值为：%d\n", n);//以整型类型的方式进行读取，得到一个极大的数，为1091567616
	printf("*pFloat的值为：%f\n", *pFloat);//以浮点数类型的方式进行读取，为9.000000
	return 0;
}
int main()
{
	float f = 9.0;
	printf("%d", f);//ERROR!!!
	printf("%d", (unsigned int)f);//打印出来是9
	//特别注意：如果要对一个数以另一种类型打印出来，是需要利用一次指针强制类型转换的，不能直接打印，且不可以在printf里面直接转换
}





//指针的进阶
//指针概念：
//1.指针就是个变量，用来存放地址，地址唯一标识一块内存空间
//2.指针的大小是固定的4（32位平台）或8个（64位平台）字节
//3.指针是有类型的，指针的类型决定指针的+-整数的步长，指针解引用操作时候的权限
//4.指针的运算


//字符指针
int main()
{
	char ch = 'q';
	char* pc = &ch;
	return 0;
}

int main()
{
	char* pc = "Hello world";
	//本质上是把"Hello world"这个字符串的首字符的地址存储在了pc
	printf("%c\n", *pc);//H
	printf("%s\n", *pc);//"Hello world"
	//相似用法
	char arr[] = "Hello world";
	printf("%s\n", arr);//"Hello world"
	return 0;
}

int main()
{
	char* str = "hello world";
	*str = 'w';//ERROR!!!
	//"hello world"是一个常量字符串，是不允许修改的，一些语法严格的编译器甚至需要在char之前加上const 
	return 0;
}
int main()
{
	//字符串指针两种血法
	//1
	char str1 = "hello world";
	char* pc1 = str1;
	//2
	char* pc2 = "hello world";
	//两种写法的区别在于在内存中存储的区域不同，字符数组存储在全局数据区或栈区，第二种形式字符串存储在常量区。全局变量区和栈区
	//的字符串有读取和写入和权限，而常量区字符串只有读取权限，没有写入权限，这就导致了字符数组在定义后可读取和修改每个字符而第
	//二种形式（字符串常量）一旦定义后便不可修改，对它的赋值都是错误的（可整体赋值）
	return 0;
}
int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";
	char* str3 = "hello world";
	char* str4 = "hello world";
	//这里的str3和str4指向的是同一个常量字符串，C/C++会把常量字符串存储到单独的一个内存区域，当几个指针指向同一个字符串的时候，
	//他们实际会指向同一块内存，但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块，即str1和str2是两个不同
	//的数组，开辟的是两个不同的空间，所以str1和str2不同，str3和str4相同
	if (str1 == str2)
		printf("str1 and str2 are same.\n");
	else
		printf("str1 and str2 are not same.\n");//be printed
	if (str3 == str4)
		printf("str3 and str4 are same.\n");//be printed
	else
		printf("str3 and str4 are not same.\n");
	return 0;
}


//指针数组
//本质是数组---数组中存放的是指针（地址）

int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[] = { 2,3,4,5,6 };
	int c[] = { 3,4,5,6,7 };
	int* arr[3] = { a,b,c };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			//print the strings
			printf("%d ", *(arr[i] + j));
			//or
			printf("%d ", arr[i][j]);
		}
	}
	return 0;
}

int main()
{
	int* arr1[10];//整形指针的数组
	char* arr2[4];//一级字符指针的数组
	char** arr3[5];//二级字符指针的数组
	return 0;
}


//数组指针


//概念：能够指向数组的指针
int main()
{
	double* d[5];//指针数组
	double* (*pd)[5] = &d;//pd就是数组指针

	int arr[10];
	int (*parr)[10] = &arr;//parr是一个数组指针，其中存放的是数组的地址，parr先与*结合，说明parr是一个指针变量，然后指向一个
	                       //大小为10个整型的数组。这里注意，[]的优先级是高于*的，所以要加（）来保证parr先与*结合
	return 0;
}

int main()
{
	int arr[10] = { 0 };
	int* p1 = arr;//arr需要一个整型指针
	int (*p2)[10] = &arr;//&arr需要一个数组指针

	//arr与&arr结果相同，但是类型不同
	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%p\n", p1);
	printf("%p\n", p2);//结果都是一致的

	printf("%p\n", p1);
	printf("%p\n", p1 + 1);//p1 和 p1+1 结果相差4个字节
	printf("%p\n", p2);
	printf("%p\n", p2 + 1);//p2 和 p2+1 结果相差40个字节
	//再次说明arr与&arr意义的不同，&arr表示的是数组的地址，而不是数组首元素的地址，整型地址+1向后移动一个整型，数组地址+1向
	//后移动一个数组
	return 0;
}

//数组名是数组首元素地址，但是有两种情况例外
//1.sizeof(数组名）-- 数组名表示的是整个数组，计算的是整个数组的大小，单位是字节
//2.&数组名 -- 数组名表示整个数组，取的是整个数组的地址


//数组指针的使用
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;
	//把数组arr的地址赋值给数组指针变量p
	//但是我们一般很少这样写
	return 0;
}

//使用范例
#include <stdio.h>
void print_arr1(int arr[3][5],int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
void print_arr2(int(*arr)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr + i) + j));//????
		}
	}
}
int mian()
{
	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	print_arr1(arr, 3, 5);
	//数组名arr表示首元素的地址
	//但是二维数组的首元素是二维数组的第一行
	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
	//可以用数组指针来接收
	print_arr2(arr, 3, 5);
	return 0;
}

//int arr[5];整型数组
//int *parr1[10];指针数组
//int (*parr2)[10];数组指针
//int (*parr3[10])[5];parr3是一个存放数组指针的数组，该数组能够存放十个数组指针，每个数组指针能够指向一个数组，数组有5个元素


//数组参数、指针参数
//一维数组传参
#include <stdio.h>
void test (int arr[])//允许，因为传过来的也只是个地址，所以[]中的数字可加可不加
{}
void test(int arr[10])//写了[]中的数字，但是没有实质意义
{}
void test(int* arr)//整型指针，允许
{}
void test2(int* arr[20])//指针数组，允许
{}
void test2(int** arr)//传过来的是int*的地址，就是指针的地址，也就是二级指针，允许
{}
int main()
{
	int arr[10] = { 0 };
	int *arr2[20] = { 0 };
	test(arr);
	test2(arr2);
}
//二维数组传参
void test(int arr[3][5])//ok
{}
void test(int arr[][])//error,行可以省略，列绝对不能省略
{}
void test(int arr[][5])//ok
{}
void test(int* arr)//error,传过来的是第一行数组的地址，不可以用一个int接收
{}
void test(int* arr[5])//error,指针数组无法接收地址
{} 
void test(int (*arr)[5])//ok,指向一维数组的指针
{}
void test(int** arr)//error，传过去的是一维数组的地址，不能用int二级指针接收
{}
int main()
{
	int arr[3][5] = { 0 };
	test(arr);
}