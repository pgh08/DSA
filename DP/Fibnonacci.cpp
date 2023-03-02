// Top-Down Memoization Approach : Time Complexity : O(n), Space Complexity : O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimized Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
using namespace std;

/* const int N = 1e5+10;

int dp[N]; */

//Top-Down Approach.
/* int topDownFibonacci(int n){
    //Base case.
    if(n <= 1){
        return n;
    }
    // Return directly from stored ans.
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
} */

// Bottom Up Approach.
/* void bottomUpFibonacci(int n){
    vector<int> ans(n+1);
    ans[0] = 0;
    ans[1] = 1;

    for(int i=2; i<=n; i++){
        ans[i] = ans[i-1] + ans[i-2];
        cout<<ans[i]<<" ";
    }
} */

// Space Optimized Approach.
void spaceOptimizedFibonacci(int n){
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;

    if(n == 0){
        cout<<0<<endl;
        return;
    }
    else{
        cout<<prev2<<" "<<prev1<<" ";
    }

    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        cout<<curr<<" ";

        //Shifting prev1 and prev2 by one place.
        prev2 = prev1;
        prev1 = curr;
    }
}

int main()
{   
    //For Top-Down Approach.
    //memset(dp, -1, sizeof(dp));
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    //Top Down Memoization Approach.
    //topDownFibonacci(n);

    //Bottom Up Approach.
    //bottomUpFibonacci(n);

    // Space Optimized Approach.
    spaceOptimizedFibonacci(n);

    return 0;
}