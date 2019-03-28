/*
Logic Simulator
*/
#include "andclass.h"
#include <iostream>
#include <string>
using namespace std;

andclass::andclass(int i1,int i2)
{
    this->in1 = i1;
    this->in2 = i2;
}

void andclass::setName(string name)
{
    gatename = name;
}
string andclass::getname() const
{
    return gatename;
}

int andclass::process() const
{
    int sonuc = 0;
    if (in1 == 0 || in2 == 0)
    {
        sonuc = 0;
    }
    else sonuc = 1;
    return sonuc;
}
void andclass::print() const
{
    cout << "*************************** " << endl;
    cout << getname() <<"'in girisleri : "<< in1<<" - " <<in2<<  endl;
    cout << getname() <<"'in cikisi : "<<process()<<  endl;
    yaz();
}


void andclass::yaz()const{
    ofstream dosya(getname()+".txt");
    dosya << "Giriþleri: "<< in1 << "-"<< in2<<endl;
    dosya << "Çýkýþ: "<< process()<<endl;
    dosya.close();
}
andclass::~andclass()
{
}
