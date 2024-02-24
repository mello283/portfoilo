#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE=20;
typedef int ET;

class List
{
private:
    ET ary[SIZE];
    int pos=0;
    int mySize=0;
public:

    List();
    List(List &p2);
    bool listEmpty();
    void first();
    void last();
    void prev();
    void next();
    int getPos();
    void setPos(ET);
    void insertBefore(ET);
    void insertAfter(ET);
    int getElement();
    int size();
    void replace(ET);
    void clear();
    void erase();
    bool operator==(const List&L2);
    bool operator!=(const List&L2);
    List operator+(const List&L2);
    List operator+=(const List&L2);
    List operator=(List&L2);
    friend ostream& operator << (ostream &out, const List &L2);
};
List::List()
{
    int pos=0;
    int mySize=0;
    for(int i=0;i<SIZE;i++)
        ary[i]=0;
}
List::List(List &L)
{
    for(int i=0;i<L.size();i++)
        ary[i]=L.getElement();
}
void List::first()
{
    pos=0;
}
void List::last()
{
    if(mySize!=0)
        pos=mySize-1;
}
void List::next()
{
    if(pos+1<=mySize)
        pos++;
}
void List::prev()
{
    if(pos-1>=0)
        pos--;
}
void List::setPos(ET val)
{
    if(val>0&&val<mySize-1)
        pos=val;
}
int List::getPos()
{
    return pos;
}
void List::erase()
{
    ary[pos]=0;
    mySize--;
    pos--;
}
int List::size()
{
    if(mySize>0)
        return mySize;
    else
        return 0;
}
void List::insertBefore(ET val)
{
    if(mySize==SIZE-1)
    {
        ary[mySize]=val;
    }
    else if(mySize==0)
    {
        ary[0]=val;
        pos++;
        mySize++;
    }
    else
    {
        for(int i=mySize;i<pos;i++)
            ary[mySize]=ary[i-1];
        ary[pos]=val;
        pos++;
        mySize++;
    }
}
void List::insertAfter(ET val)
{
        for(int i=mySize;i>pos;i--)
            ary[i]=ary[i-1];
        if(pos!=0)
            ary[pos]=val;
        else if(pos==SIZE-1)
            ary[SIZE-1]=val;
        else
            ary[0]=val;
        if(mySize+1<SIZE)
        {
            mySize++;
            pos++;
        }
}
void List::replace(ET val)
{
    ary[pos]=val;
}
void List::clear()
{
    for(int i=0;i<mySize;i++)
        ary[i]=0;
    pos=0;
    mySize=0;
}
bool List::listEmpty()
{
    if(mySize==0)
        return true;
    else
        return false;
}
int List::getElement()
{
    ET element=ary[pos];
    return element;
}
bool List::operator==(const List&L2)
{
    if(mySize==L2.mySize)
    {
        for(int i=0;i<mySize-1;i++)
        {
            if(ary[i]!=L2.ary[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
ostream& operator<<(ostream &out,List &L1)
{
    out<<"Pos: "<<L1.getPos()<<endl<<"Current element: "<<L1.getElement()<<endl;
    return out;
}
bool List::operator!=(const List&L2)
{
    return !(operator==(L2));
}
List List::operator+(const List&L2)
{
    List sum;
    for(int i=0;i<SIZE;i++)
        sum.ary[i]+=L2.ary[i];
    return sum;
}
List List::operator+=(const List&L2)
{
    for(int i=0;i<SIZE;i++)
        ary[i]+L2.ary[i];
}
List List::operator=(List&L2)
{
    L2.pos=getPos();
    L2.mySize=size();
    for(int i=0;i<mySize-1;i++)
        L2.ary[i]=ary[i];
}
//overload << and ==
#endif // LIST_H_INCLUDED
