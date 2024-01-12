// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : (n*2*3).
// Bottom Up Approach : Time Complexity : O(n*2*3), Space Complexity : O(n*2*3).
// Space Optimized Approach : Time Complexity : O(n*2*3), Space Complexity : O(2*3).
// Intutive Approach : (After selling stock one the profit made is extra money so use that to buy stock 2), Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(vector<int> &prices, int &n, int index, int buy, int limit){
    // Base Case.
    if(index >= n || limit == 0){
        return 0;
    }

    int profit = 0;
    if(buy){
        profit = max(-prices[index]+solveRecursively(prices, n, index+1, 0, limit), solveRecursively(prices, n, index+1, 1, limit));
    }
    else{
        profit = max(prices[index]+solveRecursively(prices, n, index+1, 1, limit-1), solveRecursively(prices, n, index+1, 0, limit));
    }

    return profit;
}

int solveTopDownMemo(vector<int> &prices, int &n, int index, int buy, int limit, vector<vector<vector<int>>> &dp){
    // Base Case.
    if(index >= n || limit == 0){
        return 0;
    }
    if(dp[index][buy][limit] != -1){
        return dp[index][buy][limit];
    }

    int profit = 0;
    if(buy){
        profit = max(-prices[index]+solveTopDownMemo(prices, n, index+1, 0, limit, dp), solveTopDownMemo(prices, n, index+1, 1, limit, dp));
    }
    else{
        profit = max(prices[index]+solveTopDownMemo(prices, n, index+1, 1, limit-1, dp), solveTopDownMemo(prices, n, index+1, 0, limit, dp));
    }

    return dp[index][buy][limit] = profit;
}

int solveBottomUp(vector<int> &prices, int &n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            for(int limit=1; limit<3; limit++){
                
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

    return dp[0][1][2];
}

int solveSpaceOptimized(vector<int> &prices, int &n){
    vector<vector<int>> next(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<2; buy++){
            for(int limit=1; limit<3; limit++){
                
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

    return next[1][2];
}

int solveIntutive(vector<int> &prices){
    int firstBuy = INT_MAX;
    int profitFormFirstBuy = 0;
    int secondBuy = INT_MAX;
    int profitFormSecondBuy = 0;

    for(auto currPrice : prices){
        firstBuy = min(firstBuy, currPrice);
        profitFormFirstBuy = max(profitFormFirstBuy, currPrice-firstBuy);
        secondBuy = min(secondBuy, currPrice-profitFormFirstBuy);
        profitFormSecondBuy = max(profitFormSecondBuy, currPrice-secondBuy);
    }

    return profitFormSecondBuy;
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 8.

    vector<int> prices(n, 0);
    cout<<"Enter the price of stocks on each day"<<endl;
    for(int i=0; i<n; i++){
        cin>>prices[i]; // [3,3,5,0,0,3,1,4].
    }

    // Recursive Approach.
    // int ans = solveRecursively(prices, n, 0, 1, 2);

    // Top Down Memoization Approach.
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
    // int ans = solveTopDownMemo(prices, n, 0, 1, 2, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(prices, n);

    // Space Optimized Approach.
    // int ans = solveSpaceOptimized(prices, n);

    // Intutive Approach.
    int ans = solveIntutive(prices);

    cout<<"Maximum profit can be : "<<ans<<endl; // 6.

    return 0;
}