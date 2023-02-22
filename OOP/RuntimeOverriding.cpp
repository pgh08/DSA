#include<iostream>
using namespace std;

class base{
    public:
        virtual void printing(){
            cout<<"Hello from base class"<<endl;
        }

        void show(){
            cout<<"This is base class"<<endl;
        }
};

class derived : public base{
    public:
        void printing(){
            cout<<"Hello from derived class"<<endl;
        }

        void show(){
            cout<<"This is derived class"<<endl;
        }
};

int main()
{
    base *bptr;
    derived d;

    bptr->show();
    d.show();

    bptr = &d;

    //Use of virtual function.
    bptr->printing();
    bptr->show();

    return 0;
}