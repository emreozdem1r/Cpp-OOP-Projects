/*
Logic Simulator
*/
#include "logicClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib> //atoi için
using namespace std;

logicClass::logicClass()
{
}
void logicClass::print() const
{
    //polimorfizm için gerekli olan boş fonksiyon.
    // silindiğinde çalışmadığını gördüğüm için ekledim.
}

void logicClass::kelimelerineAyir(string SatirDizisi[100])
{
    //Önce Dizi icerigi " " karakteri ile doldurdum ve while döngülerini de bu boşluk karakterine göre biçimlendirdim
    for (int i = 0; i < 100; i++)
    {
        SatirDizisi[i] = " ";
    }
    fstream oku("Circuit.txt");
    char satir[100]; // char yapilmasinin nedeni strtok fonksiyonunun char ile çalismasindan kaynaklidir.
    char *p;
    int m = 0; // m deðerleri dizide yazilacak yerler icin tanimlandi.
    while (oku.getline(satir, 100))
    {
        if (satir[0] == ' ') break;
        else
        {
            p = strtok(satir, " "); // boşluk karakterine göre ayirma yapiyor.
            while (p != NULL)
            {
                SatirDizisi[m] = p; //ve ayrılan kelimeler diziye atılıyor.
                p = strtok(NULL, " ");
                m++;
            }
        }
        SatirDizisi[m] = "\n";
        /* satırdaki tüm kelimeler ayrılıp diziye atıldıktan sonra
           sonuna \n karakteri ekleniyor ki satirin bittiği anlaşılsın.
        */
        m++;
    }
}

logicClass::~logicClass()
{
}
