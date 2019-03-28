// Emre Özdemir 340824 Assignment:1
#include <iostream>
#include "class_yazar.h"
#include "class_kitap.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main()
{
	class_yazar yazar;
	class_kitap kitap;
	string yazarAdi, kitapAdi, tur, icerik, y_yazarAdi;
	string basimYili;
	int AnaKategori, AltKategori;
	cout << "1-Yazar Ekle/Sil/Ara" << endl;
	cout << "2-Kitap Ekle/Sil/Ara" << endl;
	cout << "3-Yazar Guncelle" << endl;
	cout << "4-Kitap Guncelle" << endl;
	cout << "5-Kitaplari Listele" << endl;
	cout << "6-Tum Yazarlari Listele" << endl;
	cout << "7-Kitap Al/Ver" << endl;
	cin >> AnaKategori;
	switch (AnaKategori)
	{
	case 1:
		cout << "1-Yazar Ekle" << endl;
		cout << "2-Yazar Sil" << endl;
		cout << "3-Yazar Ara" << endl;
		cin >> AltKategori;
		if (AltKategori == 1) {
			cout << "Yazar Adi: " << endl;		//yazar ekle
			cin.ignore();
			getline(cin, yazarAdi);
			yazar.yazar_ekle(yazarAdi);
			//yazar.file_print();
			cout << "Yazar Eklendi. " << endl;
			system("cls");
			return main();
		}
		else if (AltKategori == 2) {		//yazar sil
			cout << "Yazar Adi: " << endl;
			cin.ignore();
			getline(cin, yazarAdi);
			yazar.yazar_sil(yazarAdi);
			cout << "yazar silindi" << endl;

		}
		else if (AltKategori == 3) {
			cout << "Yazar Adi: " << endl;		//yazar ara
			getline(cin, yazarAdi);
			yazar.yazar_ara(yazarAdi);
			return main();
		}
		else {
			cout << "Yanlis Secim Yapildi! " << endl;
			return main();
		}
		break;
	case 2:
		cout << "1-Kitap Ekle" << endl;
		cout << "2-Kitap Sil" << endl;
		cout << "3-Kitap Ara" << endl;
		cin >> AltKategori;
		if (AltKategori == 1) {		// kitap ekle
			cout << ("Yazar adi :");
			cin.ignore();
			getline(cin, yazarAdi);
			cout << "Kitap adi :";
			//	cin.ignore();
			getline(cin, kitapAdi);
			cout << "Turu: ";
			//	cin.ignore();
			getline(cin, tur);
			cout << "Basim yili : ";
			cin >> basimYili;
			cout << "icerik :";
			cin.ignore();
			getline(cin, icerik);
			kitap.kitap_ekle(yazarAdi, kitapAdi, tur, basimYili, icerik);
			return main();
		}
		else if (AltKategori == 2) {	// kitap sil
			cout << "Yazar adi:" << endl;
			cin.ignore();
			getline(cin, yazarAdi);
			cout << "Kitap adi:" << endl;
			getline(cin, kitapAdi);

			kitap.kitap_sil(yazarAdi, kitapAdi);

		}
		else if (AltKategori == 3) {
			cout << "Yazar adi:" << endl;		//kitap ara
			cin.ignore();
			getline(cin, yazarAdi);
			cout << "Kitap adi:" << endl;
			getline(cin, kitapAdi);
			kitap.kitap_ara(yazarAdi, kitapAdi);
			return main();
		}
		break;
	case 3:
		cout << "Yazar Adi: " << endl;				// yazar guncelleme
		cin.ignore();
		getline(cin, yazarAdi);
		yazar.yazar_guncelle(yazarAdi);
		::getchar();

		break;
	case 4:
		cout << "Yazar Adi: ";					//kitap guncelleme
		cin.ignore();
		getline(cin, yazarAdi);
		cout << "Kitap Adi: ";
		getline(cin, y_yazarAdi);
		kitap.kitap_guncelle(yazarAdi, y_yazarAdi);
		::getchar();

		break;
	case 5:
		cout << "1-Ture Gore" << endl;		// kitaplari listeleme
		cout << "2-Yazara Gore" << endl;
		cout << "3-Tumunu Listele" << endl;
		cin >> AltKategori;
		if (AltKategori == 1) {		//türe göre listeleme
			cout << "Aranan Tur: ";
			cin >> tur;
			kitap.tur_listele(tur);
			cout << "------------------" << endl;
			return main();
		}
		else if (AltKategori == 2) {	//yazara göre listeleme
			cout << "Aranan Yazar: ";
			cin >> yazarAdi;
			kitap.yazar_listele(yazarAdi);
			cout << "------------------" << endl;
			return main();
		}
		else if (AltKategori == 3) {	//tüm kitaplari listeleme
			kitap.kitap_listele();
			cout << "------------------" << endl;
			return main();
		}
		else return main();

		::getchar();
		//Tum kitaplarý listele
		break;
	case 6:
		yazar.yazar_listele();	//yazarlari listele
		::getchar();
		cout << "------------------" << endl;
		return main();
		
		//yazar listele;
		break;
	case 7:
		cout << "1-Kitap Al" << endl;
		cout << "2-Kitap Iade" << endl;
		cin >> AltKategori;
		if (AltKategori == 1) {
			cout << "Yazar Adi: ";				//Kitap alma
			cin.ignore();
			getline(cin, yazarAdi);
			cout << "Kitap Adi: ";
			getline(cin, y_yazarAdi);
			kitap.kitapKirala(yazarAdi, y_yazarAdi);
		}
		else if (AltKategori == 2) {		//kitap iade
			cout << "Yazar Adi: ";
			cin.ignore();
			getline(cin, yazarAdi);
			cout << "Kitap Adi: ";
			getline(cin, y_yazarAdi);
			kitap.kitapVer(yazarAdi, y_yazarAdi);

			return main();
		}
		// Kitap Al/ver
		break;
	default:
		cout << "Yanlis secim" << endl;
		return main();
	}
	::getchar();
	return 0;
}

