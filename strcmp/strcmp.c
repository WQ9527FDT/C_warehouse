#include <stdio.h>
#include <string.h>
#include <assert.h>
#include < stdlib.h >
// Ä£Äâstrcmp
int mystrcmp(const char* p1, const char* p2)
{
	assert(p1 && p2);
	while (*p1 && *p2&& *p1== *p2)
	{
		p1++;
		p2++;
	}
	return *p1 - *p2;

}
int main()
{
	char buff1[] = "b";
	char buff2[] = "a";
	int r = mystrcmp(buff1, buff2);
	printf("%d\n", r);

}
