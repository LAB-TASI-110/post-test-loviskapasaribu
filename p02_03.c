// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>

int main() {

    int jumlahMenu;
    int i;

    char namaMenu[50][50];
    int jumlahPesanan[50];
    float hargaMenu[50];
    float totalMenu[50];

    float totalBayar = 0;

    printf("====================================\n");
    printf("   SISTEM PEMESANAN KAFETARIA DEL\n");
    printf("====================================\n");

    printf("Masukkan jumlah jenis menu yang dipesan: ");
    scanf("%d", &jumlahMenu);

    printf("\n");

    // Input data pesanan
    for(i = 0; i < jumlahMenu; i++) {

        printf("Pesanan ke-%d\n", i+1);

        printf("Nama Menu   : ");
        scanf("%s", namaMenu[i]);

        printf("Jumlah      : ");
        scanf("%d", &jumlahPesanan[i]);

        printf("Harga Satuan: ");
        scanf("%f", &hargaMenu[i]);

        totalMenu[i] = jumlahPesanan[i] * hargaMenu[i];

        totalBayar += totalMenu[i];

        printf("\n");
    }

    // Menampilkan struk
    printf("\n====================================\n");
    printf("          STRUK PEMESANAN\n");
    printf("          KAFETARIA DEL\n");
    printf("====================================\n");

    printf("No\tMenu\tJumlah\tHarga\tTotal\n");

    for(i = 0; i < jumlahMenu; i++) {
        printf("%d\t%s\t%d\t%.2f\t%.2f\n",
               i+1,
               namaMenu[i],
               jumlahPesanan[i],
               hargaMenu[i],
               totalMenu[i]);
    }

    printf("====================================\n");
    printf("TOTAL PEMBAYARAN : Rp %.2f\n", totalBayar);
    printf("====================================\n");
    printf("Terima kasih telah memesan di\n");
    printf("Kafetaria IT Del\n");

    return 0;
}