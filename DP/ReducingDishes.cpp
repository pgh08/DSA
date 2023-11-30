// Given the array of satisfaction. Find maximum Like-time co-efficient. (Like-time co-efficient = time[i] * satisfaction[i]). You can exclude satisfaction elements if needed.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : O(n^2).
// Bottom Up Approach : Time Complexity : O(n^2), Space Complexity : O(n^2).
// Space Optimized Approach : Time Complexity : O(n^2), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveRecursively(vector<int> &satisfaction, int index, int time, int &n){
    // Base Case.
    if(index == n){
        return 0;
    }

    int include = satisfaction[index] * (time+1) + solveRecursively(satisfaction, index+1, time+1, n);

    int exclude = 0 + solveRecursively(satisfaction, index+1, time, n);

    return max(include, exclude);
}

int solveTopDownMemo(vector<int> &satisfaction, int index, int time, int &n, vector<vector<int>> &dp){
    // Base Case.
    if(index == n){
        return 0;
    }

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int include = satisfaction[index] * (time+1) + solveTopDownMemo(satisfaction, index+1, time+1, n, dp);

    int exclude = 0 + solveTopDownMemo(satisfaction, index+1, time, n, dp);

    return dp[index][time] = max(include, exclude);
}

int solveBottomUp(vector<int> &satisfaction, int &n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int time=index; time>=0; time--){

            int include = satisfaction[index] * (time+1) + dp[index+1][time+1];

            int exclude = 0 + dp[index+1][time];

            dp[index][time] = max(include,exclude);
        }
    }

    return dp[0][0];
}

int solveSpaceOptimized(vector<int> &satisfaction, int &n){
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int index=n-1; index>=0; index--){
        for(int time=n-1; time>=0; time--){
            
            int include = satisfaction[index] * (time+1) + next[time+1];

            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }

        next = curr;
    }

    return next[0];
}

int main()
{
    int n;
    cout<<"Enter the size of satisfaction array"<<endl;
    cin>>n;

    vector<int> satisfaction(n);
    cout<<"Enter the value of Satifaction array seperated by space"<<endl; //-1 -8 0 5 -9.
    for(int i=0; i<n; i++){
        cin>>satisfaction[i];
    }

    // Sorting satisfaction array before hand. (Applys for all approachs).
    sort(satisfaction.begin(), satisfaction.end());

    // Recursive Approach.
    // int index = 0;
    // int time = 0;
    // int ans = solveRecursively(satisfaction, index, time, n);

    // Top Down Memoization Approach.
    // int index = 0;
    // int time = 0;
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(satisfaction, index, time, n, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(satisfaction, n);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(satisfaction, n);

    cout<<"Maximum Value of Like-time co-efficient is : "<<ans<<endl; // 14.

    return 0;
}