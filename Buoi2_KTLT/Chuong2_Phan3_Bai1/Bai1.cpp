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

// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddLeadingDigit(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int firstDigit = a[i];
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}
// Hàm liệt kê số lần xuất hiện của các phần tử trong mảng
void listOccurrences(int a[], int n) {
    int counted[100] = { 0 };
    for (int i = 0; i < n; i++) {
        if (!counted[i]) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == a[i]) {
                    count++;
                    counted[j] = 1;
                }
            }
            printf("%d xuat hien %d lan\n", a[i], count);
        }
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
        printf("3. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("4. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
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
        case 3:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOddLeadingDigit(a, n));
            break;
        case 4:
            listOccurrences(a, n);
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

