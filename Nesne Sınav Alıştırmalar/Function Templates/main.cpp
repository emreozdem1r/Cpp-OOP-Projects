#include <iostream>
#include "point.h"

using namespace std;
/* function templates generalization*/

template <typename T, typename T1>

T add( T p1, T1 p2) {
  return p1 + p2;
}

void operationOnPoints();

int main()
{
    operationOnPoints();

    return 0;
}

void operationOnPoints()
{
    Point2D p1(10, 67);
    Point2D p2(50, 3); // 60,70

    Point2D sum = add(p1,p2);

#if 1
    cout << (add((double)5, 6.5)) << endl;
    cout << sum.getX() << endl;
    cout << sum.getY() << endl;
#endif


}
