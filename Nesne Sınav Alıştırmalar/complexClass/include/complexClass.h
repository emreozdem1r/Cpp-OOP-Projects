#ifndef COMPLEXCLASS_H
#define COMPLEXCLASS_H
#include <iostream>
#include <string>
using namespace std;
#define IMPLEMENT_AS_NUMBER 1

class complexClass
{
    public:
        complexClass();
        double real,imagine;
       friend ostream& operator<<(ostream&,const complexClass&);
       friend istream& operator>>(istream&, complexClass&);

        complexClass(double real_in,double imagine_in);
        virtual ~complexClass();
        #if IMPLEMENT_AS_NUMBER
        complexClass operator+(const complexClass&) const;
        complexClass operator-(const complexClass&) const;
        complexClass operator*(const complexClass&) const;
        complexClass operator/(const complexClass&) const;

        bool operator<(const complexClass&)const;
        bool operator>(const complexClass&)const;
        bool operator==(const complexClass&)const;
        complexClass(const char*);
        complexArray(const string &complexArrayString);

       #else
        friend complexClass operator+(const complexclass&, const complexClass&);
        friend complexClass operator-(const complexClass&,const complexClass&);
        friend complexClass operator *(const complexClass&,const complexClass&);
        friend complexClass operator/(const complexClass&,const complexClass&);

           #endif // IMPLEMENT_AS_NUMBER
    private:
};

#endif // COMPLEXCLASS_H
