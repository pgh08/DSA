// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

// Recursive Approach: Time Complexity : O(2^n), Spcae Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^2), Space Complexity : O(n) + O(n).
// Greedy Approach : Time Complexity : O(n*log(n)), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int solveRecursively(vector<vector<int>> &pairs, int &n, int i){
    // Base Case.
    if(i >= n){
        return 0;
    }
    int ans = 1;
    for(int j=i+1; j<n; j++){
        if(pairs[i][1] < pairs[j][0]){
            ans = max(ans, 1+solveRecursively(pairs, n, j));
        }
    }

    return ans;
}

int solveTopDownMemo(vector<vector<int>> &pairs, int &n, int i, vector<int> &dp){
    // Base Case.
    if(i >= n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    dp[i] = 1;
    for(int j=i+1; j<n; j++){
        if(pairs[i][1] < pairs[j][0]){
            dp[i] = max(dp[i], 1+solveTopDownMemo(pairs, n, j, dp));
        }
    }

    return dp[i];
}

int main()
{
    int n;
    cout<<"Enter the size of the pairs array"<<endl;
    cin>>n;

    vector<vector<int>> pairs(n, vector<int> (2, 0));
    cout<<"Enter the element of the array"<<endl;

    for(int i=0; i<n; i++){
        cin>>pairs[i][0]>>pairs[i][1];
    }

    // sort(pairs.begin(), pairs.end());

    // Recursive Approach.
    // int ans = solveRecursively(pairs, n, 0);

    // Top Dowm Memoization Approach.
    // vector<int> dp(n+1, -1);
    // int ans = solveTopDownMemo(pairs, n, 0, dp);

    // cout<<"Maximum Length of pairs chains is : "<<ans<<endl;

    // Greedy Approach.

    // Sort pairs in ascending order based on the second element.
    sort(pairs.begin(), pairs.end(),[](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int curr = INT_MIN, ans = 0;

    for (const auto& pair : pairs) {
        if (pair[0] > curr) {
            ans++;
            curr = pair[1];
        }
    }

    cout<<"Maximum Length of pairs chains is : "<<ans<<endl;

    return 0;
}