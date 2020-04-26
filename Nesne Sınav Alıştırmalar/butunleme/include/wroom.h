#ifndef WROOM_H
#define WROOM_H

#include <room.h>


class wroom : public room
{
    public:
        wroom();
        virtual ~wroom();
    private:
    double bc_area,t_area;
    int no_books;
    bool ia_books;

};

#endif // WROOM_H
