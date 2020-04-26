#include <stdio.h>
#include <stdlib.h>
void satranc(int dizi[8][8],int rast_1,int rast_2);
void yazdir(int yaz[8][8]);

int main()
{
    int dizi_2[8][8];
    int satir,sutun,i,j;
    printf("Satranc oyununda atin konumunun verilip ve bu konumdan hangi konumlara \n\nhareket edecegini gosteren bir algoritmadir.\n\nLutfen oynayacaginiz atin konumunu giriniz.\n\n");
    printf("Algoritma atin konumunu 1 olarak isaretleyip gidecegi yerlere 2 yazacaktir. \n\n");
    printf("satir giriniz: ");
    scanf("%d",&satir);
    satir-=1;
    printf("sutun giriniz: ");
    scanf("%d",&sutun);                 // Kullaicidan atin konumunu aliyoruz.
    sutun-=1;
    if(satir>8 || sutun>8)          // Atın konumunun satranç tahtasının aşmamasının kontrolünü yapıyoruz.
    {
        printf("satir ve sutun sayisi 8 den buyuk olamaz !");
    }
    else
    {
        satranc(dizi_2,satir,sutun);
        yazdir(dizi_2);
    }
}
void yazdir(int yaz[8][8])
{
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("%d  ",yaz[i][j]);    // Satranç tahtasının ve atın hangi yönlere gideceğinin yazdırılması
        }
        printf("\n");
    }
}
void satranc(int dizi[8][8],int rast_1,int rast_2)
{

    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(i==rast_1 && j== rast_2)     //Verilen satir ve sutun deðerlerine göre atin konumunun tahtaya yerleştirilmesi
            {
                dizi[i][j]=1;               // Atin konumuna 1 yaziliyor.
            }
            else if((j==rast_2+2 && i==rast_1+1) || (j==rast_2+2 && i==rast_1-1))// Bütün bu koşullar atin gideceği yerleri ve ihtimalleri tutuyor.
            {
                dizi[i][j]=2;
            }
            else if((j==rast_2-2 && i==rast_1+1)|| (j==rast_2-2 && i==rast_1-1))// Atin gideceği konumlara 2 yaziliyor.
            {
                dizi[i][j]=2;
            }
            else if((j==rast_2-1 && i==rast_1-2)|| (j==rast_2+1 && i==rast_1-2))
            {
                dizi[i][j]=2;
            }
            else if((j==rast_2-1 && i==rast_1+2)|| (j==rast_2+1 && i==rast_1+2)) // Bütün bu koşullar atin gideceði yerleri ve ihtimalleri tutuyor.
            {
                dizi[i][j]=2;
            }
            else
            {
                dizi[i][j]=0;         // Atin gitmeyecegi yerlere "0" yazdiriyoruz.

            }
        }

    }
}
