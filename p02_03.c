// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>
#include <string.h>

int main() {
    char nama[50], menu[50];
    int jumlah, i, n;
    float harga, total_item, total_semua = 0;
    float diskon = 0, total_bayar;

    printf("===== KAFETARIA IT DEL =====\n");
    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &n);
    getchar(); // membersihkan newline

    // Loop input pesanan
    for(i = 1; i <= n; i++) {
        printf("\nPesanan ke-%d\n", i);

        printf("Nama pembeli   : ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;

        printf("Nama menu      : ");
        fgets(menu, sizeof(menu), stdin);
        menu[strcspn(menu, "\n")] = 0;

        printf("Harga          : ");
        scanf("%f", &harga);

        printf("Jumlah beli    : ");
        scanf("%d", &jumlah);
        getchar();

        total_item = harga * jumlah;
        total_semua += total_item;

        printf("Total pesanan  : Rp %.2f\n", total_item);
    }

    // Hitung diskon
    if(total_semua >= 100000) {
        diskon = 0.10 * total_semua;
    } else if(total_semua >= 50000) {
        diskon = 0.05 * total_semua;
    }

    total_bayar = total_semua - diskon;

    // Output struk
    printf("\n===== STRUK PEMBAYARAN =====\n");
    printf("Total Belanja : Rp %.2f\n", total_semua);
    printf("Diskon        : Rp %.2f\n", diskon);
    printf("Total Bayar   : Rp %.2f\n", total_bayar);
    printf("============================\n");
    printf("Terima kasih telah berbelanja!\n");

    return 0;
}