// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>

int main() {
    int n, i, j, k = 0;
    
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int data[n];

    printf("Masukkan stok barang:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Menentukan ukuran matriks (misal dibuat mendekati persegi)
    int rows = 2; 
    int cols = (n + 1) / 2;

    int rak[rows][cols];

    // Isi zigzag
    k = 0;
    for(i = 0; i < rows; i++) {
        if(i % 2 == 0) {
            // kiri ke kanan
            for(j = 0; j < cols && k < n; j++) {
                rak[i][j] = data[k++];
            }
        } else {
            // kanan ke kiri
            for(j = cols - 1; j >= 0 && k < n; j--) {
                rak[i][j] = data[k++];
            }
        }
    }

    // tampilkan rak
    printf("\nSusunan rak (zigzag):\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%3d ", rak[i][j]);
        }
        printf("\n");
    }

    int kategori, total = 0;

    printf("\nMasukkan kategori (0 atau 1): ");
    scanf("%d", &kategori);

    // Hitung berdasarkan kolom (kategori)
    for(i = 0; i < rows; i++) {
        if(kategori < cols) {
            total += rak[i][kategori];
        }
    }

    printf("\nKode Kategori: %d\n", kategori);
    printf("Total Stok: %d\n", total);

    return 0;
}