// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note: -> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//       -> The transaction fee is only charged once for each stock purchase and sale.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : (n*2).
// Bottom Up Approach : Time Complexity : O(n*2), Space Complexity : O(n*2).
// Space Optimized Approach : Time Complexity : O(n*2), Space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &prices, int &n, int index, int buy, int &fee){
    // Base Case.
    if(index >= n){
        return 0;
    }

    int profit = 0;
    if(buy){
        // Buy Stock.
        int buy = -prices[index] + solveRecursively(prices, n, index+1, 0, fee);
        // Skip Current Stock.
        int notBuy = 0 + solveRecursively(prices, n, index+1, 1, fee);

        profit = max(profit+buy, notBuy);
    }
    else{
        // Sell Stock.
        int sell = prices[index] + solveRecursively(prices, n, index+1, 1, fee) - fee;
        // Skip Current Stock.
        int notSell = 0 + solveRecursively(prices, n, index+1, 0, fee);

        profit = max(profit+sell, notSell);
    }

    return profit;
}

int solveTopDownMemo(vector<int> &prices, int &n, int index, int buy, vector<vector<int>> &dp, int &fee){
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
        int buy = -prices[index] + solveTopDownMemo(prices, n, index+1, 0, dp, fee);
        // Skip Current Stock.
        int notBuy = 0 + solveTopDownMemo(prices, n, index+1, 1, dp, fee);

        profit = max(profit+buy, notBuy);
    }
    else{
        // Sell Stock.
        int sell = prices[index] + solveTopDownMemo(prices, n, index+1, 1, dp, fee) - fee;
        // Skip Current Stock.
        int notSell = 0 + solveTopDownMemo(prices, n, index+1, 0, dp, fee);

        profit = max(profit+sell, notSell);
    }

    return dp[index][buy] = profit;
}

int solveBottomUp(vector<int> &prices, int &n, int &fee){
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            
            int profit = 0;
            if(buy){
                profit = max(-prices[index]+dp[index+1][0], dp[index+1][1]);
            }
            else{
                profit = max(prices[index]+dp[index+1][1]-fee, dp[index+1][0]);
            }
            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

int solveSpaceOptimized(vector<int> &prices, int &n, int &fee){
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            
            int profit = 0;
            if(buy){
                profit = max(-prices[index]+next[0], next[1]);
            }
            else{
                profit = max(prices[index]+next[1]-fee, next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}

int main()
{
    int n, fee;
    cout<<"Enter the size of the array and transaction fee"<<endl;
    cin>>n>>fee; // 6, 2.

    vector<int> prices(n, 0);
    cout<<"Enter the price of stocks on each day"<<endl;
    for(int i=0; i<n; i++){
        cin>>prices[i]; // [1,3,2,8,4,9].
    }

    // Recursive Approach.
    // int ans = solveRecursively(prices, n, 0, 1, fee);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (2, -1));
    // int ans = solveTopDownMemo(prices, n, 0, 1, dp, fee);

    // Bottom Up Approach.
    // int ans = solveBottomUp(prices, n, fee);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(prices, n, fee);

    cout<<"Maximum profit can be : "<<ans<<endl; // 7.

    return 0;
}