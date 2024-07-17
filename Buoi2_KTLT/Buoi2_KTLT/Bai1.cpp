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
        printf("0. Exit\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            generateRandomArray(a, &n);
            printf("Mang ngau nhien: ");
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