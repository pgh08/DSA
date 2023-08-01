// Given a array of integers which represents obstacles in the path of frog from lane 2, Calculate minimum sideways jump from which that frog can the destination i.e. end of the array.
// Recursive Approach : Time Complexity : O(3^n), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n) + O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursively(vector<int> &obstacles, int currLane, int currPos, int n){
    // Base Case.
    if(currPos == n){
        return 0;
    }

    // Option 1 : Move in same lane.
    if(obstacles[currPos+1] != currLane){
        return solveRecursively(obstacles, currLane, currPos+1, n);
    } // Option 2 : Change lane if obstacle is present.
    else{
        int ans = INT_MAX;

        for(int i=1; i<=3; i++){
            if(currLane != i && obstacles[currPos] != i){
                ans = min(ans, 1+solveRecursively(obstacles, i, currPos, n));
            }
        }
        return ans;
    }
}

int solveTopDownMemo(vector<int> &obstacles, int currLane, int currPos, int n, vector<vector<int>> &dp){
    // Base Case.
    if(currPos == n){
        return 0;
    }
    if(dp[currLane][currPos] != -1){
        return dp[currLane][currPos];
    }


    // Option 1 : Move in same lane.
    if(obstacles[currPos+1] != currLane){
        return solveTopDownMemo(obstacles, currLane, currPos+1, n, dp);
    } // Option 2 : Change lane if obstacle is present.
    else{
        int ans = INT_MAX;

        for(int i=1; i<=3; i++){
            if(currLane != i && obstacles[currPos] != i){
                ans = min(ans, 1+solveTopDownMemo(obstacles, i, currPos, n, dp));
            }
        }
        return dp[currLane][currPos] = ans;
    }
}

int solveBottomUp(vector<int> &obstacles, int n){
    vector<vector<int>> dp(4, vector<int> (n+1, 0));

    // Initialization of base cases.
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currPos=n-1; currPos>=0; currPos--){
        for(int currLane=1; currLane<=3; currLane++){
            // Option 1 : Move in same lane.
            if(obstacles[currPos+1] != currLane){
                dp[currLane][currPos] = dp[currLane][currPos+1];
            } // Option 2 : Change lane if obstacle is present.
            else{
                int ans = INT_MAX;

                for(int i=1; i<=3; i++){
                    if(currLane != i && obstacles[currPos] != i){
                        ans = min(ans, 1+dp[i][currPos+1]);
                    }
                }
                dp[currLane][currPos] = ans;
            }
        }
    }

    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
}

int solveSpaceOptimized(vector<int> &obstacles, int n){
    vector<int> curr(4, 0);
    vector<int> next(4, 0);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currPos=n-1; currPos>=0; currPos--){
        for(int currLane=1; currLane<=3; currLane++){
            // Option 1 : Move in same lane.
            if(obstacles[currPos+1] != currLane){
                curr[currLane] = next[currLane];
            } // Option 2 : Change lane if obstacle is present.
            else{
                int ans = INT_MAX;

                for(int i=1; i<=3; i++){
                    if(currLane != i && obstacles[currPos] != i){
                        ans = min(ans, 1+next[i]);
                    }
                }
                curr[currLane] = ans;
            }
        }
        next = curr;
    }

    return min(next[2], min(1+next[1], 1+next[3])); 
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 6.

    vector<int> obstacles(n);
    cout<<"Enter the elements of the array"<<endl;

    for(int i=0; i<n; i++){
        cin>>obstacles[i]; // 0 2 1 0 3 0.
    }

    // Recursive Approach.
    // int ans = solveRecursively(obstacles, 2, 0, n);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(4, vector<int> (n+1, -1));
    // int ans = solveTopDownMemo(obstacles, 2, 0, n, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(obstacles, n);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(obstacles, n);

    cout<<"Minimum number of sideways jump required are : "<<ans<<endl;

    return 0;
}
