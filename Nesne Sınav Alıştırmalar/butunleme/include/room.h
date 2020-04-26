#ifndef ROOM_H
#define ROOM_H
#include "string"
#include <iostream>
using namespace std;
 enum colours{white,blue,red,green,yellow,black};
class room
{
    public:
        room(double=5,double=5,colours=white);
        virtual ~room();
        double a_area();
        virtual void print()=0;
    protected:
        double height,width;
       colours c;
    private:
};

#endif // ROOM_H
