/*
Logic Simulator
*/
#ifndef ANDCLASS_H
#define ANDCLASS_H

#include <iostream>
#include <string>
#include "logicClass.h"
using namespace std;


class andclass:public logicClass
{
public:
    andclass(int i1,int i2);
    void print() const;
    void setName(string Name);
    string getname() const;
    int process()const;
    ~andclass();
private:
    void yaz()const;
    int in1, in2;
    string gatename;

};


#endif // ANDCLASS_H
