// Given an array find maximum sum of non ajacent nodes. Similar to house robery pf leetcode.
// Recursive Approach : Time Comaplextiy : O(n^2), space Complexity : O(n).
// Top Down Memoization Approach : Time Comaplextiy : O(n), space Complexity : O(n).
// Bottom Up Approach : Time Comaplextiy : O(n), space Complexity : O(n).
// Space Optimized Approach : Time Comaplextiy : O(n), space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &nums, int n){
    // Base Case.
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[n];
    }
    // Include the index for sum.
    int Include = solveRecursively(nums, n-2) + nums[n];
    int Exclude = solveRecursively(nums, n-1);

    return max(Include, Exclude);
}

int solveTopDownMemo(vector<int> &nums, int n, vector<int> &dp){
    // Base Case.
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int Include = solveTopDownMemo(nums, n-2, dp) + nums[n];
    int Exclude = solveTopDownMemo(nums, n-1, dp);

    // Memoization.
    dp[n] = max(Include, Exclude);

    return dp[n];
}

int solveBottomUp(vector<int> &nums, int n){
    // Worst case n is less then zero for which we returned zero in top down memoization approach.
    vector<int> dp(n, 0);

    //Resolving Base Case.
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        // Resolving Recursive call.
        int Include = dp[i-2] + nums[i];
        int Exclude = dp[i-1];

        dp[i] = max(Include, Exclude);
    }

    return dp[n-1];
}

int solveSpaceOptimized(vector<int> &nums, int n){
    int twoBack = 0;
    int oneBack = nums[0];

    for(int i=1; i<n; i++){
        int Include = twoBack + nums[i];
        int Exclude = oneBack;

        // Storing ans.
        int ans = max(Include, Exclude);

        // Shifting Logic.
        twoBack = oneBack;
        oneBack = ans;
    }
    return oneBack;
}

int main()
{
    int n;
    cout<<"Enter the number of eleements in the array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the array elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // Recursive Approach.
    // int ans = solveRecursively(nums, n-1);

    // Top Down Memoization Approach.
    // vector<int> dp(n, -1);
    // int ans1 = solveTopDownMemo(nums, n-1, dp);

    // Bottom Up Approach.
    // int ans2 = solveBottomUp(nums, n);

    // Space Optimized Approach.
    int ans3 = solveSpaceOptimized(nums, n);

    cout<<"Maximum Sum of adjacent node is : "<<ans3<<endl;

    return 0;
}