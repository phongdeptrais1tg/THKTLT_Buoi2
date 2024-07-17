#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int whole;
    int numerator;
    int denominator;
} MixedNumber;

// Câu 1 Hàm tạo hỗn số ngẫu nhiên
void generateRandomMixedNumbers(MixedNumber b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i].whole = rand() % 10;
        b[i].numerator = rand() % 10;
        b[i].denominator = 1 + rand() % 9; // mẫu số khác 0
    }
}
// Hàm xuất danh sách hỗn số
void printMixedNumbers(MixedNumber b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].whole, b[i].numerator, b[i].denominator);
    }
}

int main() {
    srand(time(NULL));
    int n, choice;
    printf("Nhap so phan tu cua mang hon so: ");
    scanf_s("%d", &n);
    MixedNumber b[100];
    MixedNumber result;
    int num, den;
    int index1, index2;

    do {
        printf("\nMenu:\n");
        printf("1. Tao mang b chua gia tri hon so ngau nhien\n");
        printf("2. Xuat danh sach hon so\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            generateRandomMixedNumbers(b, n);
            printf("Mang hon so ngau nhien da duoc tao.\n");
            break;
        case 2:
            printf("Danh sach hon so:\n");
            printMixedNumbers(b, n);
            break;
        case 0:
            printf("Exit.\n");
            break;
        default:
            printf("Lua chon ko hop le!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}