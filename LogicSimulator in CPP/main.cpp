/*
Logic Simulator
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "logicClass.h"
#include "adderClass.h"
#include "andclass.h"
#include "orclass.h"

using namespace std;
/*Polimorfizm için tasarlanan fonksiyon gelen nesnenin
 türüne göre print iþleminin yönlendirmesini yapýyor. */
void yazdir(const logicClass& yaz )
{
    yaz.print();
}
int main()
{

    string SatirDizisi[100];
    int outDizisi[9]; //ilk 4 bit çýkýþlar, 5.adder ,6-9 andlerin baðlantý noktalarý þeklinde ortak bir dizi tasarýmý yapýldý
    int bagNoktasi1, bagNoktasi2,and1_out,and2out,or1_out,or2_out;

    logicClass lc;
    lc.kelimelerineAyir(SatirDizisi); /*Circuit.txt dosyasý buradaki adým ile iþleme giriyor.*/

    adderClass adder1;
    adder1.setinputs(SatirDizisi,outDizisi); /* adder nesnesine Circuit dosyasý ve boþ olan outDizisi gidecek */
    adder1.setName("Adder1"); /*set ve get ile buradan gönderilen isim nesneye atanýyor.*/
    yazdir(adder1); /*adder nesnesini yukarýdaki polimorfik fonksiyona gönderiyorum*/

    bagNoktasi1 = outDizisi[5]; /*baðlantý noktalarýný alýyorum*/
    bagNoktasi2 = outDizisi[6];
    andclass and1(outDizisi[bagNoktasi1 -1],outDizisi[bagNoktasi2 -1]); /* baðlantý noktasýndaki çýkýþ deðerini aldým. */
    and1_out=and1.process();
    and1.setName("And1");/*Adder için yapýlan açýklamalar bu ve sonraki nesneler içinde ortaktýr.*/
    yazdir(and1);

    bagNoktasi1 = outDizisi[7];
    bagNoktasi2 = outDizisi[8];
    andclass and2(outDizisi[bagNoktasi1 - 1], outDizisi[bagNoktasi2 - 1]);
    and2out=	and2.process();
    and2.setName("And2");
    yazdir(and2);

    orclass or1(and1_out,and2out);
    or1_out=	or1.process();
    or1.setName("Or1");
    yazdir(or1);

    orclass or2(or1_out, outDizisi[4]);
    or2_out = or2.process();
    or2.setName("Or2");
    yazdir(or2);

    adderClass adder2;
    adder2.setName("Adder2");
    adder2.adder2Set(or2_out,outDizisi);
    adder2.print();

    ::getchar();
    return 0;
}
