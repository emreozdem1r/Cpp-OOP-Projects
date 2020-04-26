#pragma once
#include <iostream>
#include <string>
#include "logicClass.h"
using namespace std;


class andGate:public logicClass
{
public:
	andGate(int i1,int i2);
	void print() const;
	void setName(string Name);
	string getname() const;
	int calculate()const;
	~andGate();
private:
	int in1, in2;
	string gatename;

};

