#ifndef LROOM_H
#define LROOM_H
#define    CONTROL 1
#include <room.h>

#if CONTROL
class Lroom : public room
{
    public:
        Lroom(double width=5,double height=5,colours c=white,int seat=0,bool inp=1);
        void seat_input();
        virtual ~Lroom();
        double a_area();
        void print();

        friend Lroom operator+(const Lroom &a, const Lroom &b);
        #endif // CONTROL
    protected:

    private:
        int no_seats;
        double *seatAreas;

};

#endif // LROOM_H
