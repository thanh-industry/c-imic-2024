#include <stdio.h>

void list(char *typeArr, char *arr)
{
    int i;
    for (i = 0; i < 13; i++)
    {
        if (i == 0)
        {
            printf("%s array: { %d,", typeArr, arr[i]);
        }
        else if (i == 12)
        {
            printf(" %d }\r\n", arr[i]);
        }
        else
        {
            printf(" %d,", arr[i]);
        }
    }
}

void sortArray(char *arr)
{
    int i;
    int j;
    int temp;

    list("Unsorted", arr);

    for (i = 0; i < 13; i++)
    {
        for (j = i + 1; j < 13; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    list("Sorted", arr);
}