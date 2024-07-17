#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Hàm tạo mảng ngẫu nhiên có số phần tử >= 15
void generateRandomArray(int a[], int* n) {
    *n = 15 + rand() % 6; // tạo mảng có từ 15 đến 20 phần tử
    for (int i = 0; i < *n; i++) {
        a[i] = rand() % 100; // các phần tử ngẫu nhiên từ 0 đến 99
    }
}

// Hàm liệt kê các số nguyên tố nhỏ hơn n
void listPrimesLessThanN(int n) {
    int found = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao nho hon %d\n", n);
    }
    else {
        printf("\n");
    }
}

// Hàm in mảng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    srand(time_t(NULL));
    int a[100];
    int n = 0;
    int choice, x;

    do {
        printf("\nMenu:\n");
        printf("1. Liet ke cac so 15 phan tu\n");
        printf("2. Liet ke cac so nguyen to nho hon n\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            generateRandomArray(a, &n);
            printf("Mang ngau nhien: ");
            printArray(a, n);
            break;
        case 2:
            printf("Nhap n: ");
            scanf_s("%d", &x);
            listPrimesLessThanN(x);
            break;
        
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

