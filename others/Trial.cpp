#include <bits/stdc++.h>
using namespace std;

void pattern(int n){
    int i = 1;

    while(i <= n){
        int temp = i-1;
        while(temp > 0){
            cout<<" ";
            temp--;
        }
        cout<<i;
        int j = (n-i)*2-1;
        while(j > 0){
            cout<<" ";
            j--;
        }
        if(i < n){
            cout<<i;
        }
        cout<<endl;
        i++;
    }
    i = 1;
    while(i < n){
        int j = n-i-1;
        while(j > 0){
            cout<<" ";
            j--;
        }
        cout<<n-i;
        int k = (i)*2-1;
        while(k > 0){
            cout<<" ";
            k--;
        }
        cout<<n-i;
        cout<<endl;
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    
    pattern(n);

    return 0;
}