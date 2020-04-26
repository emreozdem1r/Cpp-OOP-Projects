#pragma once
#include <iostream>
#include <string>
#include "logicClass.h"
using namespace std;


class orGate:public logicClass
{
public:
	orGate(int i1,int i2);
	int calculate() const;
	void print() const;
	void setName(string Name);
	string getname()const;
	~orGate();
private:
	string gateName;
	int in1, in2;

};

