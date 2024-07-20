#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int whole;
    int numerator;
    int denominator;
} MixedNumber;

// Hàm tạo hỗn số ngẫu nhiên
MixedNumber generateRandomMixedNumber() {
    MixedNumber mn;
    mn.whole = rand() % 10;
    mn.numerator = rand() % 10;
    mn.denominator = (rand() % 9) + 1; // tránh mẫu số bằng 0
    return mn;
}

// Hàm xuất danh sách hỗn số
void printMixedNumbers(MixedNumber b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d ", b[i].whole, b[i].numerator, b[i].denominator);
    }
    printf("\n");
}
// Hàm tìm hỗn số x theo Linear Search
int linearSearch(MixedNumber b[], int n, MixedNumber x) {
    for (int i = 0; i < n; i++) {
        if (b[i].whole == x.whole && b[i].numerator == x.numerator && b[i].denominator == x.denominator) {
            return i;
        }
    }
    return -1;
}

// Hàm nhập hỗn số từ người dùng
MixedNumber inputMixedNumber() {
    MixedNumber x;
    printf("Nhap hon so (dinh dang: whole numerator/denominator): ");
    scanf_s("%d %d/%d", &x.whole, &x.numerator, &x.denominator);
    return x;
}

// Hàm sắp xếp hỗn số theo phần nguyên chẵn lên đầu, phần nguyên lẻ ở cuối
void sortMixedNumbersEvenOdd(MixedNumber b[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && b[i].whole % 2 == 0) i++;
        while (i < j && b[j].whole % 2 != 0) j--;
        if (i < j) {
            MixedNumber temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
}

// Hàm sắp xếp mảng hỗn số tăng dần theo phần nguyên
int compareMixedNumbers(MixedNumber a, MixedNumber b) {
    if (a.whole != b.whole) return a.whole - b.whole;
    double fracA = (double)a.numerator / a.denominator;
    double fracB = (double)b.numerator / b.denominator;
    return (fracA < fracB) ? -1 : (fracA > fracB);
}

void sortMixedNumbersAsc(MixedNumber b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compareMixedNumbers(b[i], b[j]) > 0) {
                MixedNumber temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

// Hàm tìm hỗn số x theo Binary Search trong mảng đã sắp xếp
int binarySearch(MixedNumber b[], int n, MixedNumber x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (compareMixedNumbers(b[mid], x) == 0) {
            return mid;
        }
        else if (compareMixedNumbers(b[mid], x) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    srand(time(NULL));
    MixedNumber b[100];
    int n = 0;
    int choice, index;
    MixedNumber x;
    int s1[100];
    double s2[100], c[100];

    do {
        printf("\nMenu:\n");
        printf("1. Tao mang b chua gia tri hon so ngau nhien\n");
        printf("2. Xuat danh sach hon so\n");
        printf("3. Tim hon so x theo Linear Search\n");
        printf("4. Sap xep b theo phan nguyen chan len dau, le o cuoi\n");
        printf("5. Tim hon so x theo Binary Search trong mang da sap xep\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Nhap so phan tu: ");
            scanf_s("%d", &n);
            for (int i = 0; i < n; i++) {
                b[i] = generateRandomMixedNumber();
            }
            break;
        case 2:
            printMixedNumbers(b, n);
            break;
        case 3:
            x = inputMixedNumber();
            index = linearSearch(b, n, x);
            if (index != -1) {
                printf("Tim thay hon so tai vi tri %d\n", index);
            }
            else {
                printf("Khong tim thay hon so\n");
            }
            break;
        case 4:
            sortMixedNumbersEvenOdd(b, n);
            printMixedNumbers(b, n);
            break;
        case 5:
            sortMixedNumbersAsc(b, n);
            printf("Nhap hon so can tim (whole numerator denominator): ");
            scanf_s("%d %d %d", &x.whole, &x.numerator, &x.denominator);
            index = binarySearch(b, n, x);
            if (index != -1) {
                printf("Tim thay hon so tai vi tri %d\n", index);
            }
            else {
                printf("Khong tim thay hon so\n");
            }
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