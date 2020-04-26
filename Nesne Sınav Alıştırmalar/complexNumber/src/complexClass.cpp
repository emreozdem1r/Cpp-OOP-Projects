#include "complexClass.h"
#include <cstdlib>
#include <math.h>
#define AS_IMPLEMENT_NUMBER 1
complexClass::complexClass(double real_in,double imaginary_in)
{
    //ctor
    real = real_in;
    imaginary=imaginary_in;
}
#if AS_IMPLEMENT_NUMBER

bool complexClass::operator> (const complexClass& in) const{
    if(this->real>in.real && this->imaginary>in.imaginary) return true;
    else return false;
}
bool complexClass::operator >= (const complexClass& in1)const{
    double in1Uzunluk= pow(this->real,2) + pow(this->imaginary,2);
    double in2Uzunluk= pow(in1.real,2) + pow(in1.imaginary,2);
    if(in1Uzunluk>=in2Uzunluk){
        return true;
    }else {
        return false;
    }

}
bool complexClass::operator==(const complexClass& in) const{
    if(this->real==in.real && this->imaginary==in.imaginary) return true;
    else return false;
}
complexClass complexClass::operator +(const complexClass& in)const{
    complexClass tempObj;
    tempObj.real=this->real+in.real;
    tempObj.imaginary=this->imaginary+in.imaginary;
    return tempObj;
}
complexClass complexClass::operator -(const complexClass& in)const{
    complexClass tempObj;
    tempObj.real=this->real-in.real;
    tempObj.imaginary=this->imaginary-in.imaginary;
    return tempObj;
}
complexClass complexClass::operator/(const complexClass& in)const{
    complexClass tempObj;
    tempObj.real=this->real/in.real;
    tempObj.imaginary=this->imaginary/in.imaginary;
    return tempObj;
}
complexClass complexClass::operator*(const complexClass& in)const{
    complexClass tempObj;
    tempObj.real=this->real*in.real;
    tempObj.imaginary=this->imaginary*in.imaginary;
    return tempObj;
}
//conversation constructor
complexClass::complexClass(const char * str){
    string complexnumber = str;
   size_t pos=complexnumber.find(',');
    real=atoi(&complexnumber[pos-1]);
    imaginary=atoi(&complexnumber[pos+1]);
}
//conversation constructor devam. // (1,2)(3,4) gibi gelen deðerleri ayýrmak
//bitbucletten al
/*
complexClass::complexArray(const string &complexArrayString){
    int insize=0;
    string complexNumberString= complexArrayString;
    string complexNumber;
    this->cArray = new complexClass[complexArrayString/5];
    for(int i=0;i<complexArrayString/5;i++){
        if(complexArrayString[i]=='|'){
                complexNumber=complexNumberString.substr(0,1);
                complexNumberString=complexNumberString.substr();
                cArray[insize]=complexNumber.c_str();
        }
    }
    cArray[insize++]=complexNumberString;
}

*/
#else
complexClass operator+(const complexClass& o_in1,const complexClass& o_in2){
      complexClass tempObj;
    tempObj.real=o_in1.real + o_in2.real;
    tempObj.imaginary=o_in1.imaginary + o_in2.imaginary;
    return tempObj;
}
complexClass operator- (const complexClass& o_in1,const complexClass& o_in2){
    complexClass tempObj;
    tempObj.real=o_in1.real- o_in2.real;
    tempObj.imaginary=o_in1.imaginary-o_in2.imaginary;
    return tempObj;
}
complexClass operator /(const complexClass& in1,const complexClass& in2){
    complexClass tempObj;
    tempObj.real=in1.real/in2.real;
    tempObj.imaginary=in1.imaginary/in2.imaginary;
    return tempObj;
}
complexClass operator*(const complexClass& in1,const complexClass& in2){
    complexClass tempObj;
    tempObj.real=in1.real*in2.real;
    tempObj.imaginary=in1.imaginary*in2.imaginary;
    return tempObj;
}
#endif
complexClass::~complexClass()
{
    //dtor
}
