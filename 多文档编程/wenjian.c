#include "wenjian.h"
#include "RES.h"
#include <stdio.h>
#include <stdlib.h>
// 读取余额
double read_balance(void)
{
    FILE* fp = fopen(TEXTNAME, "rb"); // 二进制读模式
    if (fp == NULL)
    {
        // 文件不存在（首次运行），返回初始余额0
        return 0.0;
    }
    double balance = 0.0;
    // 读取失败/文件损坏则返回默认0
    if (fread(&balance, sizeof(double), 1, fp) != 1)
    {
        fclose(fp);
        return 0.0;
    }
    fclose(fp);
    return balance;
}
// 保存余额
int save_balance(double money)
{
    FILE* fp = fopen(TEXTNAME, "wb"); // 二进制写模式，覆盖更新
    if (fp == NULL)
    {
        return 0; // 文件打开失败（权限不足/磁盘满）
    }
    if (fwrite(&money, sizeof(double), 1, fp) != 1)
    {
        fclose(fp);
        return 0; // 写入失败
    }
    fclose(fp);
    return 1;
}
bool test()
{
    // 打开文件
    FILE* fp = fopen(TEXTNAME, "r");
    if (NULL == fp)
    {
        printf("打开文件失败\n");
        FILE* fp = fopen(TEXTNAME, "w");
        fclose(fp);
        return false;
    }
    fclose(fp);
    return true;

}
