#include "cat.h"

cat::cat()
{
 sign="cat";
    voice="miyav";
}
string cat::getVoice(){
    return this->sign + " says  " + voice;

}
cat::~cat()
{
    //dtor
}
