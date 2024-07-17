#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Câu 1 tạo mảng ngẫu nhiên 15 phần tử
void generateRandomArray(int a[], int* n) {
    *n = 15 + rand() % 6; 
    for (int i = 0; i < *n; i++) {
        a[i] = rand() % 100;
    }
}

// Câu 2 hàm tạo mảng chứa toàn số chẵn
void generateEvenArray(int a[], int* n) {
    *n = 15 + rand() % 6;
    for (int i = 0; i < *n; i++) {
        a[i] = (rand() % 50) * 2; 
    }
}

// Câu 3 hàm tìm kiếm tuyến tính
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}
// Câu 4 hàm sắp xếp tăng dần bằng Interchange Sort
void interchangeSortAsc(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Câu 4 hàm sắp xếp giảm dần bằng Interchange Sort
void interchangeSortDesc(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
// Câu 5 hàm tìm kiếm nhị phân
int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Câu 6 hàm sắp xếp tăng dần bằng Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = temp;
    }
}
// In mảng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int a[100];
    int n;
    int choice, x, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Tao mang ngau nhien co so phan tu >= 15\n");
        printf("2. Tao mang so chan\n");
        printf("3. Tim kiem tuyen tinh\n");
        printf("4. Sap xep tang dan bang Interchange Sort\n");
        printf("5. Sap xep giam dan bang Interchange Sort\n");
        printf("6. Tim kiem nhi phan\n");
        printf("7. Sap xep tang dan bang Selection Sort\n");
        printf("0. Exit\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            generateRandomArray(a, &n);
            printf("Mang ngau nhien: ");
            printArray(a, n);
            break;
        case 2:
            generateEvenArray(a, &n);
            printf("Mang toan so chan: ");
            printArray(a, n);
            break;
        case 3:
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            pos = linearSearch(a, n, x);
            if (pos != -1) {
                printf(" %d tai vi tri %d\n", x, pos);
            }
            else {
                printf("Khong tim thay %d\n", x);
            }
            break;
        case 4:
            interchangeSortAsc(a, n);
            printf("Mang sau khi tang dan bang Interchange Sort: ");
            printArray(a, n);
            break;
        case 5:
            interchangeSortDesc(a, n);
            printf("Mang sau khi giam dan bang Interchange Sort: ");
            printArray(a, n);
            break;
        case 6:
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            interchangeSortAsc(a, n); 
            pos = binarySearch(a, n, x);
            if (pos != -1) {
                printf(" %d tai vi tri %d\n", x, pos);
            }
            else {
                printf("Khong tim thay %d\n", x);
            }
            break;
        case 7:
            selectionSort(a, n);
            printf("Mang sau khi tang dan Selection Sort: ");
            printArray(a, n);
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