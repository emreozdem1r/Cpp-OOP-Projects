#include "andGate.h"
#include <iostream>
#include <string>
using namespace std;




andGate::andGate(int i1,int i2)
{
	in1 = i1;
    in2 = i2;
}
void andGate::setName(string name) {
	gatename = name;
}
string andGate::getname() const {
	return gatename;
}

int andGate::calculate() const{ // and kapisinin girislerinin hesaplanmasi
	int sonuc = 0;
	if (in1 == 0 || in2 == 0) {
		sonuc = 0;
	}
	else sonuc = 1;
	return sonuc;
}
void andGate::print() const {
	cout << "            " << endl;
	cout << getname() <<"'in girisleri : "<< in1<<" - " <<in2<<  endl;
	cout << getname() <<"'in cikisi : "<<calculate()<<  endl;

}
andGate::~andGate()
{
}
