#include<iostream>
using namespace std;

void increment(int **pt){
    ++**pt; 
}

int main()
{
    int num[5] = {0, 1, 2, 3, 4};
    int *ptr = num;

    cout<<ptr<<endl;

    cout<<*(&num+1)-num<<endl; // to find the size of the array.

    int n = 10;
    int *pt = &n;

    increment(&pt);

    cout<<*pt<<endl;

    cout<<pt<<endl;

    int temp = 2;

    switch (temp << 1){ 
        case 2:
            cout<<"temp's value is : "<<2<<endl;
            break;
        
        case 4:
            cout<<"temp's value is : "<<4<<endl;
            break;
        
        default:
            cout<<"Random value"<<endl;
            break;
    }

    enum data {Male, Female};

    data gender = Female;

    int i = gender;

    cout<<i<<endl;

    return 0;
}