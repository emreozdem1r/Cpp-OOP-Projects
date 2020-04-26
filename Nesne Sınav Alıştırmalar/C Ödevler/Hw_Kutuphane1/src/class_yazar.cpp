// Emre Özdemir 340824 Assignment:1
#include "class_yazar.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 
using namespace std;
class_yazar::class_yazar()
{
	head_y = NULL;
}


void class_yazar::yazar_ekle(string y_ad)
{	//Yazar ekleme fonksiyonu
	class_yazar *yeni_yazar = new class_yazar;
	yeni_yazar->yazar_adi = y_ad;
	yeni_yazar->next = 0;

	class_yazar *p = head_y;
	if (p == 0) head_y = yeni_yazar;
	else
	{
		class_yazar *first = head_y;
		while (first->next != 0)
		{
			first = first->next;
		}
		first->next = yeni_yazar;
	}
	file_print();
	head_y = NULL;
}
void class_yazar::yazar_ara(string y_ad) {
	// yazari dosyadan arama fonksiyonu
	string satir;
	int sayac = 0;
	ifstream oku("yazarlar.txt");
	while (getline(oku, satir)) {
		if (y_ad.compare(satir) == 0) {
			cout << "Aranan yazar bulundu : " << satir << endl;
			sayac++;
			break;
		}
	}
	if (sayac == 0)
		cout << "Aranan yazar veritabaninda bulunamadi." << endl;
}
void class_yazar::file_print()
{	//Okunan yazari dosyaya yazma fonksiyonu
	ofstream yaz;
	yaz.open("yazarlar.txt", ios::app);
	class_yazar *a = head_y;
	while (a != 0)
	{
		yaz << a->yazar_adi << endl;
		a = a->next;
	}
	yaz.close();
}
void class_yazar::yazar_fsil(string y_ad)
{	// Yazarlari bir baðlý listeye çektiðim fonksiyon
	class_yazar *yeni_yazar = new class_yazar;
	yeni_yazar->yazar_adi = y_ad;
	yeni_yazar->next = 0;

	class_yazar *p = head_y;
	if (p == 0) head_y = yeni_yazar;
	else
	{
		class_yazar *first = head_y;
		while (first->next != 0)
		{
			first = first->next;
		}
		first->next = yeni_yazar;
	}
}
void class_yazar::yazar_sil(string y_ad) {
	// Yazarlari sildiðim fonksiyon
	string satir; class_yazar *temp;
	fstream oku("yazarlar.txt");
	while (getline(oku, satir)) {
		yazar_fsil(satir);
	}
	oku.close();
	oku.open("yazarlar.txt", ios::out);
	oku << "";
	oku.close();
	oku.open("yazarlar.txt", ios::app);
	class_yazar *param = head_y;
	while (param->next != 0) {
		if (param->yazar_adi != y_ad) {
			oku << param->yazar_adi << endl;
		}
		temp = param->next;
		delete param;
		param = temp;
	}
}
void class_yazar::yazar_guncelle(string y_ad) {
	//Yazarlari güncellediðim fonksiyon
	string satir, y_yazarAdi;
	int sayac = 0;
	fstream oku("yazarlar.txt");

	while (getline(oku, satir)) {
		yazar_fsil(satir);
	}
	class_yazar *v = new class_yazar;
	v = head_y;
	while (v != NULL) {
		if (v->yazar_adi == y_ad) {
			cout << "Yeni yazar Adi: " << endl;
			getline(cin, y_yazarAdi);
		}
		v = v->next;
	}
	oku.close();
	oku.open("yazarlar.txt", ios::out);
	oku << "";
	oku.close();
	oku.open("yazarlar.txt", ios::app);
	class_yazar *param = head_y;
	while (param != NULL) {
		if (param->yazar_adi == y_ad) {
			param->yazar_adi = y_yazarAdi;
			cout << "basarili bir sekilde guncellendi.";
			sayac = 1;
		}
		oku << param->yazar_adi << endl;
		param = param->next;
	}
	if (sayac == 0) {
		cout << "Baba Yazar Yok :) " << endl;
	}
}
void class_yazar::yazar_listele() {
	//Yazarlari listelediðim fonksiyon
	string satir;
	ifstream oku("yazarlar.txt");
	while (getline(oku, satir)) {
		cout << satir << endl;
	}
}

class_yazar::~class_yazar()
{

}
