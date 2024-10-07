#include "BAI_6.h"
#include <stdio.h>

unsigned int giai_thua(unsigned int a)
{
    if (a == 0 || a == 1)
        return 1;
    return a * giai_thua(a - 1);
}

void tamGiacPascal(unsigned int n)
{

    unsigned int i, j, k;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("%d  ", giai_thua(i) / (giai_thua(k) * giai_thua(i - k)));
        }
        printf("\n");
    }
}