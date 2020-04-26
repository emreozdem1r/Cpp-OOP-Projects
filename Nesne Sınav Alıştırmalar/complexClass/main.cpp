#include <iostream>
#include <string>
#include "complexClass.h"
#include "complexArray.h"
using namespace std;

istream& operator >>(istream &is,complexClass& in)
{
    is>>in.real>>in.imagine;
    return is;
}
ostream& operator<<(ostream& os,complexClass& in)
{
    os<<"("<<in.real<<","<<in.imagine<<"i)";
    return os;
}
int main()
{


}
