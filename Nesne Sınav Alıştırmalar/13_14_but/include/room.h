#ifndef ROOM_H
#define ROOM_H

enum colors{white,blue,red,green,yellow,black};
class room
{
    public:
        room();
        room(double=5,double=5,colors=white);
        virtual double a_area()=0;
        virtual void print()=0;
        virtual ~room();
    protected:
        double width,height;
        colors wallc;
};

#endif // ROOM_H
