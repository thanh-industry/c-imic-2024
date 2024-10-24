#include <stdio.h>
#include <string.h>
int a = 0, //Biến điều kiện
    n, // Biến số nguyên lưu độ dài của chuỗi ký tự (khi a = 0), độ dài của từ word (khi a = 1)
    i; // Biến số nguyên để chạy vòng lặp for (dùng chung khi a = 0, a = 1)
char b, // Biến trung gian để lưu tạm thời khi hoán đổi (dùng khi a = 0)
     ChuoiTrungGian[600], // Chuỗi trung gian để lưu tạm thời khi hoán đổi (dùng khi a = 1)
     Chuoi[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, \
when an unknown printer took a galley of type and scrambled it to make a type specimen book. \
It has survived not only five centuries, but also the leap into electronic typesetting, \
remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets \
containing Lorem Ipsum passages, and more recently with desktop publishing software \
like Aldus PageMaker including versions of Lorem Ipsum.";
void DaoToanBoChuoi(char *Chuoi) { 
    // Vòng lặp for: (n+1)/2 lần nếu n lẻ và n/2 lần nếu n chẵn
    n = strlen(Chuoi); // Xác định độ dài của chuỗi ký tự, để tìm vị trí ký tự ở giữa (n/2)
    for (i = 0; i < n/2; i++) { // Lấy đối xứng qua vị trí ký tự thứ i = (n-1)/2 nếu n lẻ
         b = Chuoi[i]; // Hoán đổi ký tự dựa vào việc lưu vào biến trung gian
          Chuoi[i] = Chuoi[(n-1)-i];
    Chuoi[(n-1)-i] = b;
    }
}

int baiTap11() { 
    printf("nhap a (TH1: a = 0; TH2: a = 1): \r\n");
    scanf("%d", &a); //nhap a
    switch (a) {
        case 0: // Nếu a = 0: Hoán đổi vị trí toàn bộ chuỗi, ngược từ cuối lên đầu 
            DaoToanBoChuoi(Chuoi);
        break;
    }
    printf("chuoi da dao: \r\n"); //in ra chuoi
    printf("%s\n", Chuoi);
    return 0;
}
