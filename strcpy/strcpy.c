#include <stdio.h>
#include < string.h >
#include <assert.h>
// ÷¥Ístrcpy
char* mystrcpy(char* p1, const char* p2)
{
	char* dest = p1;
	assert(p1 && p2);
	/*int i = 0;
	while (p2[i] != '\0')
	{
			p1[i]= p2[i];
			i++;
	}
	p1[i] = p2[i];*/
	while (*p1++ = *p2++)
	{
		;
	}
	return dest;
}
int main()
{
	char buff1[] = "qwer";
	char buff2[5] = { 0 };
	/*strcpy(buff2, buff1);*/
	
	mystrcpy(buff2, buff1);
	printf("%s %s\n", buff2, buff1);
	return 0;
}