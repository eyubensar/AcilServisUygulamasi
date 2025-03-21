#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hasta bilgilerini tutan yapi
struct Hasta {
    char ad[50];
    int yas;
    int aciliyet; // 1: Dusuk, 2: Orta, 3: Yuksek
    struct Hasta *sonraki;
};

// Oncelikli kuyruk 
struct Hasta *ilk = NULL;

// HL7 formatinda hasta bilgisi icin fonksiyon
void hl7HastaBilgisi(struct Hasta *hasta) {
    printf("HL7 Hasta Kaydi: PID|1|%s|%d|%d\n", hasta->ad, hasta->yas, hasta->aciliyet);
}

// Oncelikli hasta ekleme icin fonksiyon
void hastaEkle(char ad[], int yas, int aciliyet) {
    struct Hasta *yeni = (struct Hasta*)malloc(sizeof(struct Hasta));
    if (yeni == NULL) {
        printf("Hata: Bellek tahsis edilemedi!\n");
        return;
    }
    strcpy(yeni->ad, ad);
    yeni->yas = yas;
    yeni->aciliyet = aciliyet;
    yeni->sonraki = NULL;
    
    if (ilk == NULL || ilk->aciliyet < aciliyet) {
        yeni->sonraki = ilk;
        ilk = yeni;
    } else {
        struct Hasta *gecici = ilk;
        while (gecici->sonraki != NULL && gecici->sonraki->aciliyet >= aciliyet) {
            gecici = gecici->sonraki;
        }
        yeni->sonraki = gecici->sonraki;
        gecici->sonraki = yeni;
    }
    printf("Hasta kaydedildi: %s\n", ad);
}

// Hasta listesini goruntuleme void fonk
void hastaListele() {
    struct Hasta *gecici = ilk;
    if (gecici == NULL) {
        printf("Hasta listesi bos.\n");
        return;
    }
    printf("\nAcil Servis Hasta Listesi:\n");
    while (gecici != NULL) {
        printf("Ad: %s, Yas: %d, Aciliyet: %d\n", gecici->ad, gecici->yas, gecici->aciliyet);
        gecici = gecici->sonraki;
    }
}

// Ilk hastayi isleme alma 
void hastaIslem() {
    if (ilk == NULL) {
        printf("Islem yapilacak hasta yok.\n");
        return;
    }
    struct Hasta *gecici = ilk;
    printf("\nIsleme alinan hasta: %s\n", gecici->ad);
    hl7HastaBilgisi(gecici);
    ilk = ilk->sonraki;
    free(gecici);
}

// Recete yazma fonksiyonu
void receteYaz() {
    if (ilk == NULL) {
        printf("Recete yazilacak hasta yok.\n");
        return;
    }
    srand(time(NULL)); // Rastgele sayı üreteci için
    int receteNo = rand() % 900000 + 100000; // 100000 - 999999 arasi recete numarasi
    printf("Recete yazildi: %s icin ilac recete edildi. Recete No: %d\n", ilk->ad, receteNo);
}

// Hasta silme fonksiyonu
void hastaSil(char ad[]) {
    struct Hasta *gecici = ilk, *onceki = NULL;
    while (gecici != NULL && strcmp(gecici->ad, ad) != 0) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    if (gecici == NULL) {
        printf("Hasta bulunamadi.\n");
        return;
    }
    if (onceki == NULL) {
        ilk = gecici->sonraki;
    } else {
        onceki->sonraki = gecici->sonraki;
    }
    free(gecici);
    printf("Hasta silindi: %s\n", ad);
}

// Toplam hasta sayisini bulma fonksiyonu
int toplamHastaSayisi() {
    int sayac = 0;
    struct Hasta *gecici = ilk;
    while (gecici != NULL) {
        sayac++;
        gecici = gecici->sonraki;
    }
    return sayac;
}

// Ana fonksiyon 
int main() {
    int secim, yas, aciliyet;
    char ad[50];
    
    while (1) {
        printf("\n1 - Hasta Ekle\n");
        printf("2 - Hasta Listele\n");
        printf("3 - Hasta Isleme Al\n");
        printf("4 - Recete Yaz\n");
        printf("5 - Hasta Sil\n");
        printf("6 - Toplam Hasta Sayisi\n");
        printf("7 - Cikis\n");
        printf("Seciminiz: ");
        if (scanf("%d", &secim) != 1) {
            printf("Gecersiz giris! Lutfen bir sayi giriniz.\n");
            while (getchar() != '\n'); // Gecersiz girisi temizleme
            continue;
        }
        getchar(); // Yeni satir karakterini temizleme
        
        switch (secim) {
            case 1:
                printf("Hasta Adi: ");
                fgets(ad, 50, stdin);
                ad[strcspn(ad, "\n")] = 0;
                printf("Hasta Yasi: ");
                scanf("%d", &yas);
                printf("Aciliyet (1-Dusuk, 2-Orta, 3-Yuksek): ");
                scanf("%d", &aciliyet);
                hastaEkle(ad, yas, aciliyet);
                break;
            case 2:
                hastaListele();
                break;
            case 3:
                hastaIslem();
                break;
            case 4:
                receteYaz();
                break;
            case 5:
                printf("Silinecek hasta adini giriniz: ");
                fgets(ad, 50, stdin);
                ad[strcspn(ad, "\n")] = 0;
                hastaSil(ad);
                break;
            case 6:
                printf("Toplam hasta sayisi: %d\n", toplamHastaSayisi());
                break;
            case 7:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}