// Given an interger find the least number of squares required to make that integer.
// Recursive Solution : Time Complexity : O(n*sqrt(n)), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n) + O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(int n){
    // Base Case.
    if(n == 0){
        return 0;
    }

    int ans = n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+solveRecursively(n-i*i));
    }

    return ans;
}

int solveTopDownMemo(int n, vector<int> &dp){
    // Base Case.
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+solveTopDownMemo(n-i*i, dp));
    }
    dp[n] = ans;

    return ans;
}

int solveBottomUp(int n){
    // Initialization of dp array.
    vector<int> dp(n+1, INT_MAX);

    // Initialization of base case.
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
            if((i-j*j) >= 0){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the value of integer"<<endl;
    cin>>n;

    // Recursive Approach.
    // int ans = solveRecursively(n);

    // Top Down Memoization Approach.
    // vector<int> dp(n+1, -1);
    // int ans = solveTopDownMemo(n, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(n);

    cout<<"Least number of square numbers required are : "<<ans<<endl;

    return 0;
}