#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "BAI_2.h"

typedef struct hocSinh
{
    char ten[13];
    int16_t tuoi;
    char soDienThoai[10];
    char email[50];
} HocSinh;

void printHocSinh(HocSinh *hocSinh)
{
    printf("Ten: %s\r\n", hocSinh->ten);
    printf("Tuoi: %d\r\n", hocSinh->tuoi);
    printf("So dien thoai: %s\r\n", hocSinh->soDienThoai);
    printf("Email: %s\r\n", hocSinh->email);
}

void hocSinh(void)
{
    HocSinh hocSinh[5];

    int i;
    for (i = 0; i < 5; i++)
    {
        char ten[13];
        snprintf(ten, 13, "Nguyen Van ");
        ten[11] = 'A' + i;
        ten[12] = '\0';
        snprintf(hocSinh[i].ten, 13, "%s", ten);
        hocSinh[i].tuoi = 18 + i;
        snprintf(hocSinh[i].soDienThoai, 10, "12%d45678%d", i, i);
        snprintf(hocSinh[i].email, 50, "%c@email.com", 'a' + i);

        printHocSinh(&hocSinh[i]);
    }
}