#include <stdio.h>
#include <string.h>
int a = 0, // Biến điều kiện kiểu Integer ứng với 2 trường hợp (khi a = 0 và a = 1)
    n, // Biến số nguyên lưu độ dài của chuỗi ký tự (khi a = 0), độ dài của từ word (khi a = 1)
    i; // Biến số nguyên để chạy vòng lặp for (dùng chung khi a = 0, a = 1)
char BienTrungGian, // Biến trung gian để lưu tạm thời khi hoán đổi (dùng khi a = 0)
     ChuoiTrungGian[600], // Chuỗi trung gian để lưu tạm thời khi hoán đổi (dùng khi a = 1)
     ChuoiKyTu[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. \
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, \
when an unknown printer took a galley of type and scrambled it to make a type specimen book. \
It has survived not only five centuries, but also the leap into electronic typesetting, \
remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets \
containing Lorem Ipsum passages, and more recently with desktop publishing software \
like Aldus PageMaker including versions of Lorem Ipsum.";
void DaoToanBoChuoi(char *ChuoiKyTu) { // Khai báo chương trình đảo toàn bộ ký tự (a = 0)
    // Vòng lặp for: (n+1)/2 lần nếu n lẻ và n/2 lần nếu n chẵn
    n = strlen(ChuoiKyTu); // Xác định độ dài của chuỗi ký tự, để tìm vị trí ký tự ở giữa (n/2)
    for (i = 0; i < n/2; i++) { // Lấy đối xứng qua vị trí ký tự thứ i = (n-1)/2 nếu n lẻ
         BienTrungGian = ChuoiKyTu[i]; // Hoán đổi ký tự dựa vào việc lưu vào biến trung gian
          ChuoiKyTu[i] = ChuoiKyTu[(n-1)-i];
    ChuoiKyTu[(n-1)-i] = BienTrungGian;
    }
}
void DaoTungKyTuTrongChuoi(char *ChuoiKyTu) { // Cần dùng hàm strtok
    int j = 0; // Biến chỉ vị trí ký tự trong chuỗi trung gian ChuoiTrungGian[], bắt đầu từ ký tự đầu tiên
    char *word = strtok(ChuoiKyTu, " "); // Tách từng từ (word) trong chuỗi bởi dấu ngăn cách là khoảng trắng " "
    while (word != NULL) { /* Điều kiện vòng while: Phủ định (không còn token nào nữa)
                              Nghĩa là vẫn còn từ (word) chứ chưa kết thúc Chuỗi thì thực hiện vòng While */
        n = strlen(word); // Xác định độ dài của từ (word)
        for (i = n - 1; i >= 0; i--) { // i chạy từ ký tự cuối cùng (i = n-1) đến ký tự đầu tiên (i = 0) của từ (word)
            ChuoiTrungGian[j++] = word[i]; // Biến j tăng, biến i giảm về 0 ==> Đảo vị trí thứ tự trong từ (word)
        } /* Gán ký tự cuối cùng (i = n -1) của từ (word) trong ChuoiKyTu[] đang cần chuyển với
       ký tự đầu tiên (j = 0) của từ (word) trong ChuoiTrungGian[] ==> Đã đảo đến khi ký tự cuối cùng của từ*/
        ChuoiTrungGian[j++] = ' '; // Sau khi đến ký tự cuối của 1 từ (word) ==> Thêm dấu " " để đủ so với chuỗi gốc
        word = strtok(NULL, " "); // NULL để tiếp tục phân tách từ vị trí trước đó đã tách và dừng lại
    } // Cứ như thế tách và đảo ký tự trong từ (word) đến ký tự cuối cùng ==> Trả về NULL ==> Thoát while
    ChuoiTrungGian[j - 1] = '\0'; // Vì đã thêm " " vào lần tách, đảo cuối cùng vào chuỗi trung gian nên 
                                  // cần XÓA đi 1 dấu cách cuối cùng để đúng với chuỗi gốc đã cho
    strcpy(ChuoiKyTu, ChuoiTrungGian); // Sao chép lại ChuoiTrungGian đã đảo xong vào ChuoiKyTu để in rá
}
int main() { // Chương trình chính
    printf("Nhập giá trị của a (TH1: a = 0; TH2: a = 1): \r\n");
    scanf("%d", &a); // Nhập từ bàn phím giá trị của a
    switch (a) {
        case 0: // Nếu a = 0: Hoán đổi vị trí toàn bộ chuỗi, ngược từ cuối lên đầu 
            DaoToanBoChuoi(ChuoiKyTu); // Thực hiện chương trình hoán đổi (TH1: a = 0)
        break; // Thoát khỏi switch
        case 1: // Nếu a = 1: Hoán đổi vị trí từng chữ trong chuỗi, lần lượt từ đầu đến cuối 
            DaoTungKyTuTrongChuoi(ChuoiKyTu); // Thực hiện chương trình hoán đổi (TH1: a = 0)
        break; // Thoát khỏi switch
    }
    printf("Chuỗi cần đảo cần tìm là: \r\n");
    printf("%s\n", ChuoiKyTu); // In ra chuỗi đã được sắp xếp
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