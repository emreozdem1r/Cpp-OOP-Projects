#include "cow.h"

cow::cow()
{
    sign="C";
    voice="mooooooooooooo amk moooooooooooo";
}
string cow::getVoice()
{
        return voice;
}
cow::~cow()
{
    //dtor
}
