// Given the fence your task is to paint the solts of the fence such that no more that 2 adjacent solts are of same colour. You are given number of solts 'n' and number of colour option 'k'.
// Print the number of ways in which solts can be painted.
// Recursive Approach : Time Complexity : O(n^2), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

// Utility functions starts.

int add(int a, int b){
    return (a%MOD + b%MOD);
}

int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

// Utility functions end.

int solveRecursively(int n, int k){
    // Base Case.
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }

    int ans = mul(k-1, add(solveRecursively(n-2, k), solveRecursively(n-1, k)))%MOD;

    return ans;
}

int solveTopDownMemo(int n, int k, vector<int> &dp){
    // Base case.
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = mul(k-1, add(solveTopDownMemo(n-2, k, dp), solveTopDownMemo(n-1, k, dp)))%MOD;

    return dp[n];
}

int solveBottomUp(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i=3; i<=n; i++){
        dp[i] = mul(k-1, add(dp[i-1], dp[i-2]))%MOD;
    }

    return dp[n];
}

int solveSpaceOptimized(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i=3; i<=n; i++){
        int ans = mul(k-1, add(prev2, prev1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main()
{
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    int k;
    cout<<"Enter the value of k : "<<endl;
    cin>>k;

    // Recursive Approach.
    // int ans = solveRecursively(n, k);

    // Top Down Memoization Approach.
    // vector<int> dp(n+1, -1);

    // int ans = solveTopDownMemo(n, k, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(n, k);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(n, k);

    cout<<"Number ways in which solts can be painted are : "<<ans<<endl;

    return 0;
}