/*
Logic Simulator
*/
#ifndef ORCLASS_H
#define ORCLASS_H
#include <iostream>
#include <string>
#include "logicClass.h"
using namespace std;


class orclass:public logicClass
{
public:
    orclass(int i1,int i2);
    void print() const;
    void setName(string Name);
    string getname()const;
    int process() const;
    ~orclass();

private:
    void yaz()const;
    string gateName;
    int in1, in2;

};


#endif // ORCLASS_H
