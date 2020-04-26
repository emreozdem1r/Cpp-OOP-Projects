#include "dog.h"

dog::dog()
{
   sign="Dog";
   voice="havhav";
}
string dog::getVoice()
{
     return this->sign + " says  " + voice;
}
dog::~dog()
{
    //dtor
}
