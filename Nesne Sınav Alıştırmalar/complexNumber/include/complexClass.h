#ifndef COMPLEXCLASS_H
#define COMPLEXCLASS_H
#include <iostream>
#define IMPLEMENT_AS_NUMBER 1
using namespace std;
class complexClass
{

    public:
        double real;
        double imaginary;
        friend ostream& operator << (ostream&,const complexClass&);
        friend istream& operator >>(istream&, complexClass&);
        complexClass(double real_in = 0,double imaginary_in = 0);

        #if IMPLEMENT_AS_NUMBER
        complexClass operator+(const complexClass&) const;
        complexClass operator-(const complexClass&) const;
        complexClass operator/(const complexClass&) const;
        complexClass operator*(const complexClass&) const;
        bool operator >       (const complexClass&) const;
        bool operator >=      (const complexClass&) const; //tamamlanacak
        bool operator ==      (const complexClass&) const;
        complexClass(const char*);
        complexArray(const string &complexArrayString);
        #else
        friend complexClass operator + (const complexClass&,const complexClass&);
        friend complexClass operator - (const complexClass&,const complexClass&);
        friend complexClass operator / (const complexClass&,const complexClass&);
        friend complexClass operator * (const complexClass&,const complexClass&);

        #endif // IMPLEMENT_AS_NUMBER
        virtual ~complexClass();

    protected:

    private:

};

#endif // COMPLEXCLASS_H
