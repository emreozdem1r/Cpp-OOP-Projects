/*
Logic Simulator
*/
#include "adderClass.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib> //atoi için
#include <sstream> // string convert
#include <math.h>
using namespace std;
//Prototipler
void adder_cikis_baglantilari(string *dizi,int *outDizi);

adderClass::adderClass()
{
    getName();
}
string convertToString(int a);
void adderClass::setName(string Name)
{
    this->name = Name;
}
string adderClass::getName()const
{
    return name;
}

void adderClass::print()const
{
    cout << "*************************** " << endl;
    cout << getName()<<".in girisleri:" <<in1<<" "<< in2 << " " << in3 << " " << in4 << " " <<
         in5 << " " << in6 << " " << in7 << " " << in8 << " " << carry_in << " " <<endl;
    cout <<getName()<< "in cikislari: "<< carry_out <<" "<< out4 << " " << out3 << " " << out2<< " " << out1 << " " << endl;
    yaz();
}

void adderClass::yaz()const{
    ofstream dosya(getName()+".txt");
    dosya << "Girişleri: "<< in1 << "-"<< in2<<"-"<< in3<<"-"<< in4<<"-"<< in5<<"-"<< in6<<"-"<< in7<<"-"<< in8<<"-"<< carry_in<<endl;
    dosya << "Çıkış: "<< carry_out<<"-"<< out4<<"-"<< out3<<"-"<< out2<<"-"<< out1<<endl;
    dosya.close();
}

int adderClass::topla(int a1, int a2, int *sonuc)
{
    /*Buradaki fonksiyon ile binary toplama yapılıyor. a1 ilk bit, a2 ikinci bir ve sonuc dizisi
    içerisinde de ilk bit elde ikinci bit ise carryout olarak düşünülüp tasarlanmıştır.*/
    int carry, top = 0;
    carry = *(sonuc + 0);
    top = a1 + a2 + carry;
    if (top > 1)
    {
        carry = 1;
        *(sonuc + 1) = top % 2;
    }
    else
    {
        *(sonuc + 1) = top;
        carry = 0;
    }
    *(sonuc + 0) = carry;
    return *sonuc;
}
void adderClass::setinputs(string *Dizi, int *out_araciDizi)
{
    /*
    Buradaki out_araciDizi herhangi bir yerde kullanılmadı amacı ise diğer fonksiyonlara aracılık ediyor ve
    içerisinde çıkış değerleri ve logic bağlantı noktaları gibi bilgileri tutacak. Getir-Götür elemanı gibi
    düşünülebilir.
    Bu dizi mainden gelerek tekrar mainde kullanılmaktadir.
    */
    int i = 0;
    string bitler;
    //Buraya pointer üzerinden adresi geliyor ve adres üzerinden gezinme yapabiliyorum.
    while (*Dizi != " ")
    {
        //	kelime = *(Dizi + i);
        if (*(Dizi + i) == "1" || *(Dizi + i) == "0")
        {
            while (*(Dizi + i) != "\n")
            {
                bitler += *(Dizi + i);
                i++;
            }
            break;
        }
        if (*(Dizi + i) == " ")   break;
        i++;
    }
    /*
    bitler dizide string olarak tutuluyor ve bu bitleri adderın girişlerine eşitliyorum.
    */
    in1 = bitler[0];
    in2 = bitler[1];
    in3 = bitler[2];
    in4 = bitler[3];
    in5 = bitler[4];
    in6 = bitler[5];
    in7 = bitler[6];
    in8 = bitler[7];
    carry_in = bitler[8];

    binarySum(out_araciDizi); //Aracı dizimizi asıl görev yerine gönderiyorum.Bunu yapmamdaki amaç main üzerinden az kod yazmak.
    adder_cikis_baglantilari(Dizi, out_araciDizi);
}

void adderClass::binarySum(int *outDizi)
{
    /*g ile başlayan değişkenler girişlerin integer'a çevrilmiş hali ve
    toplamdizi'de topla fonksiyonundan gelen carry ve sonuc bilgisini tutmaktadir.*/
    int g1, g2, g3, g4, g5, g6, g7, g8, c_in, toplamdizi[2] = { 0 };
    g1 = atoi(in1.c_str());
    g2 = atoi(in2.c_str());
    g3 = atoi(in3.c_str());
    g4 = atoi(in4.c_str());
    g5 = atoi(in5.c_str());
    g6 = atoi(in6.c_str());
    g7 = atoi(in7.c_str());
    g8 = atoi(in8.c_str());
    c_in = atoi(carry_in.c_str());
    topla(g4, g8, toplamdizi); //Hatirlatma: dizinin ilk elemanı carry diğeri ise binary toplama(1/0 şeklinde)  sonucu
    out4 = toplamdizi[1];
    topla(g3, g7, toplamdizi);
    out3 = toplamdizi[1];
    topla(g2, g6, toplamdizi);
    out2 = toplamdizi[1];
    topla(g1, g5, toplamdizi);
    out1 = toplamdizi[1];
    carry_out = toplamdizi[0];
    *(outDizi + 4) = out1;
    *(outDizi + 3) = out2;
    *(outDizi + 2) = out3;
    *(outDizi + 1) = out4;
    *(outDizi + 0) = carry_out;
}


