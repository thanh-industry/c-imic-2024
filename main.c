#include "stdio.h"
#include "stdio.h"
#include "unistd.h"
#include "example.h"
#include "practice.h"
#include "string.h"
unsigned int counter = 0;

//#define BAI_TAP_1 
#define BAI_TAP_2 

int main(void)
{
	daoTu();
	setVAT(8);
	char *str = "this is the string to be reverted.";
#ifdef BAI_TAP_1
	int a = 3;

#elif BAI_TAP_2

	int b;


	int c;


#endif





	char arr[64];

	memcpy(arr, str, strlen(str) + 1);
	while (1)
	{
		revertString(str, 0);
		counter++;
		sleep(1);
	}
	
	return 1;

}
