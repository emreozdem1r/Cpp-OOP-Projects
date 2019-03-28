/*
Logic Simulator
*/
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
    virtual  void print() const;
    void kelimelerineAyir(string SatirDizisi[100]);
private:
    string SatirDizisi[100];
};

#endif // LOGICCLASS_H
