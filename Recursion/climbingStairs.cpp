#include<iostream>
using namespace std;

int climbinStairs(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    return climbinStairs(n-1)+climbinStairs(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<climbinStairs(n)<<endl;

    return 0;
}
