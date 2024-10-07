#include <stdio.h>
#include "BAI_1.h"

int bienSo1 = -10;
unsigned int bienSo2 = 10;
char bienSo3 = 'A';
float bienSo4 = 3.14;
double bienSo5 = 3.14159265359;

void inBienSo(void)
{
    printf("Cac bien co gia tri lan luot la: %d, %d, %c, %f, %lf\r\n", bienSo1, bienSo2, bienSo3, bienSo4, bienSo5);
}