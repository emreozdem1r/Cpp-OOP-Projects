#include <iostream>
#include <string>
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#define IMPLEMENT_AS_MEMBER 1
using namespace std;
class complexNumber
{
    friend ostream & operator<<(ostream &, const complexNumber&);
    friend istream & operator>>(istream &, complexNumber&);

    public:
        complexNumber(double=0, double=0);
        complexNumber(const string&);
        complexNumber(const char*);
#if IMPLEMENT_AS_MEMBER
        complexNumber operator+( const complexNumber&  o_in) const;
        bool operator==(const complexNumber & o_in) const;
        bool operator>=(const complexNumber & o_in) const;
        complexNumber operator++();
        complexNumber operator++(int);
#else
        friend complexNumber operator+(const complexClass& o_in1, const complexClass& o_in2);
        friend bool operator<(const complexClass& o_in1, const complexClass & o_in2);
#endif
        virtual ~complexNumber();

    protected:

    private:
        double real;
        double imaginary;

};

#endif // COMPLEXCLASS_H
