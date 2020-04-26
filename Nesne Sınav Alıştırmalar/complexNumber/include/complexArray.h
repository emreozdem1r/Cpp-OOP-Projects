#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H
#include "complexClass.h"

class complexArray
{
    public:
        complexArray operator++();
        const complexArray& operator=(const complexArray&);
        complexArray(int arraySize);
        complexClass& operator[](int index);
        virtual ~complexArray();

    protected:

    private:
        complexClass* cArray; // compozisyon olarak tanýmlanmýþ
        int aSize;
};

#endif // COMPLEXARRAY_H
