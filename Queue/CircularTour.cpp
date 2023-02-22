#include<bits/stdc++.h>
using namespace std;

int main()
{
    int petrol[5] = {4,6,7,4};
    int distance[5] = {6,5,3,5};

    int defict = 0;
    int balance = 0;
    int start = 0;

    for(int i=0; i<5; i++){
        balance += petrol[i] - distance[i];
        if(balance < 0){
            defict += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(defict+balance > 0){
        cout<<"Starting Point is : "<<start<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }
    return 0;
}