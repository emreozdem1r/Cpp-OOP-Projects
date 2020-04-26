#ifndef KITCHEN_H
#define KITCHEN_H

#include <room.h>


class kitchen : public room
{
    public:
        kitchen();
        kitchen(double w,double h,colors c,int nc,bool ia);
        void print();
        double a_area();
        virtual ~kitchen();

    protected:

    private:
        double b_area,t_area;
        int no_cabinets;
        bool ia_oven;
};

#endif // KITCHEN_H
