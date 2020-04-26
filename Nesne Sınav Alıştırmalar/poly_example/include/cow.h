#ifndef COW_H
#define COW_H
#include  "animal.h"
#include <string>
using namespace std;

class cow:public animal
{
    public:
        cow();
        ~cow();
        string getVoice();
    protected:

    private:
        string sign;
};

#endif // COW_H
