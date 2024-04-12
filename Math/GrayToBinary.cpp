#include<bits/stdc++.h>
using namespace std;

int grayToBinary(int n, int &prev){
    // Base Case.
    if(n == 0){
        return 0;
    }

    int num = n%2;
    n = grayToBinary(n/2, prev);
    n = n*2 + prev^num;
    prev = n%2;

    return n;
}

int main()
{
    int n;
    cout<<"Enter the value of gray code in decimal"<<endl;
    cin>>n;
    int prev = 0;
    int ans = grayToBinary(n, prev);

    cout<<"Binary equivalent of the given gray code is : "<<ans<<endl;

    return 0;
}