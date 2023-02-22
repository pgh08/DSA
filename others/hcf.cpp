#include<bits/stdc++.h>
using namespace std;

int gcd_hcf(int a, int b)
{
    if(a == 0){
        return b;
    }

    if(b == 0){
        return a;
    }
    while (a != b){
        if(a > b){
            a = a-b; 
        }
        else{
            b = b-a; 
        }
    }
    return a;
     
}

int main()
{
    int num1,num2;
    cout<<"Enter 2 numbers"<<endl;
    cin>>num1>>num2;

    int ans = gcd_hcf(num1,num2);

    cout<<"GCD/HCF is : "<<ans;
    return 0;
}