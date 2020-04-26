#include <iostream>
#include "complexClass.h"
using namespace std;
ostream& operator<<(ostream& os,complexClass& in)
{
    os<<"("<<in.real<<" + "<<in.imagine<<"i)";
    return os;
}
istream& operator>>(istream& is,complexClass& in)
{
    is>>in.real>>in.imagine;
    return is;
}
int main()
{
    complexClass nesne1(4,10);
    complexClass nesne2(2,30);
    complexClass nesne3(0,0);
    bool nesne4;
    //nesne4=(nesne1==nesne2);
    //cin>>nesne1;
    //cout<<nesne1;
    //cout<<nesne1.real<<"-" << nesne1.imagine<<endl;
    //cout<<nesne2.real<<"-" << nesne2.imagine<<endl;
    nesne3=nesne1+nesne2;
    //cout<<nesne3.real<<"-" << nesne3.imagine<<endl;
    cout<<nesne3;
   // cout<<nesne4;
}
