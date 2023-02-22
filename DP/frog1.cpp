#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];

int frog(int h[], int i){
    //Base case.
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int constant = INT_MAX;
    //For single jump.
    constant = min(constant, frog(h, i-1)+abs(h[i]-h[i-1]));
    //For two jump.
    if(i > 1){
        constant = min(constant, frog(h, i-2)+abs(h[i]-h[i-2]));
    }
    return dp[i] = constant;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    int h[n];
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    int ans = frog(h, (n-1));

    cout<<ans<<endl;

    return 0;
}