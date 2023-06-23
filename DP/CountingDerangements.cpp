// Give a integer 'N' count number of ways array can be arranged so that no elements remains in their original position.
// Recursive Approach : Time Complexity : O(n^2), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

long long int solveRecursively(int N){
    // Base Case.
    if(N == 1){
        return 0;
    }
    if(N == 2){
        return 1;
    }

    int ans = (((N-1)*(solveRecursively(N-1)+solveRecursively(N-2)))%MOD);

    return ans;
}

long long int solveTopDownMemo(int N, vector<long long int> &dp){
    // Base Case.
    if(N == 1){
        return 0;
    }
    if(N == 2){
        return 1;
    }
    if(dp[N] != -1){
        return dp[N];
    }

    dp[N] = (((N-1)*(solveTopDownMemo(N-1, dp)+solveTopDownMemo(N-2, dp)))%MOD);

    return dp[N];
}

long long int solveBottomUp(int N){
    vector<long long int> dp(N+1, 0);

    // Initialization with the base case.
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=N; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first+second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;

        dp[i] = ans;
    }

    return dp[N];
}

long long int solveSpaceOptimized(int N){
    long long int twoBack = 0;
    long long int oneBack = 1;

    for(int i=3; i<=N; i++){
        long long int first = oneBack%MOD;
        long long int second = twoBack%MOD;
        long long int sum = (first+second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;

        twoBack = oneBack;
        oneBack = ans;
    }

    return oneBack;
}

int main(){
    int N;
    cout<<"Enter the value of N :"<<endl;
    cin>>N;

    // Recursive Approach.
    // long long int ans = solveRecursively(N);

    // Top Down Approach.
    // vector<long long int> dp(N+1, -1);
    // long long int ans = solveTopDownMemo(N, dp);

    // Bottom Up Approach.
    // long long int ans = solveBottomUp(N);

    // Space Optimized Approach.
    long long int ans = solveSpaceOptimized(N);

    cout<<"Possible number of ways are : "<<ans<<endl;

    return 0;
}