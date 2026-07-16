#include "myfile.h"
#include "wenjian.h"
void menu(double* money)
{
    int n;
    printf("********** 欢迎光临CHina银行 **********\n");
    printf("********** 根据您的需求输入数字： **********\n");
    printf("********** 1：存钱 **********\n");
    printf("********** 2：取钱 **********\n");
    printf("********** 3：显示余额 **********\n");
    printf("********** 4：退出 **********\n");
    printf("请输入您的选择：");

    // 增加输入合法性校验，避免输入非数字导致程序崩溃
    if (scanf("%d", &n) != 1)
    {
        // 清空输入缓冲区，避免死循环
        while (getchar() != '\n');
        printf("输入无效，请输入1-4的数字！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    switch (n)
    {
    case 1: cun(money); break;
    case 2: qu(money); break;
    case 3: show(money); break;
    case 4: exit_program(); break;
    default:
        printf("输入无效，请输入1-4的数字！\n");
        Sleep(1000);
        system("cls");
        break;
    }
}

void show(double* money)
{
    // 用%.2f代替%g，金额显示更规范，避免科学计数法
    printf("现在您的余额为:%.2f\n", *money);
    Sleep(1000);
    system("cls");
}

void cun(double* money)
{
    double m = 0;
    printf("请输入存款金额：");
    if (scanf("%lf", &m) != 1)
    {
        while (getchar() != '\n');
        printf("输入无效，请输入正确的金额！\n");
        Sleep(1000);
        system("cls");
        return;
    }
    if (m <= 0)
    {
        printf("存款金额必须大于0！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    *money += m;
    save_balance(*money);
    printf("存款成功！当前余额为：%.2f\n", *money);
    Sleep(1000);
    system("cls");

}

void qu(double* money)
{
    double a = 0;
    printf("请输入取款金额：");
    if (scanf("%lf", &a) != 1)
    {
        while (getchar() != '\n');
        printf("输入无效，请输入正确的金额！\n");
        Sleep(1000);
        system("cls");
        return;
    }
    if (a <= 0)
    {
        printf("取款金额必须大于0！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    // 修复原逻辑：余额等于取款金额时也可以正常取款
    if (a <= *money)
    {
        *money -= a;
        save_balance(*money);
        printf("取款成功！当前余额为：%.2f\n", *money);
    }
    else
    {
        save_balance(*money);
        printf("您的余额不足，当前余额为：%.2f，取款失败！\n", *money);
    }
    Sleep(1000);
    system("cls");
}

void exit_program()
{
    for (int i = 5; i > 0; i--)
    {
        printf("还有%d秒退出!\n", i);
        Sleep(1000);
    }
    exit(0);
}
