#include "cabinet.h"

cabinet::cabinet(double w,double h,double dep,string clr)
{
    colour=clr;
    width=w;
    height=h;
    depth=dep;
}
double cabinet::a_volume()
{
    return width*height*depth;
}
cabinet::~cabinet()
{
    //dtor
}
