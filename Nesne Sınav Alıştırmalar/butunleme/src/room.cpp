#include "room.h"

room::room(double w,double h,colours color):width(w),height(h),c(color)
{

}
double room::a_area()
{
    return width*height;
}
room::~room()
{
    //dtor
}
