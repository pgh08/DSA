// Given a array of integers which represents the vertices of the polygon, find the minimum triangulation of that polygon.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n^2).
// Top Down Memoization Approach : Time Complexity : O(n^3), Space Complexity : O(n^2) + O(n^2).
// Bottom Up Approach : Time Complexity : O(n^3), Space Complexity : O(n^2).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(vector<int> &values, int i, int j){
    // Base Case.
    if(i+1 == j){
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i+1; k<j; k++){
        ans = min(ans, values[i]*values[j]*values[k] + solveRecursively(values, i, k) + solveRecursively(values, k, j));
    }

    return ans;
}

int solveTopDownMemo(vector<int> &values, int i, int j, vector<vector<int>> &dp){
    // Base Case.
    if(i+1 == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;

    for(int k=i+1; k<j; k++){
        ans = min(ans, values[i]*values[j]*values[k] + solveTopDownMemo(values, i, k, dp) + solveTopDownMemo(values, k, j, dp));
    }

    return dp[i][j] = ans;
}

int solveBottomUp(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int i=n-1; i>=0; i--){
        for(int j=i+2; j<n; j++){

            int ans = INT_MAX;

            for(int k=i+1; k<j; k++){
                ans = min(ans, values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n-1];
}

int main()
{
    int n;
    cout<<"Enter the size of the polygon"<<endl;
    cin>>n; // 6.

    vector<int> values(n);
    cout<<"Enter the value of each vertices in the polygon"<<endl;
    for(int i=0; i<n; i++){
        cin>>values[i]; // 1 3 1 4 1 5.
    }

    // Recursive Appraoch.
    // int ans = solveRecursively(values, 0, n-1);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n, vector<int> (n, -1));
    // int ans = solveTopDownMemo(values, 0, n-1, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(values);

    cout<<"Minimum Triangulation is : "<<ans<<endl;

    return 0;
}