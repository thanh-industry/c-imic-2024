/* Bài 4: 
Cho mảng {21,321,91,31,5634,213,12,1,2134,2314,-912,-18,312}
Sắp xếp mảng theo thứ tự từ bé đến lớn
*/
#include <stdio.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main() {
    int arr[] = {21, 321, 91, 31, 5634, 213, 12, 1, 2134, 2314, -912, -18, 312};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Mảng sau khi sắp xếp là: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
/*	Con trỏ dữ liệu;
	Struct;
	int c = (a>b)?a:b // C = 1 nếu a > b, ngược lại C = 0;
	a = ++c, nếu c = 10 thì a = 11, do c + 1 = a rồi gán vào a;
	Mệnh đề If, If else, While, do...while, for, Switch...case
*/
/* switch (a) {
case 5:
	a++;
	break;
case 6:
	a--;
	break;
default:
	break;
}
*/
/*
	Do while: thực thi ít nhất một lần
	Tất cả các vòng lặp đều dùng break và continued thì sẽ thoát
	Return: Thoát khỏi vòng lặp
*/