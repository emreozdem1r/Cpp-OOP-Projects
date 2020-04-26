#include <iostream>
#include "complexClass.h"
#include "complexArray.h"
using namespace std;

istream& operator >> (istream& is, complexClass& in){
    is>> in.real >> in.imaginary;
    return is;
}
ostream& operator << (ostream& os, complexClass& in){
    os<<"(" <<in.real <<" , "<< in.imaginary<<"i )";
    return os;
}

	template <class Type>
	Type larger(Type x, Type y){
   	if(x >= y) return x;
   	else return y;
	}


int main()
{


    complexClass complexNumber1(4,2), complexNumber2(2,1), complexNumber3(1,1);
    complexArray mycomplexArray(100),yourcomplexArray(100);


    cout<<"Karmasik Sayilar: "<< endl;
    cout<<complexNumber1<<" + "<<complexNumber2<<endl; //modifiye edilen << ve >> operat�rlerini deniyoruz.
    cout<<complexNumber1.real<<"+"<<complexNumber1.imaginary<<"i"<< endl;
    cout<<complexNumber2.real<<"+"<<complexNumber2.imaginary<<"i"<< endl;

        complexNumber3 = complexNumber1+complexNumber2;
    cout<<"Toplama: "<<complexNumber3.real<<"+"<<complexNumber3.imaginary<<"i"<< endl;
    complexNumber3 = complexNumber1-complexNumber2;
    cout<<"Cikartma: "<<complexNumber3.real<<"+"<<complexNumber3.imaginary<<"i"<< endl;
        complexNumber3 = complexNumber1*complexNumber2;
    cout<<"Carpma: "<<complexNumber3.real<<"+"<<complexNumber3.imaginary<<"i"<< endl;
        complexNumber3 = complexNumber1/complexNumber2;
    cout<<"Bolme: "<<complexNumber3.real<<"+"<<complexNumber3.imaginary<<"i"<< endl;


     mycomplexArray=yourcomplexArray;
    cout<<mycomplexArray[10]<< endl;
    cout<<"------------ "<< endl;
    complexNumber3="(2,4)";
    cout<<":::> "<<complexNumber3.real<<"+"<<complexNumber3.imaginary<<"i"<< endl;
        /**/
     /*   string cArray="(1,2)|(3,4)|(4,5)|(6,9)";
        mycomplexArray=cArray;
        */
    complexNumber3=larger(complexNumber1,complexNumber2);
    int largeValue=larger(3,5);

    return 0;
}
