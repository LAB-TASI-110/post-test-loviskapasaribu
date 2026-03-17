// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>
#include <string.h>

// Fungsi untuk menentukan ongkir dan keterangan kota
void getDataKota(char kode[], int *ongkir, char keterangan[]) {
    if (strcmp(kode, "MDN") == 0) {
        *ongkir = 8000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "BLG") == 0) {
        *ongkir = 5000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "JKT") == 0) {
        *ongkir = 12000;
        strcpy(keterangan, "Luar Pulau");
    } else if (strcmp(kode, "SBY") == 0) {
        *ongkir = 13000;
        strcpy(keterangan, "Luar Pulau");
    } else {
        *ongkir = 0;
        strcpy(keterangan, "Tidak Diketahui");
    }
}

// Fungsi hitung berat Ucok (simulasi dari ukuran dus)
float hitungUcok(float beratButet) {
    return 0.2 * beratButet; // 20% dari berat Butet
}

int main() {
    char kode[10];
    float beratButet;

    printf("=== SISTEM PENGIRIMAN DEL EXPRES ===\n");

    while (1) {
        printf("\nMasukkan kode tujuan (MDN/BLG/JKT/SBY) atau END: ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            break;
        }

        printf("Masukkan berat paket (kg): ");
        scanf("%f", &beratButet);

        int ongkir;
        char keterangan[20];

        getDataKota(kode, &ongkir, keterangan);

        float beratUcok = hitungUcok(beratButet);
        float totalBerat = beratButet + beratUcok;
        float totalOngkir = totalBerat * ongkir;

        float diskon = 0;
        int asuransiGratis = 0;

        // Promo
        if (totalBerat > 10) {
            diskon = 0.1 * totalOngkir;
        }

        if (strcmp(keterangan, "Luar Pulau") == 0) {
            asuransiGratis = 1;
        }

        float totalBayar = totalOngkir - diskon;

        // OUTPUT STRUK
        printf("\n==============================\n");
        printf("        STRUK PEMBAYARAN      \n");
        printf("==============================\n");
        printf("Kota Tujuan      : %s\n", kode);
        printf("Kategori         : %s\n", keterangan);
        printf("Berat Butet      : %.2f kg\n", beratButet);
        printf("Berat Ucok       : %.2f kg\n", beratUcok);
        printf("Total Berat      : %.2f kg\n", totalBerat);
        printf("Ongkir / kg      : Rp%d\n", ongkir);
        printf("Total Ongkir     : Rp%.2f\n", totalOngkir);
        printf("Diskon           : Rp%.2f\n", diskon);
        printf("------------------------------\n");
        printf("TOTAL BAYAR      : Rp%.2f\n", totalBayar);

        if (diskon > 0) {
            printf("Promo            : Diskon 10%%\n");
        }

        if (asuransiGratis) {
            printf("Bonus            : Asuransi Gratis\n");
        }

        printf("==============================\n");
    }

    printf("\nTerima kasih telah menggunakan layanan Del Expres.\n");

    return 0;
}