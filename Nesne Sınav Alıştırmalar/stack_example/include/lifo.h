#ifndef LIFO_H
#define LIFO_H

#define LIFO_FULL -1
#define LIFO_OK 0
template <typename T>
class lifo
{
    public:
        lifo(int);
        int push(T);
        T pop();
        lifo<T> operator=(const lifo<T>&);
        T operator*(const lifo<T>&);
        T operator[](int);
        lifo<T> operator+(lifo<T>&);

        virtual ~lifo();
    private:
        int topPtr;
        int lsize;
        T *lifoBuffer;
};

template<typename T>
lifo<T>::lifo(int arraySize)
{
    lsize=arraySize;
    topPtr=0;
    lifoBuffer=new T[arraySize];
}
template <typename T>
int lifo<T>::push(T inValue)
{
    if(topPtr<lsize){
        lifoBuffer[topPtr++]=inValue;
        return LIFO_OK;
    }
    else
        return LIFO_FULL;
}
template <typename T>
T lifo<T>::pop()
{
    if(topPtr>0)
    {
        return lifoBuffer[--topPtr];
    }
    else
        lifoBuffer[0];
}
template <typename T>
lifo<T> lifo<T>::operator=(const lifo<T> &in)
{
    lsize=in.lsize;
    topPtr=in.topPtr;
    for(int i=0;i<lsize;i++)
    {
        lifoBuffer[i]=in.lifoBuffer[i];
    }
}
template <typename T>
lifo <T> lifo<T>::operator+(lifo<T>&in)
{
    int tempSize;
    tempSize=lsize+in.lsize;
    lifo<T> tempObject(tempSize);
    int newTop=topPtr;
    for(int i=0;i<newTop;i++)
    {
        tempObject.push(pop());
    }
    newTop=in.topPtr;
    for(int i=0;i<newTop;i++)
    {
        tempObject.push(in.pop());
    }
    return tempObject;
}
template<typename T>
T lifo<T>::operator[](int index)
{
    if(index>=0 && index<topPtr)
        return lifoBuffer[index];
    else
        return lifoBuffer[0];
}
template <typename T>
T lifo<T>::operator*(const lifo<T> &in)
{
    int vectorSize=0;
    T returnValue=0;
    if(topPtr<in.topPtr)
        vectorSize=topPtr;
    else
        vectorSize=in.topPtr;
    for(int i=0;i<vectorSize;i++)
    {
        returnValue+=lifoBuffer[i]*in.lifoBuffer[i];
    }
    return returnValue;
}
template <typename T>
lifo<T>::~lifo()
{
    delete []lifoBuffer;
}
#endif // LIFO_H
