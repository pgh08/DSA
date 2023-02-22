//Abstract Class : Sometimes implementation of all function cannot be provided in a base class because we don’t know the implementation. Such a class is called abstract class.  
//                 A class is abstract if it has at least one pure virtual function.

//1. Simple example.
/* #include<iostream>
using namespace std;

class base{
    public:
        virtual void print() = 0;
};

class derived : public base{
    public:
        void print(){
            cout<<"This is derived class"<<endl;
        }
};

int main()
{
    derived d;

    d.print();

    return 0;
} */

//2. Error case 1 : Objects of abstract class type 'base' is not allowed.
/* #include<iostream>
using namespace std;

class base{
    public:
        virtual void print() = 0;
};

int main()
{
    base b;
    b.print();

    return 0;
} */

//3. Error case 2 : Objects of abstract class type 'derived' is not allowed.
/* #include<iostream>
using namespace std;

class base{
    public:
        virtual void print() = 0;
};

class derived : public base {};

int main()
{
    derived d;
    d.print();

    return 0;
} */

//4. Abstract class can have constructor.
#include<iostream>
using namespace std;

class base{
    protected:
        int x;
    public:
        virtual void fun() = 0;

        base(int data){
            cout<<"Base class constructor is called"<<endl;
            this->x = data;
        }
};

class derived : public base{
    int y;
    public:
        derived(int data1, int data2) : base(data1){
            this->y = data2;
        }
        void fun(){
            cout<<"X is : "<<x<<" and Y is : "<<y<<endl;
        }
};

int main()
{
    derived d(10, 20);
    d.fun();

    base *b = new derived(30, 40);

    b->fun();

    return 0;
}