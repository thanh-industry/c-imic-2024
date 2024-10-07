#include "BAI_6.h"
#include <stdio.h>

unsigned int giai_thua(unsigned int a)
{
    if (a == 0 || a == 1)
        return 1;
    return a * giai_thua(a - 1);
}

void tamGiacPascal(void)
{
    unsigned int n;
    printf("Please input your number: ");
    scanf("%d", &n);

    unsigned int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("%3d", giai_thua(i) / (giai_thua(k) * giai_thua(i - k)));
        }
        printf("\n");
    }

    printf("Do you want to input again? [Y/N]: ");
    char type;
    scanf(" %c", &type);
    if (type == 'Y' || type == 'y')
        tamGiacPascal();
    else
        return;
}