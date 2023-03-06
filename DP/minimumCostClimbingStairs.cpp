// Given the number of stairs and cost for climbing each stair find the minimum cost using which we can reach the top.
// 1. Rcursive Solution : Time Complexity : O(n^2), Space Complexity : O(n).
// 2. Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// 3. Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// 4. Space Optimized Approach : TIme Complexity : O(n), Space Complexity : O(1). 
#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &cost, int n){
    //Base case.
    if(n <= 1){
        return cost[n];
    }
    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

int topDownMinimumCost(vector<int> &cost, int n, vector<int> &dp){
    // Base Case.
    if(n <= 1){
        return dp[n] = cost[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = cost[n] + min(topDownMinimumCost(cost, n-1, dp), topDownMinimumCost(cost, n-2, dp));
    return dp[n];
}

int bottomUpMinCost(vector<int> &cost, int n){
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=0; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int spaceOptimizedCost(vector<int> &cost, int n){
    int twoBack = cost[0];
    int oneBack = cost[1];

    for(int i=2; i<n; i++){
        int curr = cost[i] + min(oneBack,twoBack);

        // Shifting logic.
        twoBack = oneBack;
        oneBack = curr;
    }
    return min(oneBack, twoBack);
}

int main()
{
    int n;
    cout<<"Enter the number of stairs"<<endl;
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter the cost for climbing each stairs"<<endl;
    // 1 100 1 1 1 100 1 1 100 1. ans = 6.
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }

    // int recursiveSolution = min(solve(cost, n-1), solve(cost, n-2));

    // vector<int> dp(n+1, -1);
    
    // int ans1 = min(topDownMinimumCost(cost, n-1, dp), topDownMinimumCost(cost, n-2, dp));

    // int ans2 = bottomUpMinCost(cost, n);

    int ans3 = spaceOptimizedCost(cost, n);

    cout<<"Minimum cost to climb the stairs is : "<<ans3<<endl;

    return 0;
}