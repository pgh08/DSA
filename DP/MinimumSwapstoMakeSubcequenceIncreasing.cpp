// Given two arrays of same size find the minimum number of swaps to make 2 arrays in increasing order.
// Recursive Approach : Time Complexity : O(2^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(vector<int> &nums1, vector<int> &nums2, int &n, int index, bool swapped){
    // Base Case.
    if(index >= n){
        return 0;
    }

    int ans = INT_MAX;
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped){
        swap(prev1, prev2);
    }

    if(prev1 < nums1[index] && prev2 < nums2[index]){
        ans = solveRecursively(nums1, nums2, n, index+1, false);
    }

    if(nums1[index] > prev2 && nums2[index] > prev1){
        ans = min(ans, 1+solveRecursively(nums1, nums2, n, index+1, true));
    }

    return ans;
}

int solveTopDownMemo(vector<int> &nums1, vector<int> &nums2, int &n, int index, int swapped, vector<vector<int>> &dp){
    // Base Case.
    if(index >= n){
        return 0;
    }
    if(dp[index][swapped] != -1){
        return dp[index][swapped];
    }

    int ans = INT_MAX;
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped){
        swap(prev1, prev2);
    }

    if(prev1 < nums1[index] && prev2 < nums2[index]){
        ans = solveTopDownMemo(nums1, nums2, n, index+1, 0, dp);
    }

    if(nums1[index] > prev2 && nums2[index] > prev1){
        ans = min(ans, 1+solveTopDownMemo(nums1, nums2, n, index+1, 1, dp));
    }

    return dp[index][swapped] = ans;
}

int solveBottomUp(vector<int> &nums1, vector<int> &nums2, int &n){
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int index=n-1; index>=1; index--){
        for(int swapped=1; swapped>=0; swapped--){

            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped){
                swap(prev1, prev2);
            }

            if(prev1 < nums1[index] && prev2 < nums2[index]){
                ans = dp[index+1][0];
            }

            if(nums1[index] > prev2 && nums2[index] > prev1){
                ans = min(ans, 1+dp[index+1][1]);
            }

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

int solveSpaceOptimized(vector<int> &nums1, vector<int> &nums2, int &n){
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for(int index=n-1; index>=1; index--){
        for(int swapped=1; swapped>=0; swapped--){

            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped){
                swap(prev1, prev2);
            }

            if(prev1 < nums1[index] && prev2 < nums2[index]){
                ans = next[0];
            }

            if(nums1[index] > prev2 && nums2[index] > prev1){
                ans = min(ans, 1+next[1]);
            }

            curr[swapped] = ans;
        }
        next = curr;
    }

    return next[0];
}



int main()
{
    int n;
    cout<<"Enter the size of the arrays"<<endl;
    cin>>n; // 4.

    vector<int> nums1(n, 0), nums2(n, 0);
    cout<<"Enter the elements of first array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums1[i]; // 1 3 5 4.
    }
    cout<<"Enter the elements of second array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums2[i]; // 1 2 3 7.
    }
    
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    n += 1;

    // Recursive Approach.
    // int ans = solveRecursively(nums1, nums2, n, 1, false);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (2, -1));
    // int ans = solveTopDownMemo(nums1, nums2, n, 1, 0, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(nums1, nums2, n);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(nums1, nums2, n);

    cout<<"Minimum number of swaps required are : "<<ans<<endl;

    return 0;
}