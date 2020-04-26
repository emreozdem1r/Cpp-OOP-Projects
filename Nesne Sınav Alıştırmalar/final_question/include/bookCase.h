#ifndef BOOKCASE_H
#define BOOKCASE_H
#include "cabinet.h"

class bookCase:protected cabinet
{
    public:
        bookCase();
        virtual ~bookCase();

    protected:

    private:
        double b_volume;
        int no_books;

};

#endif // BOOKCASE_H
