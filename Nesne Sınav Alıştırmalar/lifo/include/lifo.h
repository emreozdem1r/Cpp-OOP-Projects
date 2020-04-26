#ifndef LIFO_H
#define LIFO_H

#define LIFO_FULL -1
#define LIFO_OK 0

template <typename T>
class lifo
{
    int topPtr;
    int lSize;
    T *lifoBuffer;
    public:
        lifo(int);
        virtual ~lifo();
        int push(T);
        T pop();
        lifo<T> operator +(lifo<T>&);
        T operator*(const lifo<T>& oIn);
        T operator[](int);
        lifo<T> operator =(const lifo<T>&);
};

template <typename T>
lifo<T>::lifo(int lifoSize)
{
    lSize = lifoSize;
    topPtr = 0;
    lifoBuffer = new T[lifoSize];
    //ctor
}

template <typename T>
T lifo<T>::pop()
{
  if(topPtr > 0)
    return lifoBuffer[--topPtr];
  else
    return lifoBuffer[0];
}

template <typename T>
int lifo<T>::push(T inValue)
{
  if (topPtr < lSize){
    lifoBuffer[topPtr ++] = inValue;
    return LIFO_OK;
  } else return LIFO_FULL;
}

template <typename T>
lifo<T> lifo<T>::operator+(lifo<T>& oIn)
{
  int totalSize = lSize + oIn.lSize;
  lifo<T> tempObject(totalSize);
  int _topPtr = topPtr;
  for (int i = 0; i < _topPtr; i++){
    tempObject.push(pop());
  }
  _topPtr = oIn.topPtr;
  for (int i = 0; i < _topPtr; i++){
    tempObject.push(oIn.pop());
  }
  return tempObject;
}

template <typename T>
T lifo<T>::operator[](int index)
{
   if(index >= 0 && index < topPtr)
    return lifoBuffer[index];
   else
    return lifoBuffer[0];
}

template <typename T>
lifo<T> lifo<T>::operator=(const lifo<T>& oIn)
{
   topPtr = oIn.topPtr;
   lSize = oIn.lSize;
   if (topPtr < oIn.lSize){
     for(int i=0; i < topPtr; i ++)
     {
        lifoBuffer[i] = oIn.lifoBuffer[i];
     }
   }
}

template <typename T>

T lifo<T>::operator*(const lifo<T>& oIn){
    int vectorSize = 0;
    T returnValue = 0;

    if (topPtr > oIn.topPtr) {
        vectorSize = oIn.topPtr;
    } else vectorSize = topPtr;


    for (int i = 0; i < vectorSize; i ++)
        returnValue += oIn.lifoBuffer[i] * lifoBuffer[i];

    return returnValue;
}

template <typename T>
lifo<T>::~lifo()
{
    delete lifoBuffer;
    //dtor
}

#endif // LIFO_H
