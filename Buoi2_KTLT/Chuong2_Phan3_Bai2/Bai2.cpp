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
// Hàm chia mảng b thành 2 mảng s1 và s2
void splitArray(MixedNumber b[], int n, int s1[], double s2[]) {
    for (int i = 0; i < n; i++) {
        s1[i] = b[i].whole;
        s2[i] = (double)b[i].numerator / b[i].denominator;
    }
}
// Hàm xóa phần tử thứ k trong mảng b
void deleteElement(MixedNumber b[], int* n, int k) {
    if (k >= 0 && k < *n) {
        for (int i = k; i < *n - 1; i++) {
            b[i] = b[i + 1];
        }
        (*n)--;
    }
    else {
        printf("Vi tri khong hop le!\n");
    }
}

// Hàm thêm hỗn số x vào mảng b tại vị trí k
void insertElement(MixedNumber b[], int* n, MixedNumber x, int k) {
    if (k >= 0 && k <= *n) {
        for (int i = *n; i > k; i--) {
            b[i] = b[i - 1];
        }
        b[k] = x;
        (*n)++;
    }
    else {
        printf("Vi tri khong hop le!\n");
    }
}

// Hàm tạo mảng c chứa các phần tử là phân số được đổi từ hỗn số của mảng b
void createFractionArray(MixedNumber b[], int n, double c[]) {
    for (int i = 0; i < n; i++) {
        c[i] = b[i].whole + (double)b[i].numerator / b[i].denominator;
    }
}

// Hàm tính tổng các phần tử của mảng b
double sumMixedNumbers(MixedNumber b[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i].whole + (double)b[i].numerator / b[i].denominator;
    }
    return sum;
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
        printf("6. Chia mang b thanh 2 mang s1 va s2\n");
        printf("7. Xoa phan tu thu k trong mang b\n");
        printf("8. Them hon so x vao mang b tai vi tri k\n");
        printf("9. Tao mang c chua cac phan tu la phan so tu hon so cua b\n");
        printf("10. Tinh tong cac phan tu cua mang b\n");
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
        case 6:
            splitArray(b, n, s1, s2);
            printf("Mang s1 (phan nguyen): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", s1[i]);
            }
            printf("\nMang s2 (phan so): ");
            for (int i = 0; i < n; i++) {
                printf("%0.2f ", s2[i]);
            }
            printf("\n");
            break;
        case 7:
            printf("Nhap vi tri can xoa: ");
            int k;
            scanf_s("%d", &k);
            deleteElement(b, &n, k);
            printMixedNumbers(b, n);
            break;
        case 8:
            printf("Nhap hon so can them (whole numerator denominator): ");
            scanf_s("%d %d %d", &x.whole, &x.numerator, &x.denominator);
            printf("Nhap vi tri can them: ");
            scanf_s("%d", &k);
            insertElement(b, &n, x, k);
            printMixedNumbers(b, n);
            break;
        case 9:
            createFractionArray(b, n, c);
            printf("Mang c (phan so tu hon so cua b): ");
            for (int i = 0; i < n; i++) {
                printf("%0.2f ", c[i]);
            }
            printf("\n");
            break;
        case 10:
            printf("Tong cac phan tu cua mang b: %0.2f\n", sumMixedNumbers(b, n));
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