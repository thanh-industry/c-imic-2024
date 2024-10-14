#include <stdio.h>
#include <string.h>
#include "BaiTap.h"
int KetQuaBaiTap3_2() {
    char MyStr[] = "Abcd. Efghij. Klmn. Opqrs. Tuvwxyz."; // Mảng 1 chiều lưu chuỗi kỹ tự tôi đã cho trước
    char sentences[10][100], // Mảng 2 chiều dùng để lưu các câu, giả sử tối đa 10 câu, tối đa mỗi câu 100 ký tự
         *token; // Biến con trỏ kiểu ký tự dùng để tách và trỏ đến các ký tự trong câu
    int CauThuN = 0, // Biến Câu thứ N kiểu số nguyên dùng lưu Số lượng câu trong chuỗi ký tự đã cho
        InRaCauThuN; // Biến "In ra câu thứ N" kiểu số nguyên được người dùng yêu cầu in ra câu thứ N trong chuỗi ký tự đã cho
// Sử dụng hàm strtok để tách câu dựa trên dấu chấm
    printf("BAT DAU BAI TAP 3.2 >>>>>>>>>>>>>>>>>>>\r\n"); // BẮT ĐẦU BÀI TẬP 3.2
    printf("Chuoi da cho la: %s \r\n", MyStr);
    token = strtok(MyStr, "."); // Tách các câu trong chuỗi đã cho bằng ký tự dấu chấm "."
    while (token != NULL) { /* Điều kiện vòng while: Phủ định (không còn token nào nữa)
                              Nghĩa là vẫn còn câu (sentences) chứ chưa kết thúc Chuỗi thì thực hiện vòng While */
        strcpy(sentences[CauThuN], token); // Lưu câu thứ N đã tách vào mảng
        CauThuN++; // Tách câu thứ N xong, tiếp tục tăng lên tới Câu thứ N+1
        token = strtok(NULL, "."); // Tiếp tục tách các câu còn lại cho đến hết
    }
// Bỏ đi ký tự khoảng trống từ câu thứ 2 đến hết câu cuối cùng trong chuỗi ký tự đã cho 
    if (CauThuN >= 2) { // Nếu có từ 2 câu trở lên thì câu thứ 2 trở đi xóa khoảng trống
        int i; // Câu thứ i
        for (i = 1; i < CauThuN; i++) {
            int length = strlen(sentences[i]); // Số lượng ký tự có trong câu thứ i
            int j; // Ký tự thứ j
            for (j = 0; j < length; j++) { // Hàng thứ i-1 ứng với câu thứ i
                sentences[i][j] = sentences[i][j+1]; // Dịch 1 ký tự phía sau lên phía trước, bỏ đi khoảng trắng
            }
            sentences[i][j+1] = '\0'; // Xóa đi ký tự cuối cùng trong câu thứ i
        }
    }
// Hiển thị số lượng câu và các câu lần lượt là:
    printf("So luong cau trong chuoi: %d\n", CauThuN);
    for (int i = 0; i < CauThuN; i++) { // In ra lần lượt các câu trong chuỗi ký tự đã cho
        printf(" * Cau %d: %s.\r\n", i+1, sentences[i]);
    }
// Yêu cầu người dùng nhập từ bàn phím câu thứ n muốn in ra
    printf("Nhap cau thu n muon in ra (Tu cau 1 Den cau %d): ", CauThuN);
// Nhập câu thứ n muốn in ra
    scanf("%d", &InRaCauThuN);
    // Kiểm tra và in ra câu thứ N
    while (InRaCauThuN <= 0 || CauThuN < InRaCauThuN ) {
        printf("Ban da nhap so thu tu cau KHONG HOP LE!\r\n");
        printf("Xin vui long thu lai......... \r\n");
        printf("Nhap cau thu n muon in (Tu cau 1 Den cau %d): ", CauThuN);
        scanf("%d", &InRaCauThuN);
    }
    printf("Cau thu %d can in ra la: %s.\r\n", InRaCauThuN, sentences[InRaCauThuN - 1]);
    printf("KET THUC BAI TAP 3.2..................\r\n"); // KẾT THÚC BÀI TẬP 3.2
    printf("\n");
    return 0;
}
/* HÀM STRTOK:
Giới thiệu: 
    Hàm strtok trong C được sử dụng để phân tách (tokenize) một chuỗi thành các "token" 
    (các phần nhỏ hơn) dựa trên các ký tự phân tách (delimiter) được chỉ định.
    Hàm này rất hữu ích khi bạn muốn chia một chuỗi thành các phần, ví dụ như từ trong một câu.
Cú pháp: 
    char *strtok(char *str, const char *delim);
Tham số:
    str: Chuỗi cần phân tách. Đối với lần gọi đầu tiên, bạn cung cấp chuỗi này. 
         Đối với các lần gọi tiếp theo, bạn cung cấp NULL để tiếp tục phân tách từ vị trí trước đó.
    delim: Chuỗi chứa các ký tự được sử dụng làm dấu phân cách.
Giá trị trả về:
    Trả về con trỏ đến token tiếp theo trong chuỗi. Nếu không còn token nào nữa, nó sẽ trả về NULL.
*/