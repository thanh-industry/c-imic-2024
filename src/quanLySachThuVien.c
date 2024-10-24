#include <stdio.h>
#include <string.h>

#define BOOKS 100
#define tenSachToiDa 100
#define tacGiaToiDa 100
#define ISBN 20

// Định nghĩa cấu trúc cho sách
typedef struct {
    char tenSach [tenSachToiDa];
    char tacGia[tacGiaToiDa];
    int nam;
    char isbn[ISBN];
} Sach;

// Khai báo các hàm
void themSach(Sach books[], int *dem);
void xemSach(Sach books[], int dem);
void timKiem(Sach books[], int dem);

// Hàm thêm sách
void themSach(Sach books[], int *dem) {
    if (*dem < BOOKS) {
        printf("Nhap ten sach: ");
        scanf(" %[^\n]", books[*dem].tenSach); // Đọc chuỗi với khoảng trắng
        printf("Nhap ten tac gia: ");
        scanf(" %[^\n]", books[*dem].tacGia);
        printf("Nhap nam xuat ban: ");
        scanf("%d", &books[*dem].nam);
        printf("Nhap ma so ISBN: ");
        scanf(" %[^\n]", books[*dem].isbn);
        (*dem)++;
        printf("Sach da duoc them!\n");
    } else {
        printf("day bo nho.\n");
    }
}

// Hàm xem tất cả sách
void xemSach(Sach books[], int dem) {
    if (dem == 0) {
        printf("Khong co sach nao.\n");
        return;
    }
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < dem; i++) {
        printf("Ten sach: %s, Tac gia: %s, Nam: %d, ISBN: %s\n",
               books[i].tenSach, books[i].tacGia, books[i].nam, books[i].isbn);
    }
}

// Hàm tìm kiếm sách
void timKiem(Sach books[], int dem) {
    char query[tenSachToiDa];
    printf("Nhap ten hoac tac gia de tim kiem: ");
    scanf(" %[^\n]", query);

    int truyXuat = 0;
    for (int i = 0; i < dem; i++) {
        if (strstr(books[i].tenSach, query) != NULL || strstr(books[i].tacGia, query) != NULL) {
            printf("Sach tim thay - Ten: %s, Tac gia: %s, Nam: %d, ISBN: %s\n",
                   books[i].tenSach, books[i].tacGia, books[i].nam, books[i].isbn);
            truyXuat = 1;
        }
    }
    if (!truyXuat) {
        printf("Khong tim thay sach\n");
    }
}


int quanLySachThuVien() {
    Sach books[BOOKS];
    int dem = 0;
    int luaChon;

    do {
        printf("\nMenu:\n");
        printf("1. Them sach moi\n");
        printf("2. xem sach\n");
        printf("3. Tim kiem sach\n");
        printf("4. Thoat ra\n");
        printf("Chon 1 lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themSach(books, &dem);
                break;
            case 2:
                xemSach(books, dem);
                break;
            case 3:
                timKiem(books, dem);
                break;
            case 4:
                printf("thoat\n");
                break;
            default:
                printf("lua chon khong hop le!\n");
        }
    } while (luaChon != 4);

    return 0;
}


