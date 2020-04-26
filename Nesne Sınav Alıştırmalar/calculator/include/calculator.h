#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
using namespace std;
#include <string>
template <typename T>
class calculator
{
    public:
        calculator(T,T);
        T topla();
        T cikar();
        T bol();
        T carp();
        void print();
        calculator<T> operator+(const calculator<T> &);
        calculator<T> operator-(const calculator<T> &);
        calculator<T> operator*(const calculator<T> &);
        calculator<T> operator/(const calculator<T> &);

        virtual ~calculator();
    private:
        T sayi1,sayi2;

};
template<typename T>
calculator<T>::calculator(T num1 ,T num2)
{
    this->sayi1=num1;
    this->sayi2=num2;
}
template<typename T>
calculator<T> calculator<T>::operator-(const calculator<T> &in)
{
    calculator<T> temp(0,0);
    temp.sayi1= this->sayi1-in.sayi1;
    temp.sayi2=this->sayi1-in.sayi2;
    temp.cikar();
    return temp;
}
template<typename T>
void calculator<T>::print()
{
 cout<<cikar()<<endl;
}
template<typename T>
calculator<T> calculator<T>::operator+(const calculator<T> &in)
{
    calculator<T> temp(0,0);
    temp.sayi1=this->sayi1+in.sayi1;
    temp.sayi2=this->sayi2+in.sayi2;
    temp.topla();
    return temp;
}
template<typename T>
T calculator<T>::topla()
{
    return this->sayi1+this->sayi2;
}
template<typename T>
T calculator<T>::cikar()
{
    return this->sayi1-this->sayi2;
}
template<typename T>
T calculator<T>::carp()
{
    return this->sayi1*this->sayi2;
}
template<typename T>
T calculator<T>::bol()
{
    return this->sayi1/this->sayi2;
}
template<typename T>
calculator<T>::~calculator()
{

}
#endif // CALCULATOR_H
