#ifndef LIST_TYPE_H
#define LIST_TYPE_H

template<typename t>
class list_type
{
    int ptr;
    int lsize;
    t *buffer;
    public:

        list_type(int);
        virtual ~list_type();
        int push(t);
        t pop();
        list_type<t>operator+(list_type<t>&);
        t operator[] (int);
        list_type<t>operator=(const list_type<t>&);
    };

    template <typename t>
    list_type<t>::list_type(int lsize){
    this->lsize=lsize;
    ptr=0;
    buffer=new t[lsize];
    }

     template <typename t>
     t list_type<t>::pop(){
     if(ptr>0)
        return buffer[--prt];
     else
        return buffer[0];
     }
     template <typename t>
    list_type<t> list_type<t>::operator+(list_type<t>& oin)
    {
        int totalsize=lsize+oin.lsize;
        list_type<t> tempObject(totalsize);
        int topPtr=ptr;
        for(int i=0;i<topPtr;i++){
            tempObject.push(pop());

        }
        topPtr=oin.ptr;
        for(int i=0;i<topPtr;i++){
            tempObject.push(oin.pop());
        }
        return tempObject;
    }

     template <typename t>
    int list_type<t>::push(t inValue)
    {


    }







#endif // LIST_TYPE_H
