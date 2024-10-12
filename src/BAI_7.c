#include <stdio.h>
#include <stdlib.h>
#include "BAI_7.h"

void demCau(char *str_, int *sCount_, int *cCount_)
{
    int n;
    int sC = 0;
    for (n = 0; n < 1000; n++)
    {
        if (str_[n] == '.' || str_[n] == '?' || str_[n] == '!')
        {
            sC++;
        }
        if (str_[n] == '\0')
        {
            break;
        }
    }
    *sCount_ = sC;
    *cCount_ = n;
}

void timCau(char *str, char *printStr_, int sNo, int cCount)
{
    int n;
    int sC = 0;
    int strStart = 0;
    int strEnd = 0;
    for (n = 0; n < cCount; n++)
    {
        if (str[n] == '.' || str[n] == '?' || str[n] == '!')
        {
            sC++;
            if (sC == sNo)
            {
                strEnd = n;
                break;
            }
            else if (sC < sNo)
            {
                strStart = n + 1;
            }
        }
    }

    int m = strEnd - strStart;

    for (n = strStart; n <= strEnd; n++)
    {
        printStr_[n - strStart] = str[n];
    }

    if (printStr_[0] == ' ')
    {
        for (n = 0; n < m; n++)
        {
            printStr_[n] = printStr_[n + 1];
        }
        printStr_[m] = '\0';
    }

    printf("The sentence No. %d is: %s\r\n", sNo, printStr_);
}

void timCauTrongDoanVan(void)
{
    char *str = (char *)malloc(1000 * sizeof(char));

    printf("PLease input your paragraph:");
    fgets(str, 1000, stdin);

    int sCount;
    int charNo;
    demCau(str, &sCount, &charNo);

    printf("There are %d sentences in your paragraph.\r\n", sCount);

    printf("Please input which sentence No. you want to print:");
    int sentenceNo;

    scanf("%d", &sentenceNo);

    char *printStr = (char *)malloc(1000 * sizeof(char));

    timCau(str, printStr, sentenceNo, charNo);

    free(str);
    free(printStr);

    printf("Do you want to input again? [Y/N]: ");
    char type;
    scanf(" %c", &type);
    if (type == 'Y' || type == 'y')
    {
        while (getchar() != '\n');
        timCauTrongDoanVan();
    }
    else
    {
        return;
    }
}