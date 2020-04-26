#include "lroom.h"
#include <iostream>
#include <string>
using namespace std;
lroom::lroom(double w, double h, colors r, int ns, bool inp):room(w,h,r),no_seats(ns)
{
    seat_areas= new double[ns];
    if(inp) seat_input();
}

lroom lroom::operator+(const lroom & other){

	lroom temp(width+other.width, height, wallc, no_seats+other.no_seats, false);
	for(int i=0; i<no_seats; i++)
		temp.seat_areas[i]=seat_areas[i];
	for(int i=no_seats; i<no_seats+other.no_seats; i++)
		temp.seat_areas[i]=other.seat_areas[i-no_seats];
	return temp;



}

void lroom::seat_input(){
	cout<<no_seats<<" adet oturagin kapladiklari alanlari teker teker giriniz:\n";
	for(int i=0; i<no_seats; i++)
		cin>>seat_areas[i];
}
double lroom::a_area(){
    double seats=0;
	for(int i=0; i<no_seats; i++)
		seats+=seat_areas[i];
	return width*height-seats;
}

void lroom::print(){
    cout<<"Oturma odasi yuzolcumu: "<<width*height;
	cout<<"\nDuvar rengi kodu: "<<wallc;
	cout<<"\nOturak sayisi: "<<no_seats;
	cout<<"\nKullanilabilir alan: "<<a_area()<<endl;

}


lroom::~lroom()
{
    //dtor
}
