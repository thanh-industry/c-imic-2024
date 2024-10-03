#include "example.h"
#include "stdio.h"

int giaDienPerKW = 1000;

unsigned int giai_thua(unsigned int n)
{
    if(n == 0 || n == 1) return 1;
    else if(n > 1){
        return(n * giai_thua(n-1));
    }
    return 0;
}

int vat = 10;
int getGiaDienPerKW(void)
{
    return giaDienPerKW * vat/100 + giaDienPerKW;
}

void setVAT(int percent)
{
    vat = percent;
}


bool revertString(char *str, bool kiTu)
{
    if (kiTu == 0)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		int kiTuDau = 0;
		int kiTuCuoi = i - 1;

		while (kiTuDau < kiTuCuoi)
		{
			char temp = str[kiTuDau];
			str[kiTuDau] = str[kiTuCuoi];
			str[kiTuCuoi] = temp;

			kiTuDau++;
			kiTuCuoi--;
		}

		printf("str ki tu sau khi dao: %s\r\n", str);
	}
	else if (kiTu == 1)
	{
		int i = 0;
		int iTemp = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ' || str[i + 1] == '\0')
			{
				int kiTuDau = iTemp;
				int kiTuCuoi;

				if (str[i + 1] == '\0')
				{
					kiTuCuoi = i;
				}
				else
				{
					kiTuCuoi = i - 1;
				}

				while (kiTuDau < kiTuCuoi)
				{
					char temp = str[kiTuDau];
					str[kiTuDau] = str[kiTuCuoi];
					str[kiTuCuoi] = temp;

					kiTuDau++;
					kiTuCuoi--;
				}
				iTemp = ++i;
			}
			i++;
		}

		printf("str ki tu sau khi dao: %s\r\n", str);
	}
    printf("Testing...");
    return 0;
}