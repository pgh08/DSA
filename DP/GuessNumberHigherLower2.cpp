// Given the number n guess the number which have to match with picked number. If not equal to picked number pay that many amount of money.
// You should guess so that you have to minimize the amount and win the game. (DP + Merge Interval Pattern).
// Recursive Approach : Time Complexity : O(n!), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^3), Space Complexity : (n^2).
// Bottom Up Approach : Time Complexity : O(n^3), Space Complexity : O(n^2).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(int start, int end){
    // Base Case.
    if(start >= end){
        return 0;
    }

    int mini = INT_MAX;
    for(int i=start; i<=end; i++){
        mini = min(mini, i+max(solveRecursively(start, i-1), solveRecursively(i+1, end)));
    }

    return mini;
}

int solveTopDownMemo(int start, int end, vector<vector<int>> &dp){
    // Base Case.
    if(start >= end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int mini = INT_MAX;
    for(int i=start; i<=end; i++){
        mini = min(mini, i+max(solveTopDownMemo(start, i-1, dp), solveTopDownMemo(i+1, end, dp)));
    }

    return dp[start][end] = mini;
}

int solveBottomUp(int &n){
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    for(int start=n; start>=1; start--){
        for(int end=start; end<=n; end++){
            if(start == end){
                continue;
            }
            else{
                int mini = INT_MAX;
                for(int i=start; i<=end; i++){
                    mini = min(mini, i+max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = mini;
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n; // 10.

    // Recursive Approach.
    // int ans = solveRecursively(1, n);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(1, n, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(n);
    cout<<"Minimum amount to spend to win the game is : "<<ans<<endl; // 16.

    return 0;
}