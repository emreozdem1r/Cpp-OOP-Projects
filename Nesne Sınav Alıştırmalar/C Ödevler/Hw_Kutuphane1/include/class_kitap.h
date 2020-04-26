// Emre Özdemir 340824 Assignment:1
#pragma once
#include<iostream>
using namespace std;

class class_kitap
{
	class_kitap* head;
	string kitap_adi;
	string tur;
	string basimYili;
	string yazar;
	string icerik;
	string durum;
	class_kitap *next;
public:

	class_kitap();
	void kitap_ekle(string yazar, string kitapAdi, string tur, string basimYili, string icerik);
	void kitap_sil(string yazar, string kitapAdi);
	void kitap_ara(string yazar, string kitapAdi);
	void file_print();
	void kitap_listele();
	void kitap_linkedlist();
	void kitap_guncelle(string y_ad, string kitapAdi);
	void addfront(string ad, string kitap, string tur, string basimyili, string durum, string icerik);
	void kitapKirala(string yazarAdi, string kitapAdi);
	void kitapVer(string yazarAdi, string kitapAdi);
	void tur_listele(string tur);
	void yazar_listele(string yazar);
	~class_kitap();
};

