// Given n dice, k face in each dice (1 to k) and target sum to achieve, find the number of possible ways to achieve target sum.
// Recursive Approach : Time Complexity : O(k^n), Space Complexity : O(k*n*target).
// Top Down Memoization Approach : Time Complexity : O(k*n*target), Space Complexity : O(n*target).
// Bottom Up Approach : Time Complexity : O(k*n*target), Space Complexity : O(n*target).
// Space Optimized Approach : Time Complexity : O(k*n*target), Space Complexity : O(target).
#include<iostream>
#include<vector>
using namespace std; 

class solution{
    private: 
        int mod = 1e9+7;

    public:
        int solveRecursively(int n, int &k, int target){
            // Base Case.
            if(target < 0){
                return 0;
            }
            if(n == 0 && target != 0){
                return 0;
            }
            if(n != 0 && target == 0){
                return 0;
            }
            if(n == 0 && target == 0){
                return 1;
            }

            // OR use if(n == 0 || target <= 0){return n == target};.
            int ans = 0;
            for(int i=1; i<=k; i++){
                ans = (ans+solveRecursively(n-1, k, target-i))%mod;
            }

            return ans;
        }

        int solveTopDownMemo(int n, int &k, int target, vector<vector<int>> &dp){
            // Base Case.
            if(n == 0 || target <= 0){
                return n == target;
            }

            if(dp[n][target] != -1){
                return dp[n][target];
            }

            int ans = 0;
            for(int i=1; i<=k; i++){
                ans = (ans + solveTopDownMemo(n-1, k, target-i, dp))%mod;
            }

            return dp[n][target] = ans;
        }

        int solveBottomUp(int n, int &k, int target);

        int solveSpaceOptimized(int n, int &k, int target){
            vector<int> prev(target+1, 0);
            vector<int> curr(target+1, 0);

            // Analysing base case.
            prev[0] = 1;

            for(int i=1; i<=n; i++){
                for(int j=1; j<=target; j++){

                    int ans = 0;
                    for(int f=1; f<=k; f++){
                        if(j-f >= 0){
                            ans = (ans + prev[j-f])%mod;
                        }
                    }
                    curr[j] = ans;
                }

                prev = curr;
            }

            return prev[target];
        }
};

int solution :: solveBottomUp(int n, int &k, int target){
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

    // Analysing base case.
    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){

            int ans = 0;
            for(int f=1; f<=k; f++){
                if(j-f >= 0){
                    ans = (ans + dp[i-1][j-f])%mod;
                }
            }
            dp[i][j] = ans;
        }
    }

    return dp[n][target];
}

int main()
{
    int n, k, target; // 30 30 500. // 2 6 7.
    cout<<"Enter the number of dice, number of faces on each dice and target"<<endl;
    cin>>n>>k>>target;

    // Initializing the object.
    solution s;

    // Recursive Approach.
    // int ans = s.solveRecursively(n, k, target);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    // int ans = s.solveTopDownMemo(n, k, target, dp);

    // Bottom Up Approach.
    // int ans = s.solveBottomUp(n, k, target);

    // Space Optimized Approach.
    int ans = s.solveSpaceOptimized(n, k, target); 

    cout<<"Number of possible ways to achieve target sum is : "<<ans<<endl; // 222616187. // 6.

    return 0;
}