void adder_cikis_baglantilari(string *dizi,int *outDizi)
{
    int i = 0, gelenOutDizisi[4];
    /*And kapılarının adderın hangi bacağına bağlı olduklarını buldurdum.*/
    /*
    Değişken isimleri icin açıklama:
    a1b1:Bu değişkende and1baglanti1 şeklinde kodlaması yapıldı fakat kısaltmak için böyle yazıldı
        Burada Adder1-1 şeklinde gelen string değer tutuluyor.
    and1bag1: icinde ise Adder1-1 deki 1 değeri yani bağlantı noktası yer almaktadir.
    **Diğerleride aynı mantıkla düşünülmüştür.
    */
    string and1bag, a1b1, a1b2, and1bag2, and2bag, and2bag2, a2b1, a2b2;
    while (*dizi != " ")
    {

        if (*(dizi + i) == "AND1")
        {
            a1b1 = *(dizi + i + 1);
            and1bag = a1b1.substr(a1b1.length() - 1, 1);
            a1b2 = *(dizi + i + 2);
            and1bag2 = a1b2.substr(a1b2.length() - 1, 1);
        }
        else if (*(dizi + i) == "AND2")
        {
            a2b1 = *(dizi + i + 1);
            and2bag = a2b1.substr(a2b1.length() - 1, 1);
            a2b2 = *(dizi + i + 2);
            and2bag2 = a2b2.substr(a2b2.length() - 1, 1);
        }
        i++;
        if (i == 100) break;
    }


    *(outDizi + 5) = atoi(and1bag.c_str());
    *(outDizi + 6) = atoi(and1bag2.c_str());

    *(outDizi + 7) = atoi(and2bag.c_str());
    *(outDizi + 8) = atoi(and2bag2.c_str());
}

void adderClass::adder2Set(int or2,int *adderDizi)
{
    /*Adder2'nin girişleri atanıyor.*/
    int a[8];
    in1 = "0";
    in2 = convertToString(or2);
    in3 = convertToString(or2) ;
    in4 = "0";
    in5 = convertToString(*(adderDizi + 3));
    in6 = convertToString(*(adderDizi + 2));
    in7 = convertToString(*(adderDizi + 1));
    in8 = convertToString(*(adderDizi + 0));

    /*atanan girişler integer değişkenlere atanıyor*/
    i_in1 = atoi(in1.c_str());
    i_in2 = atoi(in2.c_str());
    i_in3 = atoi(in3.c_str());
    i_in4 = atoi(in4.c_str());
    i_in5 = atoi(in5.c_str());
    i_in6 = atoi(in6.c_str());
    i_in7 = atoi(in7.c_str());
    i_in8 = atoi(in8.c_str());
    bcdSum();
}
/*to_string fonksiyonu hata verdiğinden böyle bir fonksiyon yazıldı bu sayede convert ediliyor.*/
string convertToString(int a)
{
    std::ostringstream s;
    s<<a;
    return s.str();
}


void adderClass::bcdSum()
{
    int SonucDizisi[5],temp[5];
    int toplamdizi[2] = { 0 };

    topla(i_in4, i_in8,toplamdizi);
    *(SonucDizisi + 4) = toplamdizi[1];
    topla(i_in3, i_in7, toplamdizi);
    *(SonucDizisi + 3) = toplamdizi[1];
    topla(i_in2, i_in6, toplamdizi);
    *(SonucDizisi + 2) = toplamdizi[1];
    topla(i_in1, i_in5, toplamdizi);
    *(SonucDizisi + 1) = toplamdizi[1];
    *(SonucDizisi + 0) = toplamdizi[0];
    i_carry_in = SonucDizisi[0];

    /*binary bitler ondalık sayıya çevrilerek 9 dan büyük olup olmamasına bakılıyor.*/
    int a = SonucDizisi[0] * pow(2, 4) + SonucDizisi[1] * pow(2, 3) + SonucDizisi[2] * pow(2, 2)
            + SonucDizisi[3] * pow(2, 1)+ SonucDizisi[4] * pow(2, 0);
    if (a>9)
    {
        //Eğer ondalık karşılığı 9'dan büyük ise bcd'ye çevirmek için 6 ile toplanıyor.
        toplamdizi[0] = 0;
        toplamdizi[1] = 0;

        topla(SonucDizisi[4], 0,toplamdizi);
        temp[0] = toplamdizi[1];

        topla(SonucDizisi[3], 1,toplamdizi);
        temp[1] = toplamdizi[1];

        topla(SonucDizisi[2], 1,toplamdizi);
        temp[2] = toplamdizi[1];

        topla(SonucDizisi[1], 0,toplamdizi);
        temp[3] = toplamdizi[1];
        topla(i_carry_in, 0, toplamdizi);
        temp[4] = toplamdizi[1];
        /*hesaplanan out değerlerini ait oldukları değişkenlere atıyorum.*/
        carry_out = temp[4];
        out4 = temp[3];
        out3 = temp[2];
        out2 = temp[1];
        out1 = temp[0];

    }
    else
    {
        /*Eğer 9'dan küçüksede sonucu değiştirmeden atamalarını yapıyorum*/
        carry_out = SonucDizisi[0];
        out4 = SonucDizisi[1];
        out3 = SonucDizisi[2];
        out2 = SonucDizisi[3];
        out1 = SonucDizisi[4];
    }
}

adderClass::~adderClass()
{
}
