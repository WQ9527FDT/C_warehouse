#include <stdio.h>
int main()
{
	int  buff1[] = { 1,2,3,4,5,6,7,8,9 };
	int  buff2[20] = { 0 };
	memcpy(buff2, buff1, 20);  //利用字节大小  int 整型 一个 4 字节
	rsize_t r = sizeof(buff2) / sizeof(buff2[0]);
	for (int i = 0; i < r; i++)
	{
		printf("%d\n", buff2[i]);
	}


}
