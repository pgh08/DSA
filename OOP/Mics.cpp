// #include<iostream>
// using namespace std;

// class Person{
//     public:
//         static int age;
//         string name = "Prajwal";
// };

// int Person :: age = 22;

// int main()
// {
//     cout<<Person::age<<endl;

//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Complex{
//     private:
//         int real, img;

//     public:
//         Complex(int r=0, int i=0){
//             this->real = r;
//             this->img = i;
//         }

//         Complex operator+(Complex &obj){
//             Complex res;

//             res.real = real + obj.real;
//             res.img = img + obj.img;

//             return res;
//         }

//         void print(){
//             cout<<"Result of complex addition is : "<<real<<"+i"<<img<<endl;
//         }
// };

// int main()
// {
//     Complex c1(10, 20), c2(5, 5);

//     Complex c3 = c1+c2;
//     c3.print();

//     return 0;
// }

// #include<iostream>
// using namespace std;

// class A{
//     public:
//         void disp(){
//             cout<<"I am class A"<<endl;
//         }
// };

// class B{
//     public:
//         void disp(){
//             cout<<"I am class B"<<endl;
//         }
// };

// class C : public A, public B{
//     public:
//         void print(){
//             cout<<"I am class C"<<endl;
//         }      
// };

// int main()
// {
//     C obj;
//     obj.A::disp();

//     obj.B::disp();

//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Base{
//     public:
//         Base(){
//             cout<<"I am Base Class"<<endl;
//         }
// };

// class Intermediate1 : virtual public Base{
//     public:
//         Intermediate1(){
//             cout<<"I am class Intermediate1"<<endl;
//         }
// };

// class Intermediate2 : virtual public Base{
//     public:
//         Intermediate2(){
//             cout<<"I am class Intermediate2"<<endl;
//         }      
// };

// class derivedClass : public Intermediate1, public Intermediate2{
//     public:
//         derivedClass(){
//             cout<<"I am derived class"<<endl;
//         }
// };

// int main()
// {
//     derivedClass obj;

//     return 0;
// }

#include<iostream>
using namespace std;

class Super{
    public:
        virtual void disp(){
            cout<<"This is base class"<<endl;
        }
};

class Sub : public Super{
    public:
        void disp(){
            cout<<"This is sub class"<<endl;
        }
};

int main()
{
    Sub obj;
    Super *obj1;

    obj1 = &obj;

    obj1->disp();

    return 0;
}