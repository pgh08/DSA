#include<iostream>
using namespace std;

class Overload{
    public:
        int real;
        int imaginary;

        Overload(int r, int i){
            this->real = r;
            this->imaginary = i;
        }

        Overload operator+(Overload obj){
            Overload res(0, 0);
            res.real = real + obj.real;
            res.imaginary = imaginary + obj.imaginary;
            return res;
        }
};

int main()
{
    Overload O1(10, 20), O2(30, 40);

    Overload O3 = O1 + O2;

    cout<<O3.real<<" + i"<<O3.imaginary<<endl; 

    return 0;
}