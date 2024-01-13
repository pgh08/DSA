// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Recursive Approach : Time Complexity : O(2^(2n)), Space Complexity : O(n^2).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : (n^2).
// Bottom Up Approach : Time Complexity : O(n^2), Space Complexity : O(n^2).
// Space Optimized Approach : Time Complexity : O(n^2), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveRecursively(string text1, string text2, int &n, int index1, int index2){
    // Base Case.
    if(index1 >= n || index2 >= n){
        return 0;
    }

    int ans = 0;
    if(text1[index1] == text2[index2]){
        ans = 1 + solveRecursively(text1, text2, n, index1+1, index2+1);
    }
    else{
        ans = max(solveRecursively(text1, text2, n, index1+1, index2), solveRecursively(text1, text2, n, index1, index2+1));
    }

    return ans;
}

int solveTopDownMemo(string text1, string text2, int &n, int index1, int index2, vector<vector<int>> &dp){
    // Base Case.
    if(index1 >= n || index2 >= n){
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    int ans = 0;
    if(text1[index1] == text2[index2]){
        ans = 1 + solveTopDownMemo(text1, text2, n, index1+1, index2+1, dp);
    }
    else{
        ans = max(solveTopDownMemo(text1, text2, n, index1+1, index2, dp), solveTopDownMemo(text1, text2, n, index1, index2+1, dp));
    }

    return dp[index1][index2] = ans;
}

int solveBottomUp(string text1, string text2, int &n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int index1=n-1; index1>=0; index1--){
        for(int index2=n-1; index2>=0; index2--){

            int ans = 0;
            if(text1[index1] == text2[index2]){
                ans = 1 + dp[index1+1][index2+1];
            }
            else{
                ans = max(dp[index1+1][index2], dp[index1][index2+1]);
            }
            dp[index1][index2] = ans;
        }
    }

    return dp[0][0];
}

int solveSpaceOptimized(string text1, string text2, int &n){
    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int index1=n-1; index1>=0; index1--){
        for(int index2=n-1; index2>=0; index2--){

            int ans = 0;
            if(text1[index1] == text2[index2]){
                ans = 1 + next[index2+1];
            }
            else{
                ans = max(next[index2], curr[index2+1]);
            }
            curr[index2] = ans;
        }
        next = curr;
    }

    return next[0];
}

int main()
{
    string s;
    cout<<"Enter the value of string s"<<endl;
    cin>>s; // bbbab

    // Step 1 : Reverse the string.
    string text2 = s;
    reverse(begin(text2), end(text2));

    // Step 2 : Perform Longest Common Subsequence.
    int n = s.length();
    
    // Recursive Approach.
    // int ans = solveRecursively(s, text2, n, 0, 0);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(s, text2, n, 0, 0, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(s, text2, n);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(s, text2, n);

    cout<<"Longest Palindromic Subsequence length is : "<<ans<<endl; // 4.

    return 0;
}