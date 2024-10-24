/*
Tạo danh sách học sinh của lớp, gồm 5 học sinh
có các thông tin tên, tuổi, số điện thoại, email
Khởi tạo danh sách với data tự chọn
In danh sách lớp
*/

#include <stdio.h>
#include <string.h>

struct HocSinh {
    char ten[30];
    int tuoi;
    char sodienthoai[15];
    char email[30];
};

// Hàm danh sách học sinh
void DanhSachHocSinh(struct HocSinh danhSach[], int soHocsinh) {
    printf("\n");
    printf("Danh sach hoc sinh:\n");
    printf("%-30s %-10s %-15s %-30s\n", "Ten", "Tuoi", "SDT", "Email");
    for (int i = 0; i < soHocsinh; i++) {
        printf("%-30s %-10d %-15s %-30s\n", danhSach[i].ten, danhSach[i].tuoi, danhSach[i].sodienthoai, danhSach[i].email);
    }
}

void baiTap2() {
    // Khởi tạo danh sách học sinh
    struct HocSinh danhSach[5] = {
        {"Nguyen Tuan Hiep", 24, "0934375890", "hiep@gmail.com"},
        {"Tran Minh Tien", 26, "0874289342", "tien@gmail.com"},
        {"Nguyen Van A", 20, "0112233445", "a@gmail.com"},
        {"Nguyen Van B", 22, "0667788990", "b@gmail.com"},
        {"Nguyen Van C", 21, "0455067468", "c@gmail.com"}
    };

    // In danh sách học sinh
    DanhSachHocSinh(danhSach, 5);

}
