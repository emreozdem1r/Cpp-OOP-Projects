#ifndef KITCHEN_H
#define KITCHEN_H

#include <room.h>


class kitchen : public room
{
    public:
        kitchen();
        virtual ~kitchen();
    private:
        double b_area,t_area;
        int no_cabinet;
        bool ia_oven;
};

#endif // KITCHEN_H
