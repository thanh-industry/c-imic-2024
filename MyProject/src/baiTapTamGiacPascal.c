#include <stdio.h>

void tamGiacPascal(int n) {
    for (int dongHienTai = 0; dongHienTai < n; dongHienTai++) 
    {
        int C = 1; // Giá trị ban đầu của C (hệ số nhị thức)

        // In khoảng trắng
        for (int space = 0; space < n - dongHienTai - 1; space++)
            printf(" ");

        // In các hệ số
        for (int i = 0; i <= dongHienTai; i++) 
        {
            printf("%d ", C);
            C = C * (dongHienTai - i) / (i + 1); // Tính hệ số nhị thức
        }
        printf("\n");
    }
}

void baiTapTamGiacPascal(){
    int n;
    printf("nhap so hang tam giac pascal: ");
    scanf("%d", &n);
    tamGiacPascal(n);
}
