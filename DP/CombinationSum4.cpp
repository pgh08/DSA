// Given a array of inetegers and target. Calculate the number of different ways in which target can be made using array elements.
// Recursive Solution : Time Complexity : O(n*target), Space Complexity : O(target) + O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(target) + O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(target).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &nums, int target, int n){
    // Base Case.
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += solveRecursively(nums, target-nums[i], n);
    }

    return ans;
}

int solveTopDownMemo(vector<int> &nums, int target, int n, vector<unsigned long long> &dp){
    // Base Case.
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }
    if(dp[target] != -1){
        return dp[target];
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += solveTopDownMemo(nums, target-nums[i], n, dp);
    }

    dp[target] = ans;

    return dp[target];
}

int solveBottomUp(vector<int> &nums, int target, int n){
    // Initializing dp array.
    vector<unsigned long long> dp(target+1, 0);
    
    // Initialization of base case.
    dp[0] = 1;

    for(int i=1; i<=target; i++){
        for(int j=0; j<n; j++){
            if((i-nums[j] >= 0)){
                dp[i] += dp[i-nums[j]];
            }
        }
    }

    return dp[target];
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 3.

    vector<int> nums(n);
    cout<<"Enter the array elements seperated by space"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 1 2 5.
    }

    int target;
    cout<<"Enter the value of target"<<endl;
    cin>>target; // 5.

    // Recursive Approach.
    // int ans = solveRecursively(nums, target, n); // 9.

    // Top Down Memoization Approach.
    // vector<unsigned long long> dp(target+1, -1);
    // int ans = solveTopDownMemo(nums, target, n, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(nums,target, n);
    
    cout<<"Different ways to reach the target is : "<<ans<<endl;

    return 0;
}