#ifndef COMPLEX_H
#define COMPLEX_H
#define IMPLEMENT_AS_MEMBER 1

class complex
{
    public:
        complex();
        friend ostream& operator <<(ostream&,const complex&)
        virtual ~complex();
    private:
        double real,imagine;
};

#endif // COMPLEX_H
