#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void temizle_tampon() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void sezar_sifrele(char* metin, int kaydirma) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (isalpha(metin[i])) {
            char base = isupper(metin[i]) ? 'A' : 'a';
            metin[i] = base + (metin[i] - base + kaydirma) % 26;
        }
    }
}

void sezar_desifrele(char* metin, int kaydirma) {
    sezar_sifrele(metin, 26 - (kaydirma % 26));
}

int main() {
    char metin[100];
    int kaydirma;
    int secim;

    printf("Metin girin: "); 
    if (fgets(metin, sizeof(metin), stdin) == NULL) {
        printf("Metin okuma hatasi!\n");
        return 1;
    }
    metin[strcspn(metin, "\n")] = 0;

    printf("Kaydirma miktarini girin (1-25): ");
    if (scanf("%d", &kaydirma) != 1 || kaydirma < 1 || kaydirma > 25) {
        printf("Gecersiz kaydirma miktari! 1-25 arasinda bir sayi girin.\n");
        temizle_tampon();
        return 1;
    }
    temizle_tampon();

    printf("1. Sifrele\n2. Desifrele\nSeciminiz: ");
    if (scanf("%d", &secim) != 1 || (secim != 1 && secim != 2)) {
        printf("Gecersiz secim! 1 veya 2 girin.\n");
        temizle_tampon();
        return 1;
    }

    if (secim == 1) {
        sezar_sifrele(metin, kaydirma);
        printf("Sifrelenmis metin: %s\n", metin);
    }
    else {
        sezar_desifrele(metin, kaydirma);
        printf("Desifrelenmis metin: %s\n", metin);
    }

    return 0;
}
   