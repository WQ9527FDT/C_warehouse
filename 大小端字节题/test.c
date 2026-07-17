#include <stdio.h>
#include <string.h>
int main()
{
#if 0 char a[1000];
	// 利用char 存储方式 求strlen(a)打印结果
	for (int i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));   // 存储循环 -128--127，126...1,0;所以为255；
#else
	//根据上面解决下面问题：
	/*unsigned char i = 1;
	for (i = 1; i <= 255; i++)
	{
		printf("%u  hello world!\n",i);
	}*/

	/*unsigned int i;
	for (i = 9; i >=0; i--)
	{
		printf("%u\n", i);
	}*/


	//X86条件解决代码：
	int a[4] = { 1,2,3,4 };
	int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	printf("%x %x", p1[-1], *p2);

#endif
return 0;

}
