#ifndef CAT_H
#define CAT_H
#include  "animal.h"
#include <string>
using namespace std;
class cat:public animal
{
    public:
        cat();
        ~cat();
         string getVoice();
    protected:

    private:
string sign;
};
#endif // CAT_H
