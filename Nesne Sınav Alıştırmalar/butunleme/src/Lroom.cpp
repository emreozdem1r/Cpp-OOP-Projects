#include "Lroom.h"

Lroom::Lroom(double width,double height,colours c,int seat,bool inp):room(width,height,c),no_seats(seat)
{
    seatAreas=new double[no_seats];
    if(inp)
        seat_input();
}
double Lroom::a_area()
{
    double seats;
    for(int i=0;i<no_seats;i++)
        seats+=seatAreas[i];
    return width*height-seats;
}
void Lroom::seat_input(){
        cout<<no_seats<<"Kadar Alani Doldurun: "<<endl;
        for(int i=0;i<no_seats;i++)
            cin>>seatAreas[i];

}
 Lroom operator+(const Lroom &a, const Lroom &b)
{
    Lroom temp(a.width+b.width,a.height+b.height,a.c,a.no_seats+b.no_seats,false);

    for(int i=0;i<a.no_seats;i++)
        temp.seatAreas[i]=a.seatAreas[i];
    for(int i=a.no_seats;i<b.no_seats;i++)
        temp.seatAreas[i]=b.seatAreas[i-a.no_seats];

    return temp;
}
void Lroom::print()
{
    cout <<"Alan: "<<a_area();
}

Lroom::~Lroom()
{
    delete [] seatAreas;
}
