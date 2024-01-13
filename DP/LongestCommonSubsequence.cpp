// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//     -> For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Recursive Approach : Time Complexity : O(2^(n1+n2)), Space Complexity : O(n1*n2).
// Top Down Memoization Approach : Time Complexity : O(n1*n2), Space Complexity : (n1*n2).
// Bottom Up Approach : Time Complexity : O(n1*n2), Space Complexity : O(n1*n2).
// Space Optimized Approach : Time Complexity : O(n1*n2), Space Complexity : O(n2).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(string text1, string text2, int &n1, int &n2, int index1, int index2){
    // Base Case.
    if(index1 >= n1 || index2 >= n2){
        return 0;
    }

    int ans = 0;
    if(text1[index1] == text2[index2]){
        ans = 1 + solveRecursively(text1, text2, n1, n2, index1+1, index2+1);
    }
    else{
        ans = max(solveRecursively(text1, text2, n1, n2, index1+1, index2), solveRecursively(text1, text2, n1, n2, index1, index2+1));
    }

    return ans;
}

int solveTopDownMemo(string text1, string text2, int &n1, int &n2, int index1, int index2, vector<vector<int>> &dp){
    // Base Case.
    if(index1 >= n1 || index2 >= n2){
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    int ans = 0;
    if(text1[index1] == text2[index2]){
        ans = 1 + solveTopDownMemo(text1, text2, n1, n2, index1+1, index2+1, dp);
    }
    else{
        ans = max(solveTopDownMemo(text1, text2, n1, n2, index1+1, index2, dp), solveTopDownMemo(text1, text2, n1, n2, index1, index2+1, dp));
    }

    return dp[index1][index2] = ans;
}

int solveBottomUp(string text1, string text2, int &n1, int &n2){
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

    for(int index1=n1-1; index1>=0; index1--){
        for(int index2=n2-1; index2>=0; index2--){

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

int solveSpaceOptimized(string text1, string text2, int &n1, int &n2){
    vector<int> next(n2+1, 0);
    vector<int> curr(n2+1, 0);

    for(int index1=n1-1; index1>=0; index1--){
        for(int index2=n2-1; index2>=0; index2--){

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
    string text1, text2;
    cout<<"Enter string1 and string2 value"<<endl;
    cin>>text1>>text2; // abcde, ace.

    int n1 = text1.length();
    int n2 = text2.length();

    // Recursive Approach.
    // int ans = solveRecursively(text1, text2, n1, n2, 0, 0);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
    // int ans = solveTopDownMemo(text1, text2, n1, n2, 0, 0, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(text1, text2, n1, n2);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(text1, text2, n1, n2);

    cout<<"Longest Common Subsequence length is : "<<ans<<endl; // 3.

    return 0;
}