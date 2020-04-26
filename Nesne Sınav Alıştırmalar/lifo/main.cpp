#include <iostream>
#include "lifo.h"
#include "complexNumber.h"
using namespace std;

int main()
{
    /*lifo<complexNumber> a(10);
    lifo<complexNumber> b(20);
    complexNumber x(5.4, 7.0);
    complexNumber y(5.7, 6.7);
*/
int x=1,y=0;
    lifo<int> a(4);
    lifo<int> b(5);
    a.push(x++);
    a.push(x++);
    a.push(x++);
    a.push(x++);

    b.push(y++);
    b.push(y++);
    b.push(y++);
    b.push(y++);
    b.push(y++);
    lifo<int> c(5);

    c=a;
    for(int i=0;i<4;i++)
        cout<<c.pop()<<endl;
    //lifo<complexNumber> c = a + b;

    //double d = a * b;

    //cout << "Hello world!" << c[3] << endl;
    return 0;
}
