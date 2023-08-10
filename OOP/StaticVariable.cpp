#include<iostream>
using namespace std;

int counter(){
    static int count = 0;
    count++;
    return count;
}

int main()
{
    for(int i=0; i<4; i++){
        cout<<counter()<<" ";
    }
    cout<<endl;

    return 0;
}