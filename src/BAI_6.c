#include "BAI_6.h"
#include <stdio.h>

unsigned int giai_thua(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * giai_thua(n - 1);
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
        /* for (k = 0; k < (2 * i) + 1; k++)
        {
            if (k % 2 == 0)
                printf("*");
            else
                printf(" ");
        } */
        for (k = 0; k <= i; k++)
        {
            printf(" %d ", giai_thua(i) / (giai_thua(k) * giai_thua(i - k)));
        }
        printf("\n");
    }
}