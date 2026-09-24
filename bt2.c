#include <stdio.h>

int main(void) {
    int tuoi;
    int ma_phim;
    int ma_ghe;
    int ma_doi_tuong;

    float gia_ve_goc = 80000.0;
    float phu_thu_ghe = 0.0;
    float giam_gia = 0.0;
    float gia_sau_giam;
    float tong_tien;

    printf("--- HE THONG BAN VE PHIM CGV ---\n");

    // Nhap thong tin
    printf("Nhap tuoi khang gia: ");
    scanf("%d", &tuoi);

    printf("Nhap ma loai phim (1-P, 2-T18): ");
    scanf("%d", &ma_phim);

    printf("Nhap ma loai ghe (1-Thuong, 2-VIP, 3-Couple): ");
    scanf("%d", &ma_ghe);

    printf("Nhap ma doi tuong (1-Thuong, 2-HS/SV): ");
    scanf("%d", &ma_doi_tuong);

    // 1. Kiem tra du lieu dau vao
    if (tuoi <= 0 ||
        (ma_phim != 1 && ma_phim != 2) ||
        (ma_ghe != 1 && ma_ghe != 2 && ma_ghe != 3) ||
        (ma_doi_tuong != 1 && ma_doi_tuong != 2)) {

        printf("\nLOI: Du lieu nhap vao khong hop le!\n");
        return 0;
    }

    // 2. Kiem tra do tuoi phim T18
    if (ma_phim == 2 && tuoi < 18) {
        printf("\nTU CHOI BAN VE: Khang gia chua du 18 tuoi de xem phim T18!\n");
        return 0;
    }

    // 3. Tinh phu thu ghe bang switch-case
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

    // 4. Tinh giam gia bang if - else
    if (ma_doi_tuong == 2) {
        giam_gia = gia_ve_goc * 0.20;
    } else {
        giam_gia = 0.0;
    }

    // Tinh gia sau giam va tong tien
    gia_sau_giam = gia_ve_goc - giam_gia;
    tong_tien = gia_sau_giam + phu_thu_ghe;

    // 5. Xuat hoa don
    printf("\n--- HOA DON THANH TOAN ---\n");

    // Hien thi doi tuong
    if (ma_doi_tuong == 1) {
        printf("Doi tuong: Khach hang thong thuong\n");
    } else {
        printf("Doi tuong: Hoc sinh / Sinh vien\n");
    }

    // Hien thi loai ghe
    switch (ma_ghe) {
        case 1:
            printf("Loai ghe: Thuong\n");
            break;

        case 2:
            printf("Loai ghe: VIP\n");
            break;

        case 3:
            printf("Loai ghe: Couple\n");
            break;
    }

    printf("Gia ve goc: %.0f VND\n", gia_ve_goc);
    printf("Giam gia uu dai: %.0f VND\n", giam_gia);
    printf("Phu thu ghe: %.0f VND\n", phu_thu_ghe);
    printf("Tong tien thanh toan: %.0f VND\n", tong_tien);

    return 0;
}
