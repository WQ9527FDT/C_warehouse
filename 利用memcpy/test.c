#include <stdio.h>
#include <string.h>
int main()
{
/*	int i = 1;
	char a[10] = { 0 };
	char* b= memcpy( a, &i, 1);
	printf("%s\n", a[0] ? "小端" : "大端");
*/ // 更简洁方法：
	int i = 1;
	printf("%s\n", *(char*)&i ? "小端" : "大端");
	return 0;


}
