/*
Logic Simulator
*/
#ifndef ADDERCLASS_H
#define ADDERCLASS_H
#include "logicClass.h"
class adderClass :
    public logicClass
{
public:
    adderClass();
    void print()const;
    ~adderClass();
    void setName(string Name);
    void setinputs(string *dizi,int *out_araciDizi);
    void adder2Set(int,int *);
    void binarySum(int *);
    int topla(int a1, int a2, int *sonuc);
    string getName()const;
    void bcdSum();

private:
    void yaz()const;
    string name;
    string in1, in2, in3, in4, in5, in6, in7,in8, carry_in;
    int i_in1, i_in2, i_in3, i_in4, i_in5, i_in6, i_in7, i_in8, i_carry_in;
    int out1, out2, out3, out4, carry_out;
};



#endif // ADDERCLASS_H
