#include <iostream>
#include "lifo.h"
using namespace std;
#include <string>
int main()
{
    lifo<int> nesne(10);

    for(int i=0;i<10;i++)
    nesne.push(i);

    for(int i=0;i<10;i++)
    cout<< nesne.pop()<<endl;

}
