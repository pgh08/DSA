#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int ans = 0;
    while(n != 0){
        if(n&1 == 1){
            ans++;
        }
        n = n>>1;
    }
    cout<<ans<<endl;

    return 0;
}