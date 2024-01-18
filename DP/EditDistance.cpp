// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
//   -> Insert a character.
//   -> Delete a character.
//   -> Replace a character.

// Recursive Approach : Time Complexity : O(3^(n1+n2)), Space Complexity : O(n1+n2).
// Top Down Memoization Approach : Time Complexity : O(n1*n2), Space Complexity : O(n1*n2).
// Bottom Up Approach : Time Complexity : O(n1*n2), Space Complexity : O(n1*n2).
// Space Optimized Approach : Time Complexity : O(n1*n2), Space Complexity : O(n2).
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(string &word1, string &word2, int &n1, int &n2, int index1, int index2){
    // Base Case.
    if(index1 == n1){
        return n2-index2;
    }
    if(index2 == n2){
        return n1-index1;
    }

    int ans = 0;
    if(word1[index1] == word2[index2]){
        return solveRecursively(word1, word2, n1, n2, index1+1, index2+1);
    }
    else{
        // Insertion.
        int insert = 1 + solveRecursively(word1, word2, n1, n2, index1, index2+1);

        // Deletion.
        int del = 1 + solveRecursively(word1, word2, n1, n2, index1+1, index2);

        // Replace.
        int replace = 1 + solveRecursively(word1, word2, n1, n2, index1+1, index2+1);

        ans = min(insert, min(del, replace));
    }

    return ans;
}

int solveTopDownMemo(string &word1, string &word2, int &n1, int &n2, int index1, int index2, vector<vector<int>> &dp){
    // Base Case.
    if(index1 == n1){
        return n2-index2;
    }
    if(index2 == n2){
        return n1-index1;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    int ans = 0;
    if(word1[index1] == word2[index2]){
        return solveTopDownMemo(word1, word2, n1, n2, index1+1, index2+1, dp);
    }
    else{
        // Insertion.
        int insert = 1 + solveTopDownMemo(word1, word2, n1, n2, index1, index2+1, dp);

        // Deletion.
        int del = 1 + solveTopDownMemo(word1, word2, n1, n2, index1+1, index2, dp);

        // Replace.
        int replace = 1 + solveTopDownMemo(word1, word2, n1, n2, index1+1, index2+1, dp);

        ans = min(insert, min(del, replace));
    }

    return dp[index1][index2] = ans;
}

int solveBottomUp(string &word1, string &word2, int &n1, int &n2){
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

    // Analysing Base Case.
    for(int i=0; i<n2; i++){
        dp[n1][i] = n2-i;
    }
    for(int i=0; i<n1; i++){
        dp[i][n2] = n1-i;
    }

    for(int index1=n1-1; index1>=0; index1--){
        for(int index2=n2-1; index2>=0; index2--){
            
            if(word1[index1] == word2[index2]){
                dp[index1][index2] = dp[index1+1][index2+1];
            }
            else{
                // Insertion.
                int insert = 1 + dp[index1][index2+1];

                // Deletion.
                int del = 1 + dp[index1+1][index2];

                // Replace.
                int replace = 1 + dp[index1+1][index2+1];

                dp[index1][index2] = min(insert, min(del, replace));
            }
        }
    }

    return dp[0][0];
}

int solveSpaceOptimized(string &word1, string &word2, int &n1, int &n2){
    vector<int> next(n2+1, 0);
    vector<int> curr(n2+1, 0);

    // Analysing Base Case.
    for(int i=0; i<n2; i++){
        next[i] = n2-i;
    }

    for(int index1=n1-1; index1>=0; index1--){
        for(int index2=n2-1; index2>=0; index2--){

            curr[n2] = n1-index1;
            
            if(word1[index1] == word2[index2]){
                curr[index2] = next[index2+1];
            }
            else{
                // Insertion.
                int insert = 1 + curr[index2+1];

                // Deletion.
                int del = 1 + next[index2];

                // Replace.
                int replace = 1 + next[index2+1];

                curr[index2] = min(insert, min(del, replace));
            }
        }
        next = curr;
    }

    return next[0];
}

int main()
{
    string word1, word2;
    cout<<"Enter  the value of the word1 and word2"<<endl;
    cin>>word1>>word2; // horse, ros.

    int n1 = word1.length();
    int n2 = word2.length();

    // Recursive Appraoch.
    // int ans = solveRecursively(word1, word2, n1, n2, 0, 0);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
    // int ans = solveTopDownMemo(word1, word2, n1, n2, 0, 0, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(word1, word2, n1, n2);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(word1, word2, n1, n2);

    cout<<"Minimum number of operations required are : "<<ans<<endl; // 3.

    return 0;
}