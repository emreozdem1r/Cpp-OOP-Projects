#include "sAdder.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <math.h>
using namespace std;

sAdder::sAdder()
{
	getName();
}
string sAdder::convert(int i){ // gelen int degerini stringe ceviren fonksiyon
    ostringstream strng;
    strng<<i;
    return strng.str();
}
void sAdder::setName(string Name) {
	this->name = Name;
}
string sAdder::getName()const {
	return name;
}

void sAdder::print()const {
	cout << "            " << endl;
	cout << getName()<<"'in girisleri:" <<in[0]<<" "<< in[1]<< " " << in[2]<< " " << in[3]<< " " <<
		in[4] << " " << in[5]<< " " << in[6]<< " " << in[7]<< " " << carry_in << " " <<endl;
	cout <<getName()<< "'in cikislari: "<< carry_out <<" "<< out4 << " " << out3 << " " << out2<< " " << out1 << " " << endl;

}

int sAdder::sum(int bit1, int bit2, int *dizi)
{
// binary olarak toplama fonksiyonu
// dizi carry ve toplami tutmaktadir. Dizinin ilk elemani carry 2. elemani ise toplami tutmaktadir.
	int carry, top = 0;
	carry = dizi[0];
	top = bit1 + bit2 + carry;
	if (top > 1)
	{
		carry = 1;
		dizi[1] = top % 2;
	}
	else
	{
		dizi[1] = top;
		carry = 0;
	}
	dizi[0] = carry;
	return *dizi;
}


void sAdder::binarySum(int *out) { // giris bitlerinin binary olarak toplanmasi ve out'lara setlenmesi
	int giris[8], c_in, toplamdizi[2] = { 0 };
	for(int i=0;i<8;i++){
        giris[i]=atoi(in[i].c_str());
	}

	sum(giris[3], giris[7], toplamdizi);
	out1 = toplamdizi[1];
	sum(giris[2], giris[6], toplamdizi);
	out2 = toplamdizi[1];
	sum(giris[1], giris[5], toplamdizi);
	out3 = toplamdizi[1];
	sum(giris[0], giris[4], toplamdizi);
	out4 = toplamdizi[1];
	carry_out = toplamdizi[0];
    c_in = atoi(carry_in.c_str());
	out[0] = carry_out;
	out[1] = out4;
	out[2] = out3;
	out[3] = out2;
	out[4]  = out1;

}


void sAdder::connections(string *dizi,int *out) {// circuit.txt'den okunan and girislerinin okunması
	int i = 0;  // and kapisinin hangi cikislardan geldiginin bulunmasi
	string and1bag, a1b1, a1b2, and1bag2, and2bag, and2bag2, a2b1, a2b2;
	string or1bag, or1bag2, o1_b1, o1_b2, or2bag, or2bag2, o2_b1, o2_b2;
	while (*dizi != " ") {

		if (*(dizi + i) == "AND1") {
			a1b1 = *(dizi + i + 1);
			and1bag = a1b1.substr(a1b1.length() - 1, 1);
			a1b2 = *(dizi + i + 2);
			and1bag2 = a1b2.substr(a1b2.length() - 1, 1);
		}
		else if (*(dizi + i) == "AND2") {
			a2b1 = *(dizi + i + 1);
			and2bag = a2b1.substr(a2b1.length() - 1, 1);
			a2b2 = *(dizi + i + 2);
			and2bag2 = a2b2.substr(a2b2.length() - 1, 1);
		}
		i++;
		if (i == 100) break;
	}
	*(out + 5) = atoi(and1bag.c_str()); //and1 girisleri
	*(out+ 6) = atoi(and1bag2.c_str());

	*(out+ 7) = atoi(and2bag.c_str()); // and2 girisleri
	*(out+ 8) = atoi(and2bag2.c_str());
}
void sAdder::setinputs(string *Dizi, int *out_araciDizi) {
	int i = 0;
			string bitler;
				while (*Dizi != " ") { // circuit.txt'den okunan değerleri in dizisine atılır.
				if (*(Dizi + i) == "1" || *(Dizi + i) == "0") {
					while (*(Dizi + i) != "\n") {
						bitler += *(Dizi + i);
						i++;
					}
					break;
				}
                if (*(Dizi + i) == " ") {
					break;
				}
				i++;
			}
			for(int i=0;i<8;i++){
                in[i]=bitler[i];
                }
			carry_in = bitler[8];

			binarySum(out_araciDizi);
			connections(Dizi, out_araciDizi);
}
void sAdder::assignment(int or2,int *adderDizi) {
	int dizim[8];   //adder2 nin girislerinin atamasi
	in[0] = "0";
	in[1] = convert(or2);
	in[2]= convert(or2) ;
	in[3]= "0";
	in[4]= convert(*(adderDizi + 1));
	in[5]= convert(*(adderDizi + 2));
	in[6]= convert(*(adderDizi + 3));
	in[7]= convert(*(adderDizi + 4));
    for(int i=0;i<8;i++)
        dizim[i]=atoi(in[i].c_str());

	bcdSum(dizim);
}

void sAdder::bcdSum(int *dizi) { // Or2 ve adder1 den gelen girişler ile bcd sum yapan fonksiyon
	int genelDizi[5],temp[5];   // eğer bu sayıların toplamı 9 dan büyük ise 6 ile toplayarak bcd sum fonksiyonu gerçekleşiyor
		int sum_dizi[2] = { 0 }; // eğer 9'dan küçük olması halinde toplam çıkışa aynen aktarılıyor
        //toplam dizisi 2 elemanlı bir dizi
        // 0. elemanı carry 1.elamnı ise iki bitin toplamını vermektedir
		sum(*(dizi + 3), *(dizi + 7),sum_dizi);
		*(genelDizi + 4) = sum_dizi[1];
		sum(*(dizi + 2), *(dizi + 6),sum_dizi);
		*(genelDizi + 3) = sum_dizi[1];
		sum(*(dizi + 1), *(dizi + 5),sum_dizi);
		*(genelDizi + 2) = sum_dizi[1];
		sum(*(dizi + 0), *(dizi + 4),sum_dizi);
		*(genelDizi + 1) = sum_dizi[1];
		*(genelDizi + 0) = sum_dizi[0];

		sum_dizi[0] = 0;// 0. elemanı carry 1.elemanı toplamı verir.
		sum_dizi[1] = 0;

        int carry=genelDizi[0];
		int top = genelDizi[0] * pow(2, 4) + genelDizi[1] * pow(2, 3) + genelDizi[2] * pow(2, 2)
			+ genelDizi[3] * pow(2, 1)+ genelDizi[4] * pow(2, 0);
            if (top>9) {    //toplamdaki sayi 9'dan buyukse 6 ile toplayip bcdsum toplamayi gercekliyor.

			sum(genelDizi[4], 0,sum_dizi);
			temp[0] = sum_dizi[1];

			sum(genelDizi[3], 1,sum_dizi);
			temp[1] = sum_dizi[1];

			sum(genelDizi[2], 1,sum_dizi);
			temp[2] = sum_dizi[1];

			sum(genelDizi[1], 0,sum_dizi);
			temp[3] = sum_dizi[1];
			sum(carry,0,sum_dizi);
			temp[4] = sum_dizi[1];
			carry_out = temp[4];
			out4 = temp[3];
			out3 = temp[2];
			out2 = temp[1];
			out1 = temp[0];

		}
		else {
			carry_out = genelDizi[0];   //adder2nin cikislarinin atamalari
			out4 = genelDizi[1];
			out3 = genelDizi[2];
			out2 = genelDizi[3];
			out1 = genelDizi[4];
		}

}

sAdder::~sAdder()
{
}
