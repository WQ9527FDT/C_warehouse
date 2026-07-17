#include <stdio.h>
int dituix(int n)
{
    if (n > 1) return n * dituix(n - 1);
    else return 1;

}
int main()
{
#if 0
    // 使用循环 
    int n, sum;
    printf("请输入阶乘数字：%d\n", n);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
#else   //	使用递推
    int n;
    while(1)
    {
        printf("请输入阶乘数字：");
        scanf("%d", &n);
        dituix(n);
        printf("输入阶乘数字为：%d 阶乘为%d\n", n, dituix(n));
    }
    
}
#endif

