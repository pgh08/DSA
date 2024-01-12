// Given an integer n find all unique binary search trees which can have nodes from 1 to n.
// This problem is also a catalan number solution.
// Recursive Approach : Time Complexity : (Written in notes), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : O(n).
// Bottom Up Approach : Time Complexity : O(n^2), Space Complexity : O(n);
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(int n){
    // Base Case.
    if(n <= 1){
        return 1;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += solveRecursively(i-1) * solveRecursively(n-i);
    }

    return ans;
}

int solveTopDownMemo(int n, vector<int> &dp){
    // Base Case.
    if(n <= 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += solveTopDownMemo(i-1, dp) * solveTopDownMemo(n-i, dp);
    }

    return dp[n] = ans;
}

int solveBottomUp(int &n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the total number of nodes"<<endl;
    cin>>n;

    // Recursive Approach.
    // int ans = solveRecursively(n);

    // Top Down Memoization Approach.
    // vector<int> dp(n+1, -1);
    // int ans = solveTopDownMemo(n, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(n);

    cout<<"Possible unique BSTs are : "<<ans<<endl;

    return 0;
}