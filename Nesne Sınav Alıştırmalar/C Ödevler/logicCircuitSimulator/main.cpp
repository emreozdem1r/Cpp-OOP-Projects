#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "logicClass.h"
#include "sAdder.h"
#include "andGate.h"
#include "orGate.h"
using namespace std;
void poly_print(const logicClass& write ) ;
int main()
{
	string SatirDizisi[100];
	int outDizisi[9]; //Dizi içeriði ilk 4 bit çýkýþlar 5.adder 6-9 andlerin baðlantý noktalarý.
	int connect1, connect2,and1_out,and2out,or1_out,or2_out;

	logicClass text_file;
	text_file.seperate(SatirDizisi); //txt dosyasinin parse edilmesi

	sAdder adder1;
	adder1.setinputs(SatirDizisi,outDizisi); // adder1 gelen bitleri binary olarak toplama
	adder1.setName("Adder1");
	poly_print(adder1);

	connect1 = outDizisi[5];
	connect2 = outDizisi[6];

	andGate and1(outDizisi[connect1 -1],outDizisi[connect2 -1]); //and1 girisleri atama ve sonuc bulma
    and1_out=and1.calculate();
	and1.setName("And1");
	poly_print(and1);

	connect1 = outDizisi[7];// out dizisinden gelen 6. eleman ve sonrası baglantı bacaklaridir.
	connect2 = outDizisi[8];
	andGate and2(outDizisi[connect1- 1], outDizisi[connect2 - 1]);
	and2out=	and2.calculate();
	and2.setName("And2");
	poly_print(and2);


	orGate or1(and1_out,and2out);   //or1  girisleri atama ve sonuc bulma
	or1_out=	or1.calculate();
	or1.setName("Or1");
	poly_print(or1);


	orGate or2(or1_out, outDizisi[0]); //or2 kapisindan girisleri atama ve sonucu alma
	or2_out = or2.calculate();
	or2.setName("Or2");
	poly_print(or2);


	sAdder adder2;
	adder2.setName("Adder2");
	adder2.assignment(or2_out,outDizisi); // out dizisinden gelen ilk 4 bit adder1 in cikislaridir.
	adder2.print();
	//poly_print(adder2);
	::getchar();
	return 0;
}
void poly_print(const logicClass& write ) {
	write.print();
 }
