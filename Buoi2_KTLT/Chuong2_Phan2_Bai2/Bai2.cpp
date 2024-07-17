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
// Câu 2 Hàm xuất danh sách hỗn số
void printMixedNumbers(MixedNumber b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].whole, b[i].numerator, b[i].denominator);
    }
}

// Câu 3 Hàm so sánh 2 hỗn số
int compareMixedNumbers(MixedNumber a, MixedNumber b) {
    int a_numerator = a.whole * a.denominator + a.numerator;
    int b_numerator = b.whole * b.denominator + b.numerator;
    int a_value = a_numerator * b.denominator;
    int b_value = b_numerator * a.denominator;
    if (a_value < b_value) return -1;
    else if (a_value > b_value) return 1;
    else return 0;
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
        printf("3. So sanh 2 hon so\n");
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
        case 3:
            printf("Nhap chi so 2 hon so de so sanh (tu 0 đến %d): ", n - 1);
            scanf_s("%d %d", &index1, &index2);
            if (compareMixedNumbers(b[index1], b[index2]) == 0) {
                printf("2 hon so bang nhau.\n");
            }
            else if (compareMixedNumbers(b[index1], b[index2]) < 0) {
                printf("Hon so 1 nho hon hon so 2.\n");
            }
            else {
                printf("Hon so 1 lon hon hon so 2.\n");
            }
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