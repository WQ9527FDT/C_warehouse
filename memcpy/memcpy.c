#include <stdio.h>
int main()
{
#if 0 
	// 正常使用
	int  buff1[] = { 1,2,3,4,5,6,7,8,9 };
	int  buff2[20] = { 0 };
	memcpy(buff2, buff1, 20);  //利用字节大小  int 整型 一个 4 字节
	rsize_t r = sizeof(buff2) / sizeof(buff2[0]);
	for (int i = 0; i < r; i++)
	{
		printf(" %d", buff2[i]);
	}
#else // 出现内存重叠
	// 让其前5个数复制到第三个数开始的内存块 观察实验结果
	int  buff1[] = { 1,2,3,4,5,6,7,8,9 };
	memcpy(buff1+2, buff1, 20);
	rsize_t r = sizeof(buff1) / sizeof(buff1[0]);
	for (int i = 0; i < r; i++)
	{
		printf("%d ", buff1[i]);
	}
#endif
}
