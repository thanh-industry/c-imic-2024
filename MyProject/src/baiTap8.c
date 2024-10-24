#include <stdio.h>


// Hàm để in kết quả
void printResult(int (*func)(int, int), int x, int y) {
    int result = func(x, y); // Gọi hàm thông qua con trỏ
    printf("Result: %d\n", result);
}
