
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char sifrele(char harf, int ekle){
//    ASCII karakterlerini 0-127 arasında döngüsel olarak dolaşır
    if(ekle==0){
        return (char)(harf+127)%128;
    }
    return (char)(harf+ekle)%128;
}

int main()
{
    char cumle[100], cumle2[100], cumle3[100];
    printf("Sifrelenecek metni giriniz: \n");
    fgets(cumle,100,stdin);

    strcpy(cumle2,cumle);

    int sayi=0;
    int toplamsayi=0;
    int kelimesayisi=0;
    char *kelime=strtok(cumle," ");

    while(kelime!=NULL){
        kelimesayisi++;
        sscanf(kelime,"%d",&sayi);
        if(sayi!=0){
            toplamsayi+=sayi;
            sayi=0;
        }
        kelime=strtok(NULL," ");
//        metin kelimelere ayrılır ve her bir kelimenin içindeki sayısal değerler toplanır
    }

    char kelimeler[kelimesayisi][30];

    kelime=strtok(cumle2," ");

    for(int i=0;kelime!=NULL;i++){
        strcpy(kelimeler[i],kelime);
        kelime=strtok(NULL," ");
    }

    printf("\nSifrelenmis Metin: \n");

    char sifrelenmiscumle[100]="";
    for(int i=0;i<kelimesayisi;i++){
        for(int j=0;j<strlen(kelimeler[i]);j++){
            if(isdigit(kelimeler[i][j])){
                printf("%c",kelimeler[i][j]);
//                 sayı ise direk yazdır
            }
            else{
                printf("%c",sifrele(kelimeler[i][j],toplamsayi));
//                sayı değil ise şifrele
            }
        }
        printf(" ");
    }

    return 0;
}
