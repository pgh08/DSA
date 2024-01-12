// Given an array arr of positive integers, consider all binary trees such that:

//     -> Each node has either 0 or 2 children;
//     -> The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//     -> The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
// It is guaranteed this sum fits into a 32-bit integer.
// A node is a leaf if and only if it has zero children.
// Recursive Approach : Time Complexity : O(n!), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n^3), Space Complexity : (n^2).
// Bottom Up Approach : Time Complexity : O(n^3), Space Complexity : O(n^2).
#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

int solveRecursively(int start, int end, map<pair<int,int>, int> &intervalMax){
    // Base Case.
    if(start == end){
        return 0;
    }

    int ans = INT_MAX;
    for(int partition=start; partition<end; partition++){
        ans = min(ans, intervalMax[{start, partition}]*intervalMax[{partition+1, end}]+solveRecursively(start, partition, intervalMax) + 
                    solveRecursively(partition+1, end, intervalMax));
    }

    return ans;
}

int solveTopDownMemo(int start, int end, map<pair<int,int>, int> &intervalMax, vector<vector<int>> &dp){
    // Base Case.
    if(start == end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int ans = INT_MAX;
    for(int partition=start; partition<end; partition++){
        ans = min(ans, intervalMax[{start, partition}]*intervalMax[{partition+1, end}]+solveTopDownMemo(start, partition, intervalMax, dp)+ 
                  solveTopDownMemo(partition+1, end, intervalMax, dp));
    }

    return dp[start][end] = ans;
}

int solveBottomUp(int &n, map<pair<int,int>, int> &intervalMax){
    vector<vector<int>> dp(n, vector<int> (n, 0));
    
    for(int start=n-1; start>=0; start--){
        for(int end=start; end<n; end++){
            if(start == end){
                continue;
            }
            else{
                int ans = INT_MAX;
                for(int partition=start; partition<end; partition++){
                    ans = min(ans, intervalMax[{start, partition}]*intervalMax[{partition+1, end}]+dp[start][partition]+dp[partition+1][end]);
                }
                dp[start][end] = ans;
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    vector<int> nums(n, 0);
    cout<<"Enter the values of leaf node in inorder traversal order"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // Step 1 : Get maximum of all possible interval combinations.
    map<pair<int,int>, int> intervalMax;
    
    for(int i=0; i<n; i++){
        intervalMax[{i,i}] = nums[i];
        for(int j=i+1; j<n; j++){
            intervalMax[{i, j}] = max(intervalMax[{i, j-1}], nums[j]);
        }
    }

    // Printing interval maximums.
    // for(auto pr : intervalMax){
    //     cout<<"["<<pr.first.first<<","<<pr.first.second<<"]"<<"  -->  "<<pr.second<<endl;
    // }

    // Recursive Approach.
    // int ans = solveRecursively(0, n-1, intervalMax);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(0, n-1, intervalMax, dp);

    // Bottom Up Approach.
    int ans = solveBottomUp(n, intervalMax);

    cout<<"Smallest possible sum of non-leaf node is : "<<ans<<endl;

    return 0;
}