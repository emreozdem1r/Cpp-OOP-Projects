#ifndef GARDROBE_H
#define GARDROBE_H

#include <cabinet.h>


class gardrobe : protected cabinet
{
    public:
        gardrobe();
        virtual ~gardrobe();
        void print();
    protected:

    private:
        double c_volume;
        int no_clothes;
        bool la_coatTree;

};

#endif // GARDROBE_H
