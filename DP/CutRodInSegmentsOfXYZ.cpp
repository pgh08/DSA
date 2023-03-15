// Given the length of the rod and lengths X,Y and Z find the maximum number of cuts required.
// Recursive Approach : Time Complexity : O(n^3), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom up Approach : Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(int rodLength, int x, int y, int z){
    // Base Case.
    if(rodLength == 0){
        return 0;
    }
    if(rodLength < 0){
        return INT_MIN;
    }

    int a = solveRecursively(rodLength-x, x, y, z) + 1;
    int b = solveRecursively(rodLength-y, x, y, z) + 1;
    int c = solveRecursively(rodLength-z, x, y, z) + 1;

    int ans = max(a, max(b, c));

    return ans;
}

int solveTopDownMemo(int rodLength, int x, int y, int z, vector<int> &dp){
    // Base Case.
    if(rodLength == 0){
        return 0;
    }
    if(rodLength < 0){
        return INT_MIN;
    }
    if(dp[rodLength] != -1){
        return dp[rodLength];
    }

    int a = solveTopDownMemo(rodLength-x, x, y, z, dp) + 1;
    int b = solveTopDownMemo(rodLength-y, x, y, z, dp) + 1;
    int c = solveTopDownMemo(rodLength-z, x, y, z, dp) + 1;

    dp[rodLength] = max(a,max(b,c));

    return dp[rodLength];
}

int solveBottomUp(int rodLength, int x, int y, int z){
    // Create a dp array of with all INT_MIN.
    vector<int> dp(rodLength+1, INT_MIN);

    // Initialize base case.
    dp[0] = 0;

    for(int i=1; i<=rodLength; i++){
        // if Only index - x or y or z is greater than or equal to zero.
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x]+1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y]+1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z]+1);
        }
    }

    if(dp[rodLength] < 0){
        return 0;
    }

    return dp[rodLength];
}

int main()
{
    int rodLength;
    cout<<"Enter the rod Length"<<endl;
    cin>>rodLength;

    int x, y, z;
    cout<<"Enter the length of segments X, Y and Z"<<endl;
    cin>>x>>y>>z;

    // Recursive Approach.
    // int ans = solveRecursively(rodLength, x, y, z);

    // Top Down Memoization Approach.
    // vector<int> dp(rodLength+1, -1);
    // int ans1 = solveTopDownMemo(rodLength, x, y, z, dp);

    // Bottom Up Approach.
    int ans2 = solveBottomUp(rodLength, x, y, z);

    cout<<"Maximum number of cuts is : "<<ans2<<endl;

    return 0;
}