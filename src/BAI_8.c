#include <stdio.h>
#include "BAI_8.h"

int tong1(int a, int b)
{
    return a + b;
}

int tong2(int a, int b)
{
    a += 1;
    b += 1;
    return a + b;
}

int tong3(int a, int b)
{
    a += b;
    b += a;
    return a + b;
}