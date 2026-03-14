// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>
#include <string.h>

int main(){

    char kode[10];
    char kota[20];
    char kategori[20];

    int tarif;
    int beratButet;
    int beratUcok;
    int totalBerat;
    int totalOngkir;

    while(1){

        scanf("%s", kode);

        if(strcmp(kode,"END")==0){
            break;
        }

        // menentukan kota dan tarif
        if(strcmp(kode,"MDN")==0){
            strcpy(kota,"Medan");
            tarif = 8000;
            strcpy(kategori,"Dalam Pulau");
        }
        else if(strcmp(kode,"BLG")==0){
            strcpy(kota,"Balige");
            tarif = 5000;
            strcpy(kategori,"Dalam Pulau");
        }
        else if(strcmp(kode,"JKT")==0){
            strcpy(kota,"Jakarta");
            tarif = 12000;
            strcpy(kategori,"Luar Pulau");
        }
        else if(strcmp(kode,"SBY")==0){
            strcpy(kota,"Surabaya");
            tarif = 13000;
            strcpy(kategori,"Luar Pulau");
        }

        scanf("%d",&beratButet);

        // berat ucok
        beratUcok = (3 * beratButet) / 2;

        // total berat
        totalBerat = beratButet + beratUcok;

        // total ongkir awal
        totalOngkir = totalBerat * tarif;

        printf("\n===== STRUK DEL EXPRESS =====\n");
        printf("Kota Tujuan   : %s\n", kota);
        printf("Berat Butet   : %d kg\n", beratButet);
        printf("Berat Ucok    : %d kg\n", beratUcok);
        printf("Total Berat   : %d kg\n", totalBerat);

        // cek promo
        if(totalBerat > 10){
            int diskon = totalOngkir * 0.10;
            totalOngkir -= diskon;
            printf("Promo         : Diskon Ongkir 10%%\n");
        }

        if(strcmp(kategori,"Luar Pulau")==0){
            printf("Bonus         : Asuransi Gratis\n");
        }

        printf("Total Ongkir  : Rp %d\n", totalOngkir);
        printf("==============================\n");

    }

    return 0;
}