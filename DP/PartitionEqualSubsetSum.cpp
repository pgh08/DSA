// Given an array of integers find whether it can be divided into subset of equal sum.
// Intution : Since we should divide array into 2 subset, sum of the array should be even so that when we do sum/2 we don't get fraction.
//            Odd sum means we can't divide the array into 2 equal subsets.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n*target), Space Complexity : O(n*target).
// Bottom Up Approach : Time Complexity : O(n*target), Space Complexity : O(n*target).
// Space Optimized Approach : Time Complexity : O(n*target), Space Complexity : O(target).
#include<iostream>
#include<vector>
using namespace std;

bool solveRecursively(vector<int> &nums, int &n, int index, int target){
    // Base Case.
    if(index >= n){
        if(target == 0){
            return true;
        }
        return false;
    }
    if(target < 0){
        return false;
    }

    bool take = solveRecursively(nums, n, index+1, target-nums[index]);
    bool notTake = solveRecursively(nums, n, index+1, target);

    return take || notTake;
}

bool solveTopDownMemo(vector<int> &nums, int &n, int index, int target, vector<vector<int>> &dp){
    // Base Case.
    if(index >= n){
        if(target == 0){
            return true;
        }
        return false;
    }
    if(target < 0){
        return false;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool take = solveTopDownMemo(nums, n, index+1, target-nums[index], dp);
    bool notTake = solveTopDownMemo(nums, n, index+1, target, dp);

    return dp[index][target] = take || notTake;
}

bool solveBottomUp(vector<int> &nums, int &n, int target){
    vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));

    // Analysing the base case.
    dp[n][0] = true;

    for(int index=n-1; index>=0; index--){
        for(int t=0; t<=target; t++){

            bool take = false;
            if(t-nums[index] >= 0){
                take = dp[index+1][t-nums[index]];
            }
            bool notTake = dp[index+1][t];

            dp[index][t] = take || notTake;
        }
    }

    return dp[0][target];
}

bool solveSpaceOptimized(vector<int> &nums, int &n, int target){
    vector<bool> next(target+1, false);
    vector<bool> curr(target+1, false);

    // Analysing the base case.
    next[0] = true;

    for(int index=n-1; index>=0; index--){
        for(int t=0; t<=target; t++){

            bool take = false;
            if(t-nums[index] >= 0){
                take = next[t-nums[index]];
            }
            bool notTake = next[t];

            curr[t] = take || notTake;
        }
        next = curr;
    }

    return curr[target];
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 4.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 1 5 11 5.
    }

    // Step 1 : Checking whether the sum is odd or even.
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }

    int target = 0;
    if(sum%2 != 0){
        cout<<"Array cannot be divided into 2 equal subsets"<<endl;
        return 0;
    }
    else{
        target = sum/2;
    }

    // Recursive Approach.
    // bool ans = solveRecursively(nums, n, 0, target);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    // bool ans = solveTopDownMemo(nums, n, 0, target, dp);

    // Bottom Up Approach.
    // bool ans = solveBottomUp(nums, n, target);

    // Space Optimized Approach.
    bool ans = solveSpaceOptimized(nums, n, target);

    if(ans){
        cout<<"Array can be divided into 2 equal subsets"<<endl;
    }
    else{
        cout<<"Array cannot be divided into 2 equal subsets"<<endl;
    }

    return 0;
}