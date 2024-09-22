#include "stdio.h"
#include "unistd.h"
#include "example.h"

unsigned int counter = 0;

int main(void)
{
	while (1)
	{
		printf("Giai thua cua %d la %d\r\n", counter, giai_thua(counter));
		counter++;
		sleep(1);
	}
	
	return 1;

}
