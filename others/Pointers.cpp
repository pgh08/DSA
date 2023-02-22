#include<bits/stdc++.h>
using namespace std;

int main()
{
/*    int num = 5;
    int *ptr = &num;
    cout<<++*ptr<<endl;
    cout<<num<<endl;

    int *q = ptr;
    cout<<*q<<endl;*/
    int i = 5;
    int *ptr1 = &i;
    int **prt2 = &ptr1;

    cout<<"prt1 "<<&ptr1<<endl;
    cout<<"ptr2 "<<prt2<<endl;
    cout<<"*ptr1 "<<*ptr1<<endl;
    cout<<"*prt2 "<<**prt2<<endl;
//    cout<<"**prt2"<<**ptr2<<endl;
}