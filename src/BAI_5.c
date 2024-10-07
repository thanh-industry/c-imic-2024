#include "BAI_5.h"

void daoChuoi(char *chuoi, int kiTu)
{
    printf("Chuoi ki tu truoc khi dao: %s\r\n", chuoi);
    if (kiTu == 0)
    {
        int i = 0;
        while (chuoi[i] != '\0')
        {
            i++;
        }
        int kiTuDau = 0;
        int kiTuCuoi = i - 1;

        while (kiTuDau < kiTuCuoi)
        {
            char temp = chuoi[kiTuDau];
            chuoi[kiTuDau] = chuoi[kiTuCuoi];
            chuoi[kiTuCuoi] = temp;

            kiTuDau++;
            kiTuCuoi--;
        }

        printf("Chuoi ki tu sau khi dao: %s\r\n", chuoi);
    }
    else if (kiTu == 1)
    {
        int i = 0;
        int iTemp = 0;
        while (chuoi[i] != '\0')
        {
            if (chuoi[i] == ' ' || chuoi[i + 1] == '\0')
            {
                int kiTuDau = iTemp;
                int kiTuCuoi;

                if (chuoi[i + 1] == '\0')
                {
                    kiTuCuoi = i;
                }
                else
                {
                    kiTuCuoi = i - 1;
                }

                while (kiTuDau < kiTuCuoi)
                {
                    char temp = chuoi[kiTuDau];
                    chuoi[kiTuDau] = chuoi[kiTuCuoi];
                    chuoi[kiTuCuoi] = temp;

                    kiTuDau++;
                    kiTuCuoi--;
                }
                iTemp = ++i;
            }
            i++;
        }

        printf("Chuoi ki tu sau khi dao: %s\r\n", chuoi);
    }
}