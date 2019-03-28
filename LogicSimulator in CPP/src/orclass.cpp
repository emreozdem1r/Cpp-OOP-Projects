/*
Logic Simulator
*/
#include "orclass.h"
#include<fstream>

orclass::orclass(int i1,int i2)
{
    this->in1 = i1;
    this->in2 = i2;
}
void orclass::setName(string name)
{
    gateName = name;
}
string orclass::getname()const
{
    return gateName;
}
/*
Or kapýsýnýn davranýþýný fonksiyon ile geri dönüþ parametreli olarak yazdým.
*/
int orclass::process()const
{
    int sonuc = 0;
    if (in1 == 1 || in2 == 1)
    {
        sonuc = 1;
    }
    else sonuc = 0;
    return sonuc;
}

void orclass::print() const
{
    cout << "*************************** " << endl;
    cout << getname() << " 'in girisleri : " << in1 << " - " << in2 << endl;
    cout << getname() << " 'in cikisi : " << process() << endl;
yaz();
}
void orclass::yaz()const{
    ofstream dosya(getname()+".txt");
    dosya << "Girişleri: "<< in1 << "-"<< in2<<endl;
    dosya << "Çıkış: "<< process()<<endl;
    dosya.close();
}
orclass::~orclass()
{
}
