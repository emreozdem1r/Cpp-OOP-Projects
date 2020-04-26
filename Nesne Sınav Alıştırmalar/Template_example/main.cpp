#include <iostream>

using namespace std;
template <typename t>
t square(t x)
{
    t temp;
    temp=x*x;
    return temp;
}
int main()
{
    int x=5;
    double y=2.2;
    float z=5.1;
    cout<<square<int>(x)<<endl;
    cout<<square<double>(y)<<endl;
    cout<<square<float>(z)<<endl;

}
