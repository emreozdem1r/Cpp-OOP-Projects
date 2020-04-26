#ifndef DOG_H
#define DOG_H
#include <string>
using namespace std;
#include  "animal.h"
class dog:public animal
{
    public:
        dog();
        ~dog();
        string getVoice();
    protected:
    string sign;
    private:
};

#endif // DOG_H
