// Emre Özdemir 340824 Assignment:1
#pragma once
#ifndef CLASS_YAZAR_H
#define CLASS_YAZAR_H
#include<iostream>
using namespace std;


class class_yazar
{


	string yazar_adi;
	class_yazar *next;

	class_yazar *head_y;
public:
	class_yazar();
	void yazar_fsil(string y_ad);
	void yazar_ekle(string y_ad);
	void yazar_sil(string y_ad);
	void yazar_ara(string y_ad);
	void file_print();
	void yazar_guncelle(string y_ad);
	void yazar_listele();
	virtual ~class_yazar();

protected:


private:
};

#endif // CLASS_YAZAR_H
