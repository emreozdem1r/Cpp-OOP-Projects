#ifndef LOGICCLASS_H
#define LOGICCLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
class logicClass
{
public:
	logicClass();
	virtual ~logicClass();
	virtual void print() const;
	void seperate(string words[100]);
private:
	string words[100];
};

#endif
