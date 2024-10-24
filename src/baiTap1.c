/*
Khai báo 5 biến bất kỳ, đặt tên biến có ý nghĩa
theo cách nhuTheNay và in ra kết quả để kiểm tra
*/ 
#include <stdio.h>
/**
 * @brief 
 * 
 * @return int 
 */
int baiTap1() {
    // Khai báo 5 biến có ý nghĩa
    char tenCuaBan[]= "NguyenTuanHiep";    // tên của bạn
    char soDienThoai[13];                  // Số điện thoại
    char diaChiEmail[] = "hiep@gmail.com"; // Email
    int tuoi = 24;                         //Số tuổi
    float chieuCao = 174.5;                // Chiều cao

    // nhập vào số điện thoại
    printf("\n");
    printf("nhap vao so dien thoai cua ban: \n");
    scanf("%10s", soDienThoai);

    // In ra kết quả
    printf("\n");
    printf("ten cua ban: %s\n", tenCuaBan);
    printf("so dien thoai: %.10s\n", soDienThoai);
    printf("dia chi email: %s\n", diaChiEmail);
    printf("tuoi: %d\n", tuoi);
    printf("chieu cao la: %.2fcm\n", chieuCao);
    printf("\n");

    return 0;
}



