#include "complexClass.h"

complexClass::complexClass(double real_in, double imagine_in)
{
    real=real_in;
    imagine=imagine_in;
}
#if CONTROL
complexClass complexClass::operator+(const complexClass& in) const {
        complexClass temp;
        temp.real=this->real+in.real;
        temp.imagine=this->imagine+in.imagine;
        return temp;
}
complexClass complexClass::operator-(const complexClass& in) const
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
complexClass complexClass::operator/(const complexClass& in)const
{
    complexClass temp;
    temp.real=this->real/in.real;
    temp.imagine=this->imagine/in.imagine;
    return temp;
}
bool complexClass::operator>(const complexClass& in) const
{
    if(this->real>in.real && this->imagine>in.imagine)
        return true;
    else
        return false;
}
bool complexClass::operator<(const complexClass& in) const{
    if(this->real<in.real && this->imagine<in.imagine)
        return true;
    else
        return false;
}
bool complexClass::operator==(const complexClass& in) const
{
    if(this->real==in.real && this->imagine==in.imagine)
        return true;
    else
        return false;
}
#else
complexClass operator+(const complexClass& in1, const complexClass& in2)
{
    complexClass temp;
    temp.real=in1.real+in2.real;
    temp.imagine=in1.imagine+in2.imagine;
    return temp;
}
complexClass operator -(const complexClass& in1 ,const complexClass& in2 )
{
    complexClass temp;
    temp.real=in1.real-in2.real;
    temp.imagine=in1.imagine-in2.imagine;
    return temp;
}
complexClass operator*(const complexClass& in1 ,const complexClass& in2 )
{
    complexClass temp;
    temp.real=in1.real*in2.real;
    temp.imagine=in1.imagine*in2.imagine;
    return temp;
}
complexClass operator/(const complexClass& in1,const complexClass& in2)
{
    complexClass temp;
    temp.real=in1.real/in2.real;
    temp.imagine=in1.imagine/in2.imagine;
    return temp;
}
#endif
complexClass::~complexClass()
{
    //dtor
}
