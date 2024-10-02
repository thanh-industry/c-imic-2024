/* Bài 1: 
- Khai báo 5 biến bất kì; ==> Đặt tên 5 biến trong các loại biến đã học
- Đặt tên biến có ý nghĩa; ==> Đặt tên theo từ gợi nhớ Tiếng Anh, có chú thích
- Gán giá trị cho biến; ==> Gán trực tiếp khi khai báo hoặc gán sau
- In ra kết quả để kiểm tra. ==> Dùng hàm printf
*/
// Khai báo thư viện stdio và string:
#include "stdio.h"
#include "string.h"
int main( ) // Chương trình chính
{
// Khai báo 5 biến mang thông tin cá nhân, có kiểu dữ liệu char, unsigned int và float:
// Khai báo và gán giá trị vào biến:
char FullName[] = "Tran_Minh_Tien", // Tên đầy đủ, gán biến FullName là chuỗi ký tự "TranMinhTien"
	 PhoneNumber[] = "0334196316"; // Số điện thoại, gán biến PhoneNumber là chuỗi ký tự "0334196316"
unsigned int Age = 26; // Khai báo biến tuổi Age = 26: Kiểu dữ liệu số nguyên không dấu
float Height = 165.590, // Khai báo biến Chiều cao Height = 165.59 (cm): Kiểu dữ liệu số thực Float
	  Weight  = 62.150; // Khai báo biến Cân nặng Weight = 62.15 (Kg): Kiểu dữ liệu số thực Float
int Select; // Khai báo biến Sự lựa chọn Select của người dùng: Kiểu số nguyên
// In ra kết quả các biến đã lưu
	printf("(FullName)    Họ và tên là    : %s\n", FullName); // In ra Họ và tên, xuống hàng
	printf("(PhoneNumber) Số điện thoại là: %s\n", PhoneNumber); // In ra Số điện thoại, xuống hàng
	printf("(Age)         Số tuổi là      : %d\n", Age); // In ra Số tuổi, xuống hàng
	printf("(Height)      Chiều cao là    : %.2f %s\n", Height, "(Cm)"); // In ra Chiều cao (Cm), xuống hàng
	printf("(Weight)      Cân nặng là     : %.3f %s\n", Weight, "(Kg)");// In ra Cân nặng (Kg), xuống hàng
	printf(" \r\n"); // In ra 1 dòng trống
// Hỏi người dùng có muốn tiếp tục chương trình
	printf("Bạn có muốn nhập thông tin từ bàn phím ?\r\n"); // Hỏi người dùng có muốn tiếp tục nhập thông tin
	printf("Nếu muốn TIẾP TỤC hãy ấn phím < 1 > Nếu muốn KẾT THÚC hãy ấn phím < 0 > \r\n"); // Hỏi người dùng có muốn tiếp tục nhập thông tin
// Người dùng nhập sự lựa chọn từ bàn phím hay không
	scanf("%d", &Select);
// Kiểm tra điều kiện người dùng có muốn nhập dữ liệu từ bàn phím hay không
	if (Select == 0) 
	{
		printf("ĐÃ CHỌN KẾT THÚC\r\n"); // Nếu ấn chọn phím < 0 >: KẾT THÚC
	}
	else if (Select == 1) // Nếu ấn chọn phím < 1 >: TIẾP TỤC
	{
		printf("ĐÃ CHỌN TIẾP TỤC, HÃY NHẬP THÔNG TIN SAU:\n"); // Đã chọn TIẾP TỤC
	// Nhập thông tin từ bàn phím
		printf("(FullName)    HÃY NHẬP Họ và tên    : "); // In ra HÃY NHẬP Họ và tên:
		scanf("%s", &FullName); // Nhập từ bàn phím CHUỖI KÝ TỰ (Họ và tên) và gán vào biến FullName
		printf("(PhoneNumber) HÃY NHẬP Số điện thoại: "); // In ra HÃY NHẬP Số điện thoại:
		scanf("%s", &PhoneNumber); // Nhập từ bàn phím CHUỖI KÝ TỰ (Số điện thoại) và gán vào biến PhoneNumber
		printf("(Age)         HÃY NHẬP Độ tuổi      : "); // In ra HÃY NHẬP Độ tuổi:
		scanf("%d", &Age); // Nhập từ bàn phím GIÁ TRỊ (Độ tuổi) và gán vào biến Age
		printf("(Height)      HÃY NHẬP Chiều cao    : "); // In ra HÃY NHẬP Chiều cao:
		scanf("%f", &Height); // Nhập từ bàn phím GIÁ TRỊ (Chiều cao) và gán vào biến Height
		printf("(Weight)      HÃY NHẬP Cân nặng     : "); // In ra HÃY NHẬP Cân nặng:
		scanf("%f", &Weight); // Nhập từ bàn phím GIÁ TRỊ (Cân nặng) và gán vào biến Weight
		printf(" \r\n"); // In ra 1 dòng trống
	// In ra để kiểm tra kết quả đã nhập từ bàn phím
		printf("HIỂN THỊ CÁC THÔNG TIN ĐÃ NHẬP: \n"); // Đã chọn TIẾP TỤC
		printf("(FullName)    Họ và tên là    : %s\n", FullName); // In ra Họ và tên, xuống hàng
		printf("(PhoneNumber) Số điện thoại là: %s\n", PhoneNumber); // In ra Số điện thoại, xuống hàng
		printf("(Age)         Số tuổi là      : %d\n", Age); // In ra Số tuổi, xuống hàng
		printf("(Height)      Chiều cao là    : %.1f %s\n", Height, "(Cm)"); // In ra Chiều cao (Cm), xuống hàng
		printf("(Weight)      Cân nặng là     : %.2f %s\n", Weight, "(Kg)");// In ra Cân nặng (Kg), xuống hàng
	}
}