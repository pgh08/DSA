#include<iostream>
using namespace std;

int power(int a, int b){
    //Base case.
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    //Recursive call.
    int ans = power(a, b/2);
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main()
{
    int a,b;
    cout<<"Enter the value of 'a' power 'b' respectivey"<<endl;
    cin>>a>>b;

    int ans = power(a,b);

    cout<<"'a' power 'b' is equal to : "<<ans<<endl;

    return 0;
}