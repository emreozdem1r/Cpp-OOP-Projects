#ifndef CABINET_H
#define CABINET_H
#include <iostream>
#include <string>
using namespace std;

class cabinet
{
    public:
        cabinet(double=2,double=1,double=1,string="white");

        double a_volume();//hacim hesabi
       virtual void print()=0;
        virtual ~cabinet();

        protected:
        enum CabinetC{white,blue,green,red,yellow,black};
        double width,height,depth;
        string colour;
};

#endif // CABINET_H
