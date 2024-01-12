// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Recursive Approach : Time Complexity : O(2^n*k), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2*k), Space Complexity : (n*2*k).
// Bottom Up Approach : Time Complexity : O(n*2*k), Space Complexity : O(n*2*k).
// Space Optimized Approach : Time Complexity : O(n*2*k), Space Complexity : O(2*k).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(vector<int> &prices, int &n, int index, int buy, int k){
    // Base Case.
    if(index >= n || k == 0){
        return 0;
    }

    int profit = 0;
    if(buy){
        profit = max(-prices[index]+solveRecursively(prices, n, index+1, 0, k), solveRecursively(prices, n, index+1, 1, k));
    }
    else{
        profit = max(prices[index]+solveRecursively(prices, n, index+1, 1, k-1), solveRecursively(prices, n, index+1, 0, k));
    }

    return profit;
}

int solveTopDownMemo(vector<int> &prices, int &n, int index, int buy, int k, vector<vector<vector<int>>> &dp){
    // Base Case.
    if(index >= n || k == 0){
        return 0;
    }
    if(dp[index][buy][k] != -1){
        return dp[index][buy][k];
    }

    int profit = 0;
    if(buy){
        profit = max(-prices[index]+solveTopDownMemo(prices, n, index+1, 0, k, dp), solveTopDownMemo(prices, n, index+1, 1, k, dp));
    }
    else{
        profit = max(prices[index]+solveTopDownMemo(prices, n, index+1, 1, k-1, dp), solveTopDownMemo(prices, n, index+1, 0, k, dp));
    }

    return dp[index][buy][k] = profit;
}

int solveBottomUp(vector<int> &prices, int &n, int &k){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            for(int limit=1; limit<=k; limit++){
                
                int profit = 0;
                if(buy){
                    profit = max(-prices[index]+dp[index+1][0][limit], dp[index+1][1][limit]);
                }
                else{
                    profit = max(prices[index]+dp[index+1][1][limit-1], dp[index+1][0][limit]);
                }

                dp[index][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][k];
}

int solveSpaceOptimized(vector<int> &prices, int &n, int k){
    vector<vector<int>> next(2, vector<int> (k+1, 0));
    vector<vector<int>> curr(2, vector<int> (k+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            for(int limit=1; limit<=k; limit++){
                
                int profit = 0;
                if(buy){
                    profit = max(-prices[index]+next[0][limit], next[1][limit]);
                }
                else{
                    profit = max(prices[index]+next[1][limit-1], next[0][limit]);
                }

                curr[buy][limit] = profit;
            }
            next = curr;
        }
    }

    return next[1][k];
}

int main()
{
    int n, k;
    cout<<"Enter the size of the array and value of k"<<endl;
    cin>>n>>k; // 6, 2.

    vector<int> prices(n, 0);
    cout<<"Enter the price of stocks on each day"<<endl;
    for(int i=0; i<n; i++){
        cin>>prices[i]; // [3,2,6,5,0,3].
    }

    // Recursive Approach.
    // int ans = solveRecursively(prices, n, 0, 1, k);

    // Top Down Memoization Approach.
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
    // int ans = solveTopDownMemo(prices, n, 0, 1, k, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(prices, n, k);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(prices, n, k);

    cout<<"Maximum profit can be : "<<ans<<endl; // 7.

    return 0;
}