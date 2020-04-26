#ifndef COMPLEXCLASS_H
#define COMPLEXCLASS_H

#include <iostream>
#define CONTROL 0
using namespace std;
class complexClass
{
    public:

        complexClass(double real_in=0, double imagine_in=0);
        friend ostream& operator<<(ostream&,const complexClass& );
        friend istream& operator>>(istream&,const complexClass&);
        double real,imagine;
        #if CONTROL
        complexClass operator+(const complexClass& )const;
        complexClass operator-(const complexClass& )const;
        complexClass operator*(const complexClass& ) const;
        complexClass operator/(const complexClass& ) const;
        bool operator>(const complexClass &) const ;
        bool operator<(const complexClass&) const;
        bool operator==(const complexClass&) const;
        #else
        friend complexClass operator+(const complexClass&,const complexClass&);
        friend complexClass operator-(const complexClass&, const complexClass&);
        friend complexClass operator*(const complexClass&,const complexClass&);
        friend complexClass operator/(const complexClass&, const complexClass&);
        #endif // CONTROL
        virtual ~complexClass();

    protected:

    private:
};

#endif // COMPLEXCLASS_H
