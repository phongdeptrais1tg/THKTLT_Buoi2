#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mssv[10];
    char hoTen[50];
    float dtb;
    char xepLoai[20];
} SinhVien;

void nhapSinhVien(SinhVien* sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten: ");
    getchar(); // Để loại bỏ ký tự newline
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0; // Loại bỏ newline
    printf("Nhap diem trung binh: ");
    scanf_s("%f", &sv->dtb);

    // Xep loai
    if (sv->dtb >= 8) {
        strcpy(sv->xepLoai, "Gioi");
    }
    else if (sv->dtb >= 6.5) {
        strcpy(sv->xepLoai, "Kha");
    }
    else if (sv->dtb >= 5) {
        strcpy(sv->xepLoai, "Trung binh");
    }
    else {
        strcpy(sv->xepLoai, "Yeu");
    }
}

void xuatSinhVien(SinhVien sv) {
    printf("MSSV: %s\n", sv.mssv);
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Diem trung binh: %.2f\n", sv.dtb);
    printf("Xep loai: %s\n", sv.xepLoai);
}

void nhapDanhSach(SinhVien ds[], int* n) {
    printf("Nhap so luong sinh vien: ");
    scanf_s("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&ds[i]);
    }
}

void xuatDanhSach(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin sinh vien thu %d:\n", i + 1);
        xuatSinhVien(ds[i]);
        printf("\n");
    }
}
// Các hàm sắp xếp
void interchangeSort(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].dtb > ds[j].dtb) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void selectionSort(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].dtb < ds[minIdx].dtb) {
                minIdx = j;
            }
        }
        SinhVien temp = ds[i];
        ds[i] = ds[minIdx];
        ds[minIdx] = temp;
    }
}

void quickSort(SinhVien ds[], int left, int right) {
    int i = left, j = right;
    float pivot = ds[(left + right) / 2].dtb;
    while (i <= j) {
        while (ds[i].dtb < pivot) i++;
        while (ds[j].dtb > pivot) j--;
        if (i <= j) {
            SinhVien temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(ds, left, j);
    if (i < right) quickSort(ds, i, right);
}
SinhVien timDiemCaoNhat(SinhVien ds[], int n) {
    SinhVien maxSV = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb > maxSV.dtb) {
            maxSV = ds[i];
        }
    }
    return maxSV;
}

SinhVien timDiemThapNhat(SinhVien ds[], int n) {
    SinhVien minSV = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb < minSV.dtb) {
            minSV = ds[i];
        }
    }
    return minSV;
}


int main() {
    SinhVien ds[100];
    int n = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Sap xep sinh vien theo diem trung binh tang dan (Interchange Sort)\n");
        printf("4. Sap xep sinh vien theo diem trung binh tang dan (Selection Sort)\n");
        printf("5. Sap xep sinh vien theo diem trung binh tang dan (Quick Sort)\n");
        printf("6. Tim sinh vien co diem trung binh cao nhat\n");
        printf("7. Tim sinh vien co diem trung binh thap nhat\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            nhapDanhSach(ds, &n);
            break;
        case 2:
            xuatDanhSach(ds, n);
            break;
        case 3:
            interchangeSort(ds, n);
            printf("Danh sach sinh vien sau khi sap xep (Interchange Sort):\n");
            xuatDanhSach(ds, n);
            break;
        case 4:
            selectionSort(ds, n);
            printf("Danh sach sinh vien sau khi sap xep (Selection Sort):\n");
            xuatDanhSach(ds, n);
            break;
        case 5:
            quickSort(ds, 0, n - 1);
            printf("Danh sach sinh vien sau khi sap xep (Quick Sort):\n");
            xuatDanhSach(ds, n);
            break;
        case 6:
            printf("Sinh vien co diem trung binh cao nhat:\n");
            xuatSinhVien(timDiemCaoNhat(ds, n));
            break;
        case 7:
            printf("Sinh vien co diem trung binh thap nhat:\n");
            xuatSinhVien(timDiemThapNhat(ds, n));
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
