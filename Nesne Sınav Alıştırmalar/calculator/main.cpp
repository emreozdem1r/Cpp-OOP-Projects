#include <iostream>
#include "calculator.h"
#include <string>
using namespace std;

int main()
{
    calculator<int> nesne(16,2);
    cout<<nesne.topla()<<endl;

    calculator<int> nesne1(23,8);
    cout<<nesne1.topla()<<endl;

    calculator<int> nesne2(0,0);
    nesne2=nesne1-nesne;

    nesne2.print();
}
