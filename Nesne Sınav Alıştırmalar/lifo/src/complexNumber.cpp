#include "complexNumber.h"
#include <stdlib.h>

complexNumber::complexNumber(double real_in, double imaginary_in)
{
    real = real_in;
    imaginary = imaginary_in;
    //ctor
}

complexNumber::complexNumber(const string& complexNum){
    string complexNumber = complexNum;
    real = atoi(&complexNumber[1]);
    imaginary = atoi(&complexNumber[3]);
}

complexNumber::complexNumber(const char * complexNum){
    string complexNumber = complexNum;
    real = atoi(&complexNumber[1]);
    size_t pos = complexNumber.find(',');
    imaginary = atoi(&complexNumber[pos + 1]);
}




#if 1// IMPLEMENT_AS_MEMBER
complexNumber complexNumber::operator+( const complexNumber&  o_in) const {
     complexNumber tempcomplexNumber;

     tempcomplexNumber.real = real + o_in.real;
     tempcomplexNumber.imaginary = imaginary + o_in.imaginary;

     return tempcomplexNumber;
}

bool complexNumber::operator>=(const complexNumber& o_in) const {

   double r1, r2;

   r1 = this->real * this->real + this->imaginary * this->imaginary;
   r2 = o_in.real * o_in.real + o_in.imaginary * o_in.imaginary;

   return (r1 >= r2);
}
bool complexNumber::operator==(const complexNumber& o_in) const {

    return (this->real == o_in.real) && (this->imaginary == o_in.imaginary);
}

complexNumber complexNumber::operator++(){

   ++real;
   ++imaginary;
   return *this;
}

complexNumber complexNumber::operator++(int dummy){
   complexNumber tempObject = *this;

   real++;
   imaginary++;

   return tempObject;

}
#endif


complexNumber::~complexNumber()
{
    //dtor
}
