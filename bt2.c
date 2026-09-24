#include <stdio.h>

int main() {
    // 1. Khai bao bien
    int tuoi, ma_phim, ma_ghe, ma_doi_tuong;
    double gia_co_ban = 80000.0;
    double phu_thu_ghe = 0.0;
    double giam_gia = 0.0;
    double gia_sau_giam = 0.0;
    double tong_tien = 0.0;

    // 2. Nhap du lieu dau vao
    printf("--- HE THONG BAN VE PHIM CGV ---\n");
    printf("Nhap tuoi khang gia: ");
    scanf("%d", &tuoi);
    
    printf("Nhap ma loai phim (1-P, 2-T18): ");
    scanf("%d", &ma_phim);
    
    printf("Nhap ma loai ghe (1-Thuong, 2-VIP, 3-Couple): ");
    scanf("%d", &ma_ghe);
    
    printf("Nhap ma doi tuong (1-Thuong, 2-HS/SV): ");
    scanf("%d", &ma_doi_tuong);

    printf("\n"); // In xuong dong cho de nhin

    // 3. Yeu cau 1: Kiem chuan du lieu dau vao (Input Validation)
    if (tuoi <= 0 || (ma_phim != 1 && ma_phim != 2) || (ma_ghe < 1 || ma_ghe > 3) || (ma_doi_tuong != 1 && ma_doi_tuong != 2)) {
        printf("LOI: Du lieu nhap vao khong hop le!\n");
        return 1; // Ket thuc chuong trinh kem ma loi
    }

    // 4. Yeu cau 2: Kiem tra quy dinh gioi han do tuoi
    if (ma_phim == 2 && tuoi < 18) {
        printf("TU CHOI BAN VE: Khang gia chua du 18 tuoi de xem phim T18!\n");
        return 0; // Tu choi ban ve va ket thuc thanh cong giao dich
    }

    // 5. Yeu cau 3: Tinh toan phu thu va chiet khau
    
    // Tinh phu thu ghe bang switch-case
    switch (ma_ghe) {
        case 1:
            phu_thu_ghe = 0.0;
            break;
        case 2:
            phu_thu_ghe = 15000.0;
            break;
        case 3:
            phu_thu_ghe = 30000.0;
            break;
    }

    // Tinh giam gia uu dai bang if-else
    if (ma_doi_tuong == 2) {
        giam_gia = gia_co_ban * 0.20; // Giam 20% tren gia co ban
    } else {
        giam_gia = 0.0;
    }

    // 6. Tong hop cong thuc tinh tien
    gia_sau_giam = gia_co_ban - giam_gia;
    tong_tien = gia_sau_giam + phu_thu_ghe;

    // 7. Yeu cau 4: Hien thi ket qua (Hoa don)
    printf("--- HOA DON THANH TOAN ---\n");
    
    // In phan loai doi tuong
    if (ma_doi_tuong == 1) {
        printf("Doi tuong: Khan gia thong thuong\n");
    } else {
        printf("Doi tuong: Hoc sinh / Sinh vien\n");
    }

    // In phan loai ghe
    if (ma_ghe == 1) {
        printf("Loai ghe: Thuong\n");
    } else if (ma_ghe == 2) {
        printf("Loai ghe: VIP\n");
    } else {
        printf("Loai ghe: Couple\n");
    }

    // In cac thong so tai chinh (ep kieu %.0f de khong in chu so thap phan)
    printf("Gia ve goc: %.0f VND\n", gia_co_ban);
    printf("Giam gia uu dai: %.0f VND\n", giam_gia);
    printf("Phu thu ghe: %.0f VND\n", phu_thu_ghe);
    printf("Tong tien thanh toan: %.0f VND\n", tong_tien);

    return 0;
}