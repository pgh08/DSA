// Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) 
// i.e., the longest possible subsequence in which the elements of the subsequence are sorted in increasing order. (0/1 kanpsack pattern).
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : O(n^2).
// Bottom Up Approach : Time Complexity : O(n^2), Space Complexity : O(n^2).
// Space Optimized Approach : Time Complexity : O(n^2), Space Complexity : O(n).
// DP + Binary Search Approach : Time Complexity : O(), Space Complexity : O().
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &nums, int index, int prevIndex, int &n){
    // Base Case.
    if(index >= n){
        return 0;
    }

    int take = 0;
    if(prevIndex == -1 || nums[prevIndex] < nums[index]){
        take = 1 + solveRecursively(nums, index+1, index, n);
    }

    int notTake = 0 + solveRecursively(nums, index+1, prevIndex, n);

    return max(take, notTake);
}

int solveTopDownMemo(vector<int> &nums, int index, int prevIndex, int &n, vector<vector<int>> &dp){
    // Base Case.
    if(index >= n){
        return 0;
    }

    if(dp[index][prevIndex+1] != -1){
        return dp[index][prevIndex+1];
    }

    int take = 0;
    if(prevIndex == -1 || nums[prevIndex] < nums[index]){
        take = 1 + solveTopDownMemo(nums, index+1, index, n, dp);
    }

    int notTake = 0 + solveTopDownMemo(nums, index+1, prevIndex, n, dp);

    return dp[index][prevIndex+1] = max(take, notTake);
}

int solveBottomUp(vector<int> &nums, int &n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int prevIndex=index-1; prevIndex>=-1; prevIndex--){
            int take = 0;

            if(prevIndex == -1 || nums[prevIndex] < nums[index]){
                take = 1 + dp[index+1][index+1];
            }

            int notTake = 0 + dp[index+1][prevIndex+1];

            dp[index][prevIndex+1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int solveSpaceOptimized(vector<int> &nums, int &n){
    vector<int> curr(n+1, 0), next(n+1, 0);

    for(int index=n-1; index>=0; index--){
        for(int prevIndex=index-1; prevIndex>=-1; prevIndex--){

            int take = 0;

            if(prevIndex == -1 || nums[prevIndex] < nums[index]){
                take = 1 + next[index+1];
            }

            int notTake = 0 + next[prevIndex+1];

            curr[prevIndex+1] = max(take, notTake);
        }
        next = curr;
    }

    return next[0];
}

int solveDPBinarySearch(vector<int> &nums, int &n){
    if(n == 0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(nums[0]);

    for(int i=1; i<n; i++){
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            // Find the index of next greater element.
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

            ans[index] = nums[i];
        }
    }

    return ans.size();
}

int main()
{
    int n; 
    cout<<"Enter the size of array"<<endl;
    cin>>n; // 6.

    vector<int> nums(n); // [50, 3, 10, 7, 40, 80].
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // Recursive Approach.
    // int ans = solveRecursively(nums, 0, -1, n);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(nums, 0, -1, n, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(nums, n);

    // Space Optimized Approach.
    // int ans = solveSpaceOptimized(nums, n);

    // DP + Binary Search Approach.
    int ans = solveDPBinarySearch(nums, n);

    cout<<"Largest Increasing Subsequence length is : "<<ans<<endl;

    return 0;
}