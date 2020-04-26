#include "orGate.h"

orGate::orGate(int i1,int i2)
{
	this->in1 = i1;
	this->in2 = i2;
}
void orGate::setName(string name) {
	gateName = name;
}
string orGate::getname()const {
	return gateName;
}

int orGate::calculate()const { // or kapisinin hesaplanmasý
	int sonuc = 0;
	if (in1 == 1 || in2 == 1) {
		sonuc = 1;
	}
	else sonuc = 0;
	return sonuc;
}
void orGate::print() const {
	cout << "            " << endl;
	cout << getname() << " 'in girisleri : " << in1 << " - " << in2 << endl;
	cout << getname() << " 'in cikisi : " << calculate() << endl;
}
orGate::~orGate()
{
}
