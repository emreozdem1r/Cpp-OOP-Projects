#ifndef FIFO_H
#define FIFO_H
#include <iostream>
#include <string>
using namespace std;
template<typename T>	
class fifo
{
public:
    fifo(int arraySize=10);
    T read();
    bool write(T&);

    fifo<T> operator=(const fifo<T>&);
    T operator [](int index);
    virtual ~fifo();

private:
    int getEmptyLocation();
    T *fifoArray;
    int r_index, w_index,maxSize;
    int arraySize;
};
#endif // FIFO_H
template<typename T>
fifo<T>::fifo(int arraySize)
{
    fifoArray= new T[arraySize];
    this->arraySize=arraySize;
    w_index=0;
    r_index=0;
}
template<typename T>
T fifo<T>::read()
{
   if(r_index!=w_index)
   {
       r_index=r_index%maxSize;
       return fifoArray[r_index++];
   }
}
template<typename T>
bool fifo<T>::write(T &a)
{


}

template<typename T>
int fifo<T>::getEmptyLocation()
{
    if(w_index>r_index)
    {
        return maxSize-(w_index-r_index);
    }
    else
    {	
        return (r_index-w_index);
    }
}
template <typename T>
T fifo<T>::operator[](int index)
{
 

}
template <typename T>
fifo<T> fifo<T>::operator=(const fifo<T>& oIn)
{
    maxSize = oIn.maxSize;
    arraySize = oIn.arraySize;
    if (maxSize < oIn.arraySize)
    {
        for(int i=0; i < maxSize; i ++)
        {
            fifoArray[i]=oIn.fifoArray[i];
        }
    }
}
template <typename T>
fifo<T>::~fifo()
{
    delete [] fifoArray;
}
