/* Bài 1: 
- Khai báo 5 biến bất kì; ==> Đặt tên 5 biến trong các loại biến đã học
- Đặt tên biến có ý nghĩa; ==> Đặt tên theo từ gợi nhớ Tiếng Anh, có chú thích
- Gán giá trị cho biến; ==> Gán trực tiếp khi khai báo hoặc gán sau
- In ra kết quả để kiểm tra. ==> Dùng hàm printf
*/
// Khai báo thư viện BaiTap1_1.h:
#include <stdio.h>
#include <string.h>
#include "BaiTap.h"
int KetQuaBaiTap1_1() {
	printf("BAT DAU BAI TAP 1.1 >>>>>>>>>>>>>>>>>>>>>>>>> \r\n"); // BẮT ĐẦU BÀI TẬP 1.1
// Khai báo 5 biến mang thông tin cá nhân, có kiểu dữ liệu char, unsigned int và float:
// Khai báo và gán giá trị vào biến:
	char FullName[20] = "Tran_Minh_Tien", // Tên đầy đủ, gán biến FullName là chuỗi ký tự "TranMinhTien"
		PhoneNumber[15] = "0334196316"; // Số điện thoại, gán biến PhoneNumber là chuỗi ký tự "0334196316"
	unsigned int Age = 26; // Khai báo biến tuổi Age = 26: Kiểu dữ liệu số nguyên không dấu
	float Height = 165.590, // Khai báo biến Chiều cao Height = 165.59 (cm): Kiểu dữ liệu số thực Float
		Weight  = 62.150; // Khai báo biến Cân nặng Weight = 62.15 (Kg): Kiểu dữ liệu số thực Float
	int Select; // Biến lựa chọn tiếp tục hay dừng lại
// In ra kết quả các biến đã lưu
	printf("(FullName)    Ho va ten la    : %s\n", FullName); // In ra Họ và tên, xuống hàng
	printf("(PhoneNumber) So dien thoai la: %s\n", PhoneNumber); // In ra Số điện thoại, xuống hàng
	printf("(Age)         So tuoi la      : %d\n", Age); // In ra Số tuổi, xuống hàng
	printf("(Height)      Chieu cao la    : %.2f %s\n", Height, "(Cm)"); // In ra Chiều cao (Cm), xuống hàng
	printf("(Weight)      Can nang la     : %.3f %s\n", Weight, "(Kg)");// In ra Cân nặng (Kg), xuống hàng
	printf(" \r\n"); // In ra 1 dòng trống
// Hỏi người dùng có muốn tiếp tục chương trình
	printf("Ban co muon nhap thong tin tu ban phim ?\r\n"); // Hỏi người dùng có muốn tiếp tục nhập thông tin
	printf("Neu muon TIEP TUC hay an phim < 1 > Neu muon KET THUC hay an phim < 0 > \r\n"); // Hỏi người dùng có muốn tiếp tục nhập thông tin
// Người dùng nhập sự lựa chọn từ bàn phím hay không
	scanf("%d", &Select);
// Kiểm tra điều kiện người dùng có muốn nhập dữ liệu từ bàn phím hay không
	if (Select == 0) 
	{
		printf("DA CHON KET THUC\r\n"); // Nếu ấn chọn phím < 0 >: KẾT THÚC
	}
	else if (Select == 1) // Nếu ấn chọn phím < 1 >: TIẾP TỤC
	{
		printf("DA CHON TIEP TUC, HAY NHAP THONG TIN SAU:\n"); // Đã chọn TIẾP TỤC
	// Nhập thông tin từ bàn phím
		printf("(FullName)    HAY NHAP Ho va ten    : "); // In ra HÃY NHẬP Họ và tên:
		scanf("%s", FullName); // Nhập từ bàn phím CHUỖI KÝ TỰ (Họ và tên) và gán vào biến FullName
		printf("(PhoneNumber) HAY NHAP So dien thoai: "); // In ra HÃY NHẬP Số điện thoại:
		scanf("%s", PhoneNumber); // Nhập từ bàn phím CHUỖI KÝ TỰ (Số điện thoại) và gán vào biến PhoneNumber
		printf("(Age)         HAY NHAP Do tuoi      : "); // In ra HÃY NHẬP Độ tuổi:
		scanf("%d", &Age); // Nhập từ bàn phím GIÁ TRỊ (Độ tuổi) và gán vào biến Age
		printf("(Height)      HAY NHAP Chieu cao    : "); // In ra HÃY NHẬP Chiều cao:
		scanf("%f", &Height); // Nhập từ bàn phím GIÁ TRỊ (Chiều cao) và gán vào biến Height
		printf("(Weight)      HAY NHAP Can nang     : "); // In ra HÃY NHẬP Cân nặng:
		scanf("%f", &Weight); // Nhập từ bàn phím GIÁ TRỊ (Cân nặng) và gán vào biến Weight
		printf(" \r\n"); // In ra 1 dòng trống
	// In ra để kiểm tra kết quả đã nhập từ bàn phím
		printf("HIEN THI CAC THONG TIN DA NHAP: \n"); // Đã chọn TIẾP TỤC
		printf("(FullName)    Ho va ten la    : %s\n", FullName); // In ra Họ và tên, xuống hàng
		printf("(PhoneNumber) So dien thoai la: %s\n", PhoneNumber); // In ra Số điện thoại, xuống hàng
		printf("(Age)         So tuoi la      : %d\n", Age); // In ra Số tuổi, xuống hàng
		printf("(Height)      Chieu cao la    : %.1f %s\n", Height, "(Cm)"); // In ra Chiều cao (Cm), xuống hàng
		printf("(Weight)      Can nang la     : %.2f %s\n", Weight, "(Kg)");// In ra Cân nặng (Kg), xuống hàng
	}
	printf("KET THUC BAI TAP 1.1.................\r\n"); // KẾT THÚC BÀI TẬP 1.1
    printf("\n");
    return 0;
}