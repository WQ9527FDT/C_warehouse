#include <stdio.h>
#include <string.h>
#include <assert.h>
void* mymemcpy(void* p1, const void* p2, size_t num)
{
	assert(p1, p2);
	void* dest = p1;  // 将p1指向的的地址存放在dest；
	// 因为字节和char 内存使用相似 ,利用char 
	while (num--)
	{
		*(char*)p1 = *(char*)p2;
		p1 = (char*)p1+1;
		p2=(char*)p2+1;
	}
	return dest;
}
int main()
{
	int  buff1[] = { 1,2,3,4,5,6,7,8,9 };
	int  buff2[20] = { 0 };
	// 利用自己写的实现内存不重叠拷贝，一旦重叠出现错误
	mymemcpy(buff2, buff1, 20);  //利用字节大小  int 整型 一个 4 字节
	rsize_t r = sizeof(buff2) / sizeof(buff2[0]);
	for (int i = 0; i < r; i++)
	{
		printf(" %d", buff2[i]);
	}
	

}
