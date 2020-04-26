#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;

class animal
{
    public:
        animal();
         virtual ~animal();
        virtual string getVoice();
    protected:
    string voice;
    private:
};

#endif // ANIMAL_H
