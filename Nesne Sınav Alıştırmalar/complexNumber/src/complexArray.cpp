#include "complexArray.h"

complexArray::complexArray(int arraySize)
{
    cArray= new complexClass[arraySize];
    aSize=arraySize;
    //ctor
}
/*
complexArray complexArray::operator++(){

}*/
complexClass& complexArray::operator[](int index){
  if(index<=0)
  index=0;
  else if(index>=aSize)
    index= aSize-1;
return(this->cArray[index]);
}

const complexArray& complexArray::operator=(const complexArray& in)
{
    int i;
    if(this!= &in)
    {
        if(this->aSize > in.aSize)
        {
            this->aSize= in.aSize;
        }
        for(i=0; i<this->aSize; i++)
        {
            this->cArray[i]=in.cArray[i];
        }
    }  return * this;
}

complexArray::~complexArray()
{
    //dtor
    delete [] cArray;
}
