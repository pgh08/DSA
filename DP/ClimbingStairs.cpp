#include<bits/stdc++.h>
using namespace std;

int N = 45;
int dp[45];

//Top down approach.
int NumberOfCombination(int n){
    //Base case.
    if(n <= 1){
        return dp[n] = 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = NumberOfCombination(n-1) + NumberOfCombination(n-2); 
}

//Bottom up approach.
int bottomUp(int n){
    int one = 1;
    int two = 1;
    for(int i=0; i<n-1; i++){
        int temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    int ans = NumberOfCombination(n);
    int ans1 = bottomUp(n);

    cout<<"Total number of combination is "<<ans1<<endl;

    return 0;
}