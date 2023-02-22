#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int compliment;
    int m=n;
    int mask = 0;

    if(m == 0){
        cout<<0<<endl;
        return 0;
    }
    while(m != 0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    compliment = (~n) & mask;
    cout<<compliment<<endl;

    return 0;
}