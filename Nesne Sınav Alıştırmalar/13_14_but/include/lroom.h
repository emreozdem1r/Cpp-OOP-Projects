#ifndef LROOM_H
#define LROOM_H

#include <room.h>


class lroom : public room
{
    public:
        lroom();
        lroom(double w, double h, colors r, int ns, bool inp);
        lroom(const lroom &other);
        void seat_input();
        lroom operator+(const lroom &);
        void print() ;
        double a_area();
        virtual ~lroom();
    private:
        double *seat_areas;
        int no_seats;
};

#endif // LROOM_H
