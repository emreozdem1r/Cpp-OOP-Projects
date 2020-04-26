// Emre Özdemir 340824 Assignment:1
#include "class_kitap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

class_kitap::class_kitap()
{
	head = NULL;
}

void class_kitap::kitap_ekle(string yazar, string kitapAdi, string tur, string basimYili, string icerik) {
	// Kitaplarý Eklemek için kullandýðým fonksiyon
	class_kitap *yeni_kitap = new class_kitap;
	yeni_kitap->yazar = yazar;
	yeni_kitap->kitap_adi = kitapAdi;
	yeni_kitap->tur = tur;
	yeni_kitap->basimYili = basimYili;
	yeni_kitap->durum = "Rafta";
	yeni_kitap->icerik = icerik;
	yeni_kitap->next = NULL;

	class_kitap *p = head;
	if (p == 0) head = yeni_kitap;
	else
	{
		class_kitap *first = head;
		while (first->next != 0)
		{
			first = first->next;
		}
		first->next = yeni_kitap;
	}
	file_print();
	head = NULL;
}
void class_kitap::file_print() {
	// Bilgileri dosyaya yazdýrdýðým fonksiyon
	ofstream yaz;
	yaz.open("kitaplar.txt", ios::app);
	class_kitap *a = head;
	while (a != 0)
	{
		yaz << a->yazar << endl;
		yaz << a->kitap_adi << endl;
		yaz << a->tur << endl
			<< a->basimYili << endl
			<< a->durum << endl
			<< a->icerik << endl
			<< endl;
		a = a->next;
	}
	yaz.close();
}
void class_kitap::kitap_ara(string yazar, string kitapAdi) {
	//Kitap arama fonksiyonu
	string satir;
	class_kitap *v = new class_kitap;
	int sayac = 0, t_say = 0;
	ifstream oku("kitaplar.txt");
	kitap_linkedlist();
	v = head;
	while (v != NULL) {
		if (yazar.compare(v->yazar) == 0 && kitapAdi.compare(v->kitap_adi) == 0) {
			cout << "Aranan kitap veritabaninda bulundu." << endl;
			sayac = 1;
			break;
		}
		v = v->next;
	}
	if (sayac == 0)
		cout << "Aranan kitap veritabaninda bulunamadi." << endl;
}
void class_kitap::kitap_listele() {
	// Bütün kitaplarý listelediðim fonksiyon
	string satir;
	ifstream oku("kitaplar.txt");
	while (getline(oku, satir)) {
		cout << satir << endl;
	}
}
void class_kitap::tur_listele(string tur) {
	//Kitaplarý türlerine göre listelediðim fonksiyon
	kitap_linkedlist();
	class_kitap *v = new class_kitap;
	v = head;
	while (v != NULL) {
		if (tur.compare(v->tur) == 0) {
			cout << "Aranan turde " << v->yazar << "'in " << v->kitap_adi << " adli kitabi bulunmaktadir." << endl;
		}
		v = v->next;
	}

}
void class_kitap::yazar_listele(string yazar) {
	//Kitaplari yazarlarina göre listelediðim fonksiyon
	kitap_linkedlist();
	class_kitap *v = new class_kitap;
	v = head;
	while (v != NULL) {
		if (yazar.compare(v->yazar) == 0) {
			cout << "Aranan yazarin " << v->kitap_adi << " adli kitabi bulunmaktadir." << endl;
		}
		v = v->next;
	}
}

void class_kitap::kitap_linkedlist() {
	//Kitaplari dosyadan okuyup bir linkedliste çektiðim fonksiyon bu fonksiyon içinden farklý bir 
	//fonksiyon çaðýrarak listeleme iþini yaptým. Bu fonksiyon while döngüsünde bulunmaktadýr..
	class_kitap* yeni_kitap = new class_kitap;
	string satir;
	int while_sayaci = 0;
	fstream oku;
	oku.open("kitaplar.txt");
	string c_yazarAdi, c_kitapAdi, c_tur, c_icerik;
	string i_basimYili, durum;

	while (getline(oku, satir)) {
		if (satir.empty()) {
			while_sayaci = 0;
			//class_kitap* yeni_kitap = new class_kitap;
			continue;
		}
		else if (while_sayaci == 0) yeni_kitap->yazar = satir;
		else if (while_sayaci == 1) yeni_kitap->kitap_adi = satir;
		else if (while_sayaci == 2) yeni_kitap->tur = satir;
		else if (while_sayaci == 3) yeni_kitap->basimYili = satir;
		else if (while_sayaci == 4) yeni_kitap->durum = satir;
		else if (while_sayaci == 5) {
			yeni_kitap->icerik = satir;
			addfront(yeni_kitap->yazar, yeni_kitap->kitap_adi, yeni_kitap->tur, yeni_kitap->basimYili, yeni_kitap->durum, yeni_kitap->icerik);
		}
		while_sayaci++;
	}
}
void class_kitap::addfront(string ad, string kitap, string tur, string basimyili, string durum, string icerik) {
	// bir üstteki linklist fonksiyonunun while kýsmýnda okuduðum deðerleri listeye aldýðým bölüm
	class_kitap* v = new class_kitap;
	v->yazar = ad;
	v->kitap_adi = kitap;
	v->tur = tur;
	v->basimYili = basimyili;
	v->durum = durum;
	v->icerik = icerik;
	v->next = head;
	head = v;
}

