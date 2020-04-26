#pragma once
#include "logicClass.h"
class sAdder :
	public logicClass
{
public:
	sAdder();
	void print()const;
	~sAdder();
	void setName(string Name);
	void setinputs(string *dizi,int *out_araciDizi);
	void assignment(int,int *);
	int sum(int , int , int *);
	string getName()const;
	void bcdSum(int *);

private:
    void binarySum(int *);
    void connections(string *dizi,int *out) ;
    string convert(int i);
	string name;
	string in[8], carry_in;
	int out1, out2, out3, out4, carry_out;
};

