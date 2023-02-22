#include<iostream>
using namespace std;

int main()
{
    int i = 10;
    int j = 0;
    int *const ptr = &i; 

    *ptr = 100;

    cout<<*ptr<<endl;

    return 0;
}