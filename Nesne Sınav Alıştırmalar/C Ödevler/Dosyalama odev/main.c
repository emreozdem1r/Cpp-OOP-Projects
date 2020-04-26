#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *dosya,*yaz;
    int i,sayac=0;
    char *c,dizi[100000];
    dosya=fopen("main.c","r"); // Okunacak dosyanin adresi
    yaz=fopen("yaz.txt","w");  // Yazilacak dosyanin adresi
    if(dosya!=NULL)
    {
        do
        {
            c=fgets(dizi,10000,dosya); // Satir satir okuma islemi yapma ve bunu bir diziye atama
            if(c!=NULL)                // Satir satir okuma isleminin sonuna gelene kadar
            {
                for(i=0; i<strlen(dizi); i++)   // Diziden verileri okuma
                {
                    int j=0;
                    if(dizi[i]=='/')            // Satir satir okuma isleminde aciklama satiri olan yeri bulma
                    {
                        sayac++;
                        if(sayac==2)            // 2 tane oldugu durumda buranin aciklama satiri oldugunu gosterme
                        {
                            sayac=0;
                            for(j=i+2; j<strlen(dizi); j++) // Aciklama satirini gordukten sonra aciklama satirini yazdirma
                            {
                                printf("%c",dizi[j]);
                                fprintf(yaz,"%c",dizi[j]);  // Bu aciklama satirlarini bir metin belgesine yazdirma
                            }
                        }
                    }

                }
            }
        }
        while(c!=NULL);
    }
    else
    {
        printf("dosya bulunamadi!");
    }
    fclose(dosya);
    fclose(yaz);
    return 0;
}
