#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include "BAI_1.h"
#include "BAI_2.h"
#include "BAI_4.h"
#include "BAI_5.h"
#include "BAI_6.h"
#include "BAI_7.h"
#include "BAI_8.h"

// #define BAI_TAP_1 // Tao va in bien so
// #define BAI_TAP_2 // Tao va in struct hoc sinh
// #define BAI_TAP_4 // Sap xep mang so nguyen
// #define BAI_TAP_5 // Dao chuoi
// #define BAI_TAP_6 // Tam giac Pascal
#define BAI_TAP_7 // Tim cau trong doan van, su dung malloc() de input doan van
// #define BAI_TAP_8 // Khai bao va su dung con tro ham

int main(void)
{
#ifdef BAI_TAP_1
	inBienSo();
#endif

#ifdef BAI_TAP_2
	hocSinh();
#endif

#ifdef BAI_TAP_4
	int arr[13] = {21, 321, 91, 31, 5634, 213, 12, 1, 2134, 2314, -912, -18, 312};
	sortArray(arr);
#endif

#ifdef BAI_TAP_5

	char str[1000];
	printf("Please input your string:");
	fgets(str, sizeof(str), stdin);

	int type;
	printf("Please input your type of reverse (0 - reverse whole string, 1 - reverse each word): ");
	scanf("%d", &type);

	daoChuoi(str, type);
#endif

#ifdef BAI_TAP_6

	while (1)
	{
		tamGiacPascal();
		printf("Do you want to input again? [Y/N]: ");
		char type;
		scanf(" %c", &type);
		if (type == 'Y' || type == 'y')
			continue;
		else
			break;
	}

#endif

#ifdef BAI_TAP_7
	while (1)
	{
		char *str = timCauTrongDoanVan();
		printf("The sentence is: %s\n", str);
		free(str);
		printf("Do you want to input again? [Y/N]: ");
		char type;
		scanf(" %c", &type);
		if (type == 'Y' || type == 'y')
			continue;
		else
			break;
	}
#endif

#ifdef BAI_TAP_8

	int a, b;
	int (*tong)(int, int);

	printf("Please input a: ");
	scanf("%d", &a);

	printf("Please input b: ");
	scanf("%d", &b);

	tong = tong1;
	printf("Tong 1: %d\r\n", tong(a, b));

	tong = tong2;
	printf("Tong 2: %d\r\n", tong(a, b));

	tong = tong3;
	printf("Tong 3: %d\r\n", tong(a, b));

#endif

	return 1;
}
