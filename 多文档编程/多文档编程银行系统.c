#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfile.h"
#include "wenjian.h"
int main()
{
    while (1)
    {
        double money = 0;
        if (test())
        {
            money = read_balance();
        }
        else {
            money = 0;
            save_balance(money);
        }
        menu(&money);
    }
    return 0;
}
