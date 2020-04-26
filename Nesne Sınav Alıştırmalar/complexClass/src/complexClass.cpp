#include "complexClass.h"

complexClass::complexClass(double real_in,double imagine_in)
{
    real=real_in;
    imagine=imagine_in;
}
complexClass::complexClass(){}
complexClass complexClass::operator+(const complexClass &in) const
{
    complexClass temp;
    temp.real=this->real+in.real;
    temp.imagine=this->imagine+in.imagine;
    return temp;
}
complexClass complexClass::operator-(const complexClass&in)const

{
    complexClass temp;
    temp.real=this->real-in.real;
    temp.imagine=this->imagine-in.imagine;
    return temp;

}
complexClass complexClass::operator*(const complexClass& in)const
{
    complexClass temp;
    temp.real=this->real*in.real;
    temp.imagine=this->imagine*in.imagine;
    return temp;
}
complexClass complexClass::operator/(const complexClass &in)const
{
    complexClass temp;
    temp.real=this->real/in.real;
    temp.imagine=this->imagine/in.imagine;
    return temp;
}
bool complexClass::operator==(const complexClass&in)const
{
    if(this->real==in.real && this->imagine==in.imagine)
        return true;
    else
        return false;
}
bool complexClass::operator<(const complexClass& in)const
{
    if(this->real<in.real && this->imagine<in.imagine)
        return true;
    else
        return false;
}
bool complexClass::operator>(const complexClass&in)const
{
    if(this->real>in.real && this->imagine>in.imagine)
        return true;
    else
        return false;
}
complexClass::~complexClass()

{
    //dtor
}