void class_kitap::kitap_guncelle(string y_ad, string kitapAdi) {
	//kitaplari güncellediðim fonksiyon
	string satir;
	fstream oku;
	kitap_linkedlist();
	oku.open("kitaplar.txt", ios::out);
	oku << "";
	oku.close();
	oku.open("kitaplar.txt", ios::app);

	class_kitap *param = head;
	while (param != 0) {
		if (param->yazar == y_ad && param->kitap_adi == kitapAdi) {
			cout << "Yazar Adi:";
			getline(cin, param->yazar);
			cout << "Kitap Adi:";
			getline(cin, param->kitap_adi);
			cout << "Tur:";
			getline(cin, param->tur);
			cout << "Basim Yili:";
			cin >> param->basimYili;
			cout << "Durum:";
			cin >> param->durum;
			cout << "Ýcerik:";
			cin.ignore();
			getline(cin, param->icerik);
			cout << "basarili bir sekilde guncellendi.";
		}
		for (int i = 1; i <= 6; i++) {
			if (i == 1) {
				oku << param->yazar << endl;
			}
			else if (i == 2) {
				oku << param->kitap_adi << endl;
			}
			else if (i == 3) {
				oku << param->tur << endl;
			}
			else if (i == 4) {
				oku << param->basimYili << endl;
			}
			else if (i == 5) {
				oku << param->durum << endl;
			}
			else if (i == 6) {
				oku << param->icerik << endl << endl;
			}
		}
		param = param->next;
	}
}
void class_kitap::kitap_sil(string yazar, string kitapAdi) {
	//Kitap silme fonksiyonu
	int sayac = 0;
	kitap_linkedlist();
	class_kitap* v = new class_kitap;
	class_kitap* temp;
	fstream oku;
	oku.open("kitaplar.txt", ios::out);
	oku << "";
	oku.close();
	oku.open("kitaplar.txt", ios::app);
	v = head;
	while (v != NULL) {
		if (yazar.compare(v->yazar) != 0 && kitapAdi.compare(v->kitap_adi) != 0) {
			oku << v->yazar << endl;
			oku << v->kitap_adi << endl;
			oku << v->tur << endl;
			oku << v->basimYili << endl;
			oku << v->durum << endl;
			oku << v->icerik << endl;
			oku << endl;
		}
		else sayac = 1;
		v = v->next;
	}
	if (sayac == 1) cout << "Basariyla silindi!";
	else cout << "Kitap Bulunamadi.";
	oku.close();
}
void class_kitap::kitapKirala(string yazarAdi, string kitapAdi) {
	//Kitaplarý bu fonksiyonla kiraliyorum
	kitap_linkedlist();
	class_kitap *v = new class_kitap;
	int sayac = 0;
	v = head;
	while (v != NULL) {
		if (yazarAdi.compare(v->yazar) == 0 && kitapAdi.compare(v->kitap_adi) == 0) {
			if (v->durum == "Rafta") {
				v->durum = "Elde";
				cout << "Kitabinizi basariyla kiraladiniz.";
				sayac = 1;
			}
		}
		v = v->next;
	}
	if (sayac == 0) cout << "Aranan kitap bulunamadi...";
	else {
		fstream oku;
		oku.open("kitaplar.txt", ios::out);
		oku << "";
		oku.close();
		oku.open("kitaplar.txt", ios::app);
		v = head;
		while (v != NULL) {
			oku << v->yazar << endl;
			oku << v->kitap_adi << endl;
			oku << v->tur << endl;
			oku << v->basimYili << endl;
			oku << v->durum << endl;
			oku << v->icerik << endl;
			oku << endl;
			v = v->next;
		}	oku.close();
	}
}

void class_kitap::kitapVer(string yazarAdi, string kitapAdi) {
	// Kitap iade iþlemlerini bu fonksiyonla yaptým
	kitap_linkedlist();
	class_kitap *v = new class_kitap;
	int sayac = 0, gun, varsayilan = 30;
	double faiz;
	v = head;
	while (v != NULL) {
		if (yazarAdi.compare(v->yazar) == 0 && kitapAdi.compare(v->kitap_adi) == 0) {
			cout << "Kitap kac gundur kullanicida?";
			cin >> gun;
			if (gun > varsayilan) {
				fstream oku("ayar.config");
				oku >> faiz;
				oku.close();
				cout << "Odenecek tutar: " << faiz*(gun - varsayilan) << " TL'dir.";
			}
			if (v->durum == "Elde") {
				v->durum = "Rafta";
				cout << "Kitabinizi basariyla iade ettiniz." << endl;
				sayac = 1;
			}
		}
		v = v->next;
	}
	if (sayac == 0) cout << "Aranan kitap bulunamadi...";
	else {
		fstream oku;
		oku.open("kitaplar.txt", ios::out);
		oku << "";
		oku.close();
		oku.open("kitaplar.txt", ios::app);
		v = head;
		while (v != NULL) {
			oku << v->yazar << endl;
			oku << v->kitap_adi << endl;
			oku << v->tur << endl;
			oku << v->basimYili << endl;
			oku << v->durum << endl;
			oku << v->icerik << endl;
			oku << endl;
			v = v->next;
		}	oku.close();
	}
	::getchar();
}

class_kitap::~class_kitap()
{
}
