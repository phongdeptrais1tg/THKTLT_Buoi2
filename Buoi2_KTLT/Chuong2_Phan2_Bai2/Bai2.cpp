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
// Câu 4 Hàm chuyển hỗn số thành phân số
void mixedToFraction(MixedNumber a, int* numerator, int* denominator) {
    *numerator = a.whole * a.denominator + a.numerator;
    *denominator = a.denominator;
}
// Câu 5 Hàm chuyển phân số thành hỗn số
MixedNumber fractionToMixed(int numerator, int denominator) {
    MixedNumber result;
    result.whole = numerator / denominator;
    result.numerator = numerator % denominator;
    result.denominator = denominator;
    return result;
}
// Hàm tính tổng 2 hỗn số
MixedNumber addMixedNumbers(MixedNumber a, MixedNumber b) {
    int num_a, den_a, num_b, den_b;
    mixedToFraction(a, &num_a, &den_a);
    mixedToFraction(b, &num_b, &den_b);
    int numerator = num_a * den_b + num_b * den_a;
    int denominator = den_a * den_b;
    return fractionToMixed(numerator, denominator);
}

// Hàm tính hiệu 2 hỗn số
MixedNumber subtractMixedNumbers(MixedNumber a, MixedNumber b) {
    int num_a, den_a, num_b, den_b;
    mixedToFraction(a, &num_a, &den_a);
    mixedToFraction(b, &num_b, &den_b);
    int numerator = num_a * den_b - num_b * den_a;
    int denominator = den_a * den_b;
    return fractionToMixed(numerator, denominator);
}

// Hàm tính tích 2 hỗn số
MixedNumber multiplyMixedNumbers(MixedNumber a, MixedNumber b) {
    int num_a, den_a, num_b, den_b;
    mixedToFraction(a, &num_a, &den_a);
    mixedToFraction(b, &num_b, &den_b);
    int numerator = num_a * num_b;
    int denominator = den_a * den_b;
    return fractionToMixed(numerator, denominator);
}

// Hàm tính thương 2 hỗn số
MixedNumber divideMixedNumbers(MixedNumber a, MixedNumber b) {
    int num_a, den_a, num_b, den_b;
    mixedToFraction(a, &num_a, &den_a);
    mixedToFraction(b, &num_b, &den_b);
    int numerator = num_a * den_b;
    int denominator = den_a * num_b;
    return fractionToMixed(numerator, denominator);
}
// Hàm sắp xếp tăng dần bằng Interchange Sort
void interchangeSortAsc(MixedNumber b[], int n) {
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

// Hàm sắp xếp giảm dần bằng Interchange Sort
void interchangeSortDesc(MixedNumber b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compareMixedNumbers(b[i], b[j]) < 0) {
                MixedNumber temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp tăng dần bằng Selection Sort
void selectionSortAsc(MixedNumber b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (compareMixedNumbers(b[j], b[minIdx]) < 0) {
                minIdx = j;
            }
        }
        MixedNumber temp = b[i];
        b[i] = b[minIdx];
        b[minIdx] = temp;
    }
}

// Hàm sắp xếp tăng dần bằng Quick Sort
void quickSortAsc(MixedNumber b[], int left, int right) {
    if (left < right) {
        MixedNumber pivot = b[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (compareMixedNumbers(b[j], pivot) < 0) {
                i++;
                MixedNumber temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
        MixedNumber temp = b[i + 1];
        b[i + 1] = b[right];
        b[right] = temp;
        int p = i + 1;
        quickSortAsc(b, left, p - 1);
        quickSortAsc(b, p + 1, right);
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
        printf("3. So sanh 2 hon so\n");
        printf("4. Chuyen hon so thanh phan so\n");
        printf("5. Chuyen phan so thanh hon so\n");
        printf("6. Tinh tong,hieu,tich,thuong cua 2 hon so\n");
        printf("7. Sap xep b tang/giam theo 3 giai thuat da hoc\n");
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
        case 4:
            printf("Nhap hon so thanh phan so (tu 0 den %d): ", n - 1);
            scanf_s("%d", &index1);
            mixedToFraction(b[index1], &num, &den);
            printf("Phan so: %d/%d\n", num, den);
            break;
        case 5:
            printf("Nhap phan so ");
            scanf_s("%d %d", &num, &den);
            result = fractionToMixed(num, den);
            printf("Hon so: %d %d/%d\n", result.whole, result.numerator, result.denominator);
            break;
        case 6:
            printf("Nhap 2 hon so (tu 0 den %d): ", n - 1);
            scanf_s("%d %d", &index1, &index2);
            result = addMixedNumbers(b[index1], b[index2]);
            printf("Tong: %d %d/%d\n", result.whole, result.numerator, result.denominator);
            result = subtractMixedNumbers(b[index1], b[index2]);
            printf("Hieu: %d %d/%d\n", result.whole, result.numerator, result.denominator);
            result = multiplyMixedNumbers(b[index1], b[index2]);
            printf("Tich: %d %d/%d\n", result.whole, result.numerator, result.denominator);
            result = divideMixedNumbers(b[index1], b[index2]);
            printf("Thuong: %d %d/%d\n", result.whole, result.numerator, result.denominator);
            break;
        case 7:
            printf("Chon phuong phap sap xep:\n");
            printf("1. Interchange Sort tang dan\n");
            printf("2. Interchange Sort giam dan\n");
            printf("3. Selection Sort tang dan\n");
            printf("4. Quick Sort tang dan\n");
            scanf_s("%d", &choice);
            switch (choice) {
            case 1:
                interchangeSortAsc(b, n);
                printf("Mang duoc sap xep tang dan bang Interchange Sort.\n");
                break;
            case 2:
                interchangeSortDesc(b, n);
                printf("Mang da duoc sap xep giam dan bang Interchange Sort.\n");
                break;
            case 3:
                selectionSortAsc(b, n);
                printf("Mang da duoc sap xep tang dan bang Selection Sort.\n");
                break;
            case 4:
                quickSortAsc(b, 0, n - 1);
                printf("Mang da duoc sap xep tang dan bang Quick Sort.\n");
                break;
            default:
                printf("Lua chon!\n");
                break;
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