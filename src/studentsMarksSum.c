#include <stdio.h>
#include <stdlib.h>

int tongDiemHocSinh (int* diem, int soLuongHocSinh, char gioiTinh) {
    int tong = 0;
    if (gioiTinh == 'b') {
        // Cộng điểm của nam (các chỉ số chẵn)
        for (int i = 0; i < soLuongHocSinh; i += 2) {
            tong += *(diem + i);
        }

    } else if (gioiTinh== 'g') {
        // Cộng điểm của nữ (các chỉ số lẻ)
        for (int i = 1; i < soLuongHocSinh; i += 2) {
            tong += *(diem + i);
        }
    }
    return tong;  // Trả về tổng điểm
}

int studentsMarksSum() {
    int soLuongHocSinh;
    char gioiTinh;
    int tongDiem;

    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &soLuongHocSinh);

    int *diem = (int *) malloc(soLuongHocSinh * sizeof(int));

    printf("\nNhap diem cua hoc sinh: \n");
    for (int hocSinh = 0; hocSinh < soLuongHocSinh; hocSinh++) {
        scanf("%d", (diem + hocSinh)); //tro toi dia chi cua phan tu tai chi so "hocSinh" trong mang diem
    }
    printf("\nNhap gioi tinh hoc sinh (b hoac g)\n");
    scanf(" %c", &gioiTinh);
    tongDiem = tongDiemHocSinh(diem, soLuongHocSinh, gioiTinh);
    printf("\nTong diem la: ");
    printf("%d\n", tongDiem);

    free(diem);  // Giải phóng bộ nhớ đã cấp phát
    return 0;
}
