#ifndef FIFO_H
#define FIFO_H
#include <iostream>
#include <string>
using namespace std;
template<typename t>

class fifo
{
    public:
        fifo(int arraySize=0);
        t read();
        bool write(t&);
        fifo<t> operator=(const fifo<t>&);
        t operator [](int index);
        virtual ~fifo();
    private:
        int getEmptyLocation();
        t *fifoArray;
        int r_index,w_index,maxSize;
        int arraySize;
};
#endif // FIFO_H
template <typename t>
fifo<t>::fifo(int arraySize){
    fifoArray= new t[arraySize];
    this->arraySize=arraySize;
    w_index=0;
    r_index=0;
}
template<typename t>
t fifo<t>::read()
{
    if(r_index!=w_index)
    {
        r_index=r_index%maxSize;
        return fifoArray[r_index++];
    }
}
template <typename t>
int fifo<t>::getEmptyLocation()
{
        if(w_index<r_index)
        {
            return maxSize-(w_index-r_index);
        }
        else
        {
            return (r_index-w_index);
        }
}
template<typename t>
fifo<t> fifo<t>::operator=(const fifo<t>&o_in)
{
    maxSize=o_in.maxSize;
    arraySize=o_in.arraySize;
    for(int i=0;i<arraySize;i++){
        fifoArray[i]=o_in.fifoArray[i];
    }
}
template<typename t>
fifo<t>::~fifo()
{
    delete []fifoArray;
}
