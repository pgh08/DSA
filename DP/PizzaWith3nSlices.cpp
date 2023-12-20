// Given the array which signifies the size of pizza slices, find maximum size of pizza you can consume if your adjacent slices are eaten by Alice and Bob.
// Recursive Approach : Time Complexity : O(2^(k*n)), Space Complexity : O(k).
// Top Down Memoization Approach : Time Compleixty : O(k*n), Space Complexity : O(k*n).
// Bottom Up Approach : Time Compleixty : O(k*n), Space Complexity : O(k*n).
// Space Optimized Approach : Time Complexity : O(k*n), Space Complexity : O(n); // Where n = k/3.
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &slices, int endingIndex, int index, int n){
    // Base Case.
    if(n == 0 || index >= endingIndex){
        return 0;
    }

    int take = slices[index] + solveRecursively(slices, endingIndex, index+2, n-1);
    int notTake = 0 + solveRecursively(slices, endingIndex, index+1, n);

    return max(take, notTake);
}

int solveTopDownMemo(vector<int> &slices, int endingIndex, int index, int n, vector<vector<int>> &dp){
    // Base Case.
    if(n == 0 || index >= endingIndex){
        return 0;
    }
    if(dp[index][n] != -1){
        return dp[index][n];
    }

    int take = slices[index] + solveTopDownMemo(slices, endingIndex, index+2, n-1, dp);
    int notTake = 0 + solveTopDownMemo(slices, endingIndex, index+1, n, dp);

    return dp[index][n] = max(take, notTake);
}

int solveBottomUp(vector<int> &slices, int &k, int index, int lastIndex){
    vector<vector<int>> dp(k+2, vector<int> ((k/3)+1, 0));
    
    while(index >= lastIndex){
        for(int n=1; n<=k/3; n++){

            int take = slices[index] + dp[index+2][n-1];
            int notTake = 0 + dp[index+1][n];

            dp[index][n] = max(take, notTake);
        }
        index--;
    }

    return lastIndex == 1 ? dp[1][k/3] : dp[0][k/3];
}

int solveSpaceOptimized(vector<int> &slices, int &k, int index, int lastIndex){
    vector<int> prev((k/3)+1, 0);
    vector<int> curr((k/3)+1, 0);
    vector<int> next((k/3)+1, 0);

    while(index >= lastIndex){
        for(int n=1; n<=k/3; n++){

            int take = slices[index] + next[n-1];
            int notTake = 0 + curr[n];

            prev[n] = max(take, notTake);

        }
        next = curr;
        curr = prev;
        index--;
    }

    return lastIndex == 1 ? next[k/3] : curr[k/3];
}

int main()
{
    int k; // 6. // 12.
    cout<<"Enter the number of slice in pizza"<<endl;
    cin>>k;

    vector<int> slices(k, 0); // [1,2,3,4,5,6]. // [9,5,1,7,8,4,4,5,5,8,7,7].
    cout<<"Enter the size of each slices"<<endl;
    for(int i=0; i<k; i++){
        cin>>slices[i];
    }

    // Recursive Approach.
    // int case1 = solveRecursively(slices, k-1, 0, k/3);
    // int case2 = solveRecursively(slices, k, 1, k/3);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp1(k+2, vector<int> ((k/3)+1, -1));
    // int case1 = solveTopDownMemo(slices, k-1, 0, k/3, dp1);
    // dp1.clear();
    // vector<vector<int>> dp2(k+2, vector<int> ((k/3)+1, -1));
    // int case2 = solveTopDownMemo(slices, k, 1, k/3, dp2);
    // dp2.clear();

    // Bottom Up Approach.
    // int case1 = solveBottomUp(slices, k, k-2, 0);
    // int case2 = solveBottomUp(slices, k, k-1, 1);

    // Space Optimized Approach.
    int case1 = solveSpaceOptimized(slices, k, k-2, 0);
    int case2 = solveSpaceOptimized(slices, k, k-1, 1);
    int ans = max(case1, case2);

    cout<<"Maximum amount of pizza which can be eaten by me is : "<<ans<<endl;

    return 0;
}