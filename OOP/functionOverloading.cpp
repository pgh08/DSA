#include<iostream>
using namespace std;

class Example{
    public:
        void add(int a, int b, int c){
            cout<<"Sum is : "<<(a+b+c)<<endl;
        }

        void add(int a, int b){
            cout<<"Sum is : "<<(a+b)<<endl;
        }

        void add(double a, double b){
            cout<<"Sum is : "<<(a+b)<<endl;
        }
};

int main()
{
    Example e;

    e.add(10, 20, 30);

    e.add(100, 200);

    e.add(25.50, 30.50);

    return 0;
}