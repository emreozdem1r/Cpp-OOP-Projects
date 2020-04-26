#ifndef KITCHENC_H
#define KITCHENC_H
#include <iostream>
#include <string>
using namespace std;
#include "cabinet.h"
class kitchenC: protected cabinet
{
    public:

        kitchenC(double,double,double,string,int);
        kitchenC(const kitchenC&);
        double a_volume()const;
        void print();
        void kw_input();
        double operator +(const kitchenC&) const;
        virtual ~kitchenC();
    private:
        int no_kitchenware;
        double *kw_volumes;

};

#endif // KITCHENC_H
