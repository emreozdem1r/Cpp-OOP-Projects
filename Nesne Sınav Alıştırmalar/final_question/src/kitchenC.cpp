#include "kitchenC.h"

kitchenC::kitchenC(double n_height,double n_width,double n_depth,string clr,int arraySize):cabinet(n_height,n_width,n_depth,clr)
{
  kw_volumes=new double[arraySize];
}
kitchenC::kitchenC(const kitchenC& p)
{
    this->height=p.height;
    this->width=p.width;
    this->depth=p.depth;
    this->colour=p.colour;
}
double kitchenC::a_volume()const
{
    return height*width*depth;
}
double kitchenC::operator +(const kitchenC& p)const
{
    double sonuc;
    sonuc=this->a_volume()+ p.a_volume();
    return sonuc;
}
kitchenC::~kitchenC()
{
   delete [] kw_volumes;
}
