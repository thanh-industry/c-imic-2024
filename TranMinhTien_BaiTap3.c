/* Bài 3: 
phân tích sự khác nhau giữa Struct và Union

Struct và Union đều là những kiểu dữ liệu phức hợp trong ngôn ngữ lập trình C, cho phép tổ chức và quản lý nhiều biến liên quan nhau. 
Dưới đây là phân tích những điểm giống và khác nhau giữa chúng.

* Điểm giống nhau:
- Cả hai đều là kiểu dữ liệu phức hợp: Cả struct và union cho phép nhóm nhiều biến khác nhau thành một đơn vị duy nhất.
- Cú pháp khai báo: Cả hai đều được khai báo bằng từ khóa Struct và Union, có thể chứa các kiểu dữ liệu khác nhau.
- Truy xuất đến thành viên: Có thể truy xuất các thành viên của Struct và Union bằng dấu chấm (.) hoặc dấu mũi tên (->) khi làm việc với con trỏ.

* Điểm khác nhau: 
- Quản lý bộ nhớ:
	+ Struct: Mỗi thành viên trong struct có không gian bộ nhớ riêng biệt. Kích thước của Struct là TỔNG kích thước của TẤT CẢ các THÀNH VIÊN.
	+ Union: Tất cả các thành viên của union chia sẻ cùng một không gian bộ nhớ. Kích thước của Union bằng kích thước của THÀNH VIÊN LỚN NHẤT.
- Thời gian sử dụng:
	+ Struct: Có thể sử dụng tất cả các thành viên cùng một lúc.
	+ Union: Chỉ một thành viên có thể được sử dụng tại một thời điểm. Nếu ta ghi đè lên một thành viên, giá trị của thành viên khác sẽ bị mất.

* Ví dụ minh họa:
- Sử dụng Struct:
	#include <stdio.h>
	#include <string.h>

	struct Student { // Định nghĩa cấu trúc Student
		char name[30]; // 
		int age;
		float gpa;
	};
	int main() { // Chương trình chính
		struct Student student1 = {"Nguyen Van A", 20, 3.495};
		printf("Tên : %s\n"  , student1.name);
		printf("Tuổi: %d\n"  , student1.age);
		printf("GPA : %.2f\n", student1.gpa);
		return 0;
	}
- Sử dụng Union:
	#include <stdio.h>
	#include <string.h>

	union Data { // Định nghĩa union Data
		int intValue;
		float floatValue;
		char charValue;
	};
	int main() { // Chương trình chính
		union Data data; 
		data.intValue = 10; // Gán giá trị cho intValue
		printf("Giá trị int: %d\n", data.intValue);
		data.floatValue = 220.5; // Gán giá trị cho floatValue
		printf("Giá trị float: %.2f\n", data.floatValue);
		data.charValue = 'A'; // Gán giá trị cho charValue
		printf("Giá trị char: %c\n", data.charValue);
		// Lưu ý: Các giá trị trước đó sẽ không còn hợp lệ
		printf("Giá trị int sau khi gán char: %d\n", data.intValue);
		return 0;
	}
* Kết luận:
- Struct là lựa chọn tốt khi bạn cần lưu trữ nhiều thuộc tính của một đối tượng và sử dụng chúng cùng một lúc.
- Union là lựa chọn hợp lý khi bạn cần tiết kiệm bộ nhớ và chỉ cần lưu trữ một thuộc tính tại một thời điểm.
*/