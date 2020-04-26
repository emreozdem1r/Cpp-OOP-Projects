#include <iostream>
#include  "animal.h"
#include "dog.h"
#include  "cat.h"
#include "cow.h"
#include <string>
using namespace std;
void getValueofAnimal(animal &);
void getValueofAnimal(animal *);
int main()
{
    animal *pAnimal=new cow;

//    cat kedi;
  //  getValueofAnimal(kedi);
    getValueofAnimal(pAnimal);
    delete pAnimal;
    /*destructor virtual olarak tanimlanmadiginda bu delete olayi sadece base classýn
    destructor i cagirilir. Baseclassýn destructori virtual oldugunda silinecek nesnenin
    destructori cagirilir.*/
}
void getValueofAnimal(animal &type)
{
   cout<< type.getVoice()<<endl;
}
void getValueofAnimal(animal *type)
{
   cout<< type->getVoice()<<endl;
}
