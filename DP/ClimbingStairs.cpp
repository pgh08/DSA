// Given a number of stairs, find the minmum number of ways in which we can reach the top if we are allowed to climb 1 or 2 stairs at each jump.
// Top-Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
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

int bottomUpCombinations(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space optimized approach.
int SpaceOptimizedClimingStairs(int n){
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

    cout<<"Enter the number of stairs"<<endl;
    cin>>n;

    // int ans = NumberOfCombination(n);
    // int ans1 = bottomUpCombinations(n);
    int optimized = SpaceOptimizedClimingStairs(n);

    cout<<"Total number of combination is : "<<optimized<<endl;

    return 0;
}