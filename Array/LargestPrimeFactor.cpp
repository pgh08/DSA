// Given the integer N find its largest prime factor.
#include<iostream>
#include<cmath>
using namespace std;

int getPrimeFactor(int N){
    int maxi = 0;

    while(N%2 == 0){
        maxi = 2;
        N = N/2;
    }

    for(int i=3; i<=sqrt(N); i=i+2){
        while(N%i == 0){
            maxi = max(maxi, i);
            N = N/i;
        }
    }

    if(N > 2){
        maxi = max(maxi, N);
    }

    return maxi;
}

int main()
{
    int N;
    cout<<"Enter the value of N"<<endl;
    cin>>N;

    int ans = getPrimeFactor(N);

    cout<<"Largest Prime Factor is : "<<ans<<endl;

    return 0;
}