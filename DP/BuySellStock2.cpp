// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : (n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
// Intutive Approach : (We Only Buy if previous day's price is lower), Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &prices, int &n, int index, int buy){
    // Base Case.
    if(index >= n){
        return 0;
    }

    int profit = 0;
    if(buy){
        // Buy Stock.
        int buy = -prices[index] + solveRecursively(prices, n, index+1, 0);
        // Skip Current Stock.
        int notBuy = 0 + solveRecursively(prices, n, index+1, 1);

        profit = max(profit+buy, notBuy);
    }
    else{
        // Sell Stock.
        int sell = prices[index] + solveRecursively(prices, n, index+1, 1);
        // Skip Current Stock.
        int notSell = 0 + solveRecursively(prices, n, index+1, 0);

        profit = max(profit+sell, notSell);
    }

    return profit;
}

int solveTopDownMemo(vector<int> &prices, int &n, int index, int buy, vector<vector<int>> &dp){
    // Base Case.
    if(index >= n){
        return 0;
    }
    if(dp[index][buy] != -1){
        return dp[index][buy];
    }

    int profit = 0;
    if(buy){
        // Buy Stock.
        int buy = -prices[index] + solveTopDownMemo(prices, n, index+1, 0, dp);
        // Skip Current Stock.
        int notBuy = 0 + solveTopDownMemo(prices, n, index+1, 1, dp);

        profit = max(profit+buy, notBuy);
    }
    else{
        // Sell Stock.
        int sell = prices[index] + solveTopDownMemo(prices, n, index+1, 1, dp);
        // Skip Current Stock.
        int notSell = 0 + solveTopDownMemo(prices, n, index+1, 0, dp);

        profit = max(profit+sell, notSell);
    }

    return dp[index][buy] = profit;
}

int solveBottomUp(vector<int> &prices, int &n){
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            
            int profit = 0;
            if(buy){
                profit = max(-prices[index]+dp[index+1][0], dp[index+1][1]);
            }
            else{
                profit = max(prices[index]+dp[index+1][1], dp[index+1][0]);
            }
            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

int solveSpaceOptimized(vector<int> &prices, int &n){
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            
            int profit = 0;
            if(buy){
                profit = max(-prices[index]+next[0], next[1]);
            }
            else{
                profit = max(prices[index]+next[1], next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}

int solveIntutive(vector<int> &prices, int &n){
    int profit = 0;

    for(int i=1; i<n; i++){
        if(prices[i] > prices[i-1]){
            profit += prices[i]-prices[i-1];
        }
    }

    return profit;
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 6.

    vector<int> prices(n, 0);
    cout<<"Enter the price of stocks on each day"<<endl;
    for(int i=0; i<n; i++){
        cin>>prices[i]; // [7,1,5,3,6,4].
    }

    // Recursive Approach.
    // int ans = solveRecursively(prices, n, 0, 1);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (2, -1));
    // int ans = solveTopDownMemo(prices, n, 0, 1, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(prices, n);

    // Space Optimized Approach.
    // int ans = solveSpaceOptimized(prices, n);

    // Intutive Approach.
    int ans = solveIntutive(prices, n);

    cout<<"Maximum profit can be : "<<ans<<endl; // 7.

    return 0;
}