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
void logicClass::print() const {

 }


void logicClass::seperate(string words[100]) {
	//Dizi icerigi " " karakteri ile dolduruldu
	for (int i = 0; i < 100; i++) {
		words[i] = " ";
	}
	fstream oku("Circuit.txt");
	char satir[100]; // char yapýlmasýnýn nedeni strtok fonksiyonunun char ile çalýþmasýndan kaynaklýdýr.

					 //Okunan satirdaki kelimeleri string diziye aktarýyorum.
	char *p;
	int l = 0; // k ve l deðerleri dizide yazýlacak yerler icin tamýmlandý
	if(oku==NULL){
        cout<<"dosya yok"<<endl;
        ::getchar();
	}
    else{
	while (oku.getline(satir, 100)) {
		if (satir[0] == NULL) break;
		else {
			p = strtok(satir, " "); // " " karakterine göre ayýrma yapýyor.
			while (p != NULL) {
				words[l] = p; //dizi icerigine kelime atamasý
				p = strtok(NULL, " ");
				l++;
			}
		}
		words[l] = "\n";	l++;
	}
	//diziye aktarma iþlemi bitiþi
}}

logicClass::~logicClass()
{
}
