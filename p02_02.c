// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>

int main() {
    
    int N;
    int stok[100];
    char kategori[100];
    char cari;
    int total = 0;

    printf("=== SISTEM PENGELOMPOKAN STOK GUDANG ===\n");

    // Input jumlah data
    printf("Masukkan jumlah data barang: ");
    scanf("%d", &N);

    // Input stok barang
    printf("\nMasukkan data stok barang:\n");
    for(int i = 0; i < N; i++) {
        printf("Stok barang ke-%d : ", i + 1);
        scanf("%d", &stok[i]);
    }

    // Input kategori barang
    printf("\nMasukkan kategori tiap barang (A/B/C):\n");
    for(int i = 0; i < N; i++) {
        printf("Kategori barang ke-%d : ", i + 1);
        scanf(" %c", &kategori[i]);
    }

    // Input kategori yang dicari
    printf("\nMasukkan kode kategori yang ingin dicari: ");
    scanf(" %c", &cari);

    // Proses menghitung total stok kategori tertentu
    for(int i = 0; i < N; i++) {
        if(kategori[i] == cari) {
            total += stok[i];
        }
    }

    // Output
    printf("\nKategori yang dicari : %c\n", cari);
    printf("Total stok barang dalam kategori tersebut : %d\n", total);

    return 0;
}