#include <stdio.h>
int cnt = 0;
void hannuo(int n);
void hannuota(int n, char began, char temp, char end);
int main()
{
	int i;
	while(1)
	{ 
		printf("请输入搬运圈个数:");
		scanf("%d", &i);
		hannuo(i);
		printf("搬运圈%d个需要%d次:\n",i,cnt);
	}
	return 0;
}
void hannuo(int n)
{
	hannuota(n, 'A', 'B', 'C');

}
void hannuota(int n, char began, char temp, char end)
{
	if (n > 0)
	{
		hannuota(n-1, began, end, temp);   //将上部分先放在C上,然后放在B
		printf("搬运顺序为：%c -- >%c\n",began, end);
		cnt++;
		hannuota(n-1, temp, began, end);//将上部分从B放在A上,然后放在C

	}
}
