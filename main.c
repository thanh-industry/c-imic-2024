#include "stdio.h"
#include "unistd.h"
#include "example.h"
#include "practice.h"

unsigned int counter = 0;

int main(void)
{
	daoTu();
	while (1)
	{
		printf("Giai thua cua %d la %d\r\n", counter, giai_thua(counter));
		counter++;
		sleep(1);
	}
	
	return 1;

}
