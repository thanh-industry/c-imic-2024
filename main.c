#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "BAI_1.h"
#include "BAI_2.h"
#include "BAI_4.h"
#include "BAI_5.h"
#include "BAI_6.h"

// #define BAI_TAP_1 // Tao va in bien so
// #define BAI_TAP_2 // Tao va in struct hoc sinh
// #define BAI_TAP_4 // Sap xep mang so nguyen
// #define BAI_TAP_5 // Dao chuoi
#define BAI_TAP_6 // Tam giac Pascal

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
	unsigned int n;
	printf("Please input your number: ");
	scanf("%d", &n);

	tamGiacPascal(n);
#endif

	return 1;
}
