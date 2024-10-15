#include <stdio.h>
#include <string.h>
#include "BaiTap.h"
// The functions calculating the goods value in the invoices of Shop 1 and Shop 2
unsigned int Shop_1(unsigned int Value_of_goods, unsigned int VAT) {
    return Value_of_goods*(1 + (VAT-15)*0.01); // calculating the goods value in the invoices of Shop 1
}                     // Sale up to 15%
unsigned int Shop_2(unsigned int Value_of_goods, unsigned int VAT) {
    return Value_of_goods*(1 + (VAT-20)*0.01); // calculating the goods value in the invoices of Shop 2
}                     // Sale up to 20%
// Function that uses function pointers as parameters
void My_Bill(unsigned int (*Pointer)(unsigned int, unsigned int), unsigned int x, unsigned int y) {
    printf("My bill is: %u (VND) \r\n", Pointer(x, y));
}
int KetQuaBaiTap4() {
    printf("BAT DAU BAI TAP 4 >>>>>>>>>>>>>>>>>>>\r\n"); // BẮT ĐẦU BÀI TẬP 3.2
    unsigned int x, y;
    printf("Please enter the goods value (VND): "); scanf("%u", &x);
    printf("Please enter value VAT (*/100)    : "); scanf("%u", &y);
    printf("At Shop 1 (Sale up to 15/100), "); // My bill is calculated at Shop 1
    My_Bill(Shop_1, x, y); 
    printf("At Shop 2 (Sale up to 20/100), "); // My bill is calculated at Shop 2
    My_Bill(Shop_2, x, y);
    printf("KET THUC BAI TAP 3.2..................\r\n"); // KẾT THÚC BÀI TẬP 3.2
    printf("\n");
    return 0;
}
/* Con trỏ hàm
Cú pháp khai báo con trỏ hàm như sau: return_type (*pointer_name)(parameter_types);
    return_type: Kiểu trả về của hàm.
    pointer_name: Tên của con trỏ hàm.
    parameter_types: Kiểu dữ liệu của các tham số mà hàm nhận vào.
*/