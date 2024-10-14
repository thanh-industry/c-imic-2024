/* Bài 2: 
- Tạo danh sách có 5 học sinh; ==> Dùng cấu trúc Mảng
- Có các thông tin: ==> Dùng kiểu Struct
+ Tên;
+ Tuổi;
+ Số điện thoại;
+ Email.
- Khởi tạo danh sách với Data tự chọn;
- In danh sách lớp ra để kiểm tra
*/
//  Khai báo thư viện stdio và string:
#include <stdio.h>
#include <string.h>
#include "BaiTap.h"
// Định nghĩa số lượng học sinh NumberOfStudents là 5
int KetQuaBaiTap1_2() {
	printf("BAT DAU BAI TAP 1.2 >>>>>>>>>>>>>>>>>>>>>>>>>\r\n"); // BẮT ĐẦU BÀI TẬP 1.2
	#define NumberOfStudents 5
	// Định nghĩa và khai báo kiểu cấu trúc (Dùng Struct) StudentInformation chứa các thông tin cá nhân của Học sinh
	struct StudentInformation { 
		char FullName[30]; // Tên đầy đủ, gán biến kiểu Char FullName là chuỗi có 29 ký tự
		int  Age; // Độ tuổi, gán biến kiểu char Age là kiểu số nguyên Integer
		char NumberPhone[15]; // Số điện thoại, gán biến kiểu Char NumberPhone là chuỗi có 14 ký tự
		char Email[20]; // Địa chỉ Email, gán biến kiểu Char Email là chuỗi có 19 ký tự
	};
	// Khởi tạo các thuộc tính của cấu trúc Struct_StudentInformation nằm trong mảng Array_Students[NumberOfStudents] chứa danh sách 5 học sinh
	struct StudentInformation Students[NumberOfStudents] = {
		{"Nguyen Van A", 14, "0123456789", "vana@example.com"},
		{"Tran Thi B  ", 15, "0987654321", "thib@example.com"},
		{"Le Van C   " , 16, "0111111111", "vanc@example.com"},
		{"Pham Thi D  ", 17, "0222222222", "thid@example.com"},
		{"Hoang Van E" , 18, "0333333333", "vane@example.com"}
	};
	// In danh sách lớp 5 học sinh với thông tin đã khởi tạo
	printf("DANH SACH TONG HOP THONG TIN CUA %d %s\n", NumberOfStudents, "HOC SINH:");
	printf("%-20s %-10s %-15s %-20s\n", "Ho & Ten", "Tuoi", "So dien thoai", "Dia chi Email");
	printf("--------------------------------------------------------------------\n");
	for (int i = 0; i < NumberOfStudents; i++) {
		printf("%-20s %-10d %-15s %-20s\n", 
				Students[i].FullName, 
				Students[i].Age, 
				Students[i].NumberPhone, 
				Students[i].Email);
	}
	printf("KET THUC BAI TAP 1.2.................\r\n"); // KẾT THÚC BÀI TẬP 1.2
    printf("\n");
    return 0;
}
