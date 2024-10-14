#include <stdio.h>
#include "BaiTap.h"
// Hàm tính giai thừa của một số nguyên
unsigned long long GiaiThuaCua(int n) {
    if (n == 0 || n == 1) return 1;
    long long GiaTriGiaiThua = 1;
    for (int i = 2; i <= n; i++) {
        GiaTriGiaiThua *= i; // Giá trị giai thừa = 1*2*3*.....*(n-1)*n
    }
    return GiaTriGiaiThua;
}
// Hàm tính tổ hợp chập k của n phần tử: C(n, k) = n! / (k! * (n-k)!)
unsigned long long GiaTriCanTim(int n, int k) {
    return GiaiThuaCua(n) / (GiaiThuaCua(k) * GiaiThuaCua(n - k));
}
int KetQuaBaiTap3_1() {
    printf("BAT DAU BAI TAP 3.1 >>>>>>>>>>>>>>>>>>>>>\r\n"); // BẮT ĐẦU BÀI TẬP 3
    printf("Xac dinh TAM GIAC Pascal => HAY NHAP SO MU n: ");
    int n; // Nhập giá trị n từ bàn phím
    scanf("%d", &n);
    printf("Tam giac Pascal cho (a + b)^%d la:\n", n);
    for (int i = 0; i <= n; i++) { // In ra hệ số C(i, j) mũ n => i = n + 1: i+1 là số lượng hàng
        for (int j = 0; j <= i; j++) { // Mũ n => j = n + 1 Cột j, tương ứng phần tử thứ j+1 trong hàng.
            printf("%lld ", GiaTriCanTim(i, j));     // In tam giác Pascal tới hàng thứ n+1
        }
        printf("\n");
    }
    printf("KET THUC BAI TAP 3.1..................\r\n"); // KẾT THÚC BÀI TẬP 3.1
    printf("\n");
    return 0;
}