// Recursive Solution : Time Complexity : O(amount^2), Space Complexity : O(amount).
// Top Down Memoization Approach : Time Complexity : O(amount*n), Space Complexity : O(amount).
// Bottom Up Approach : Time Complexity : O(amount*n), Space Complexity : O(amount).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursive(vector<int> &coins, int targetAmount){
    // Base Case.
    if(targetAmount == 0){
        return 0;
    }
    if(targetAmount < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(auto val : coins){
        int ans = solveRecursive(coins, targetAmount-val);

        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}

int solveTopDownMemo(vector<int> &coins, int targetAmount, vector<int> &dp){
    //Base Case.
    if(targetAmount == 0){
        return 0;
    }
    if(targetAmount < 0){
        return INT_MAX;
    }
    if(dp[targetAmount] != -1){
        return dp[targetAmount];
    }

    int mini = INT_MAX;

    for(auto val : coins){
        int ans = solveTopDownMemo(coins, targetAmount-val, dp);

        if(ans != INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    dp[targetAmount] = mini;

    return mini;
}

int solveBottomUp(vector<int> &coins, int targetAmount, int n){
    // All the elements are set to INT_MAX because all worst all child's amount can be less than zero.
    vector<int> dp(targetAmount+1, INT_MAX);
    // Resolving Base Case.
    dp[0] = 0;

    // Outer Loop equivalent to recursive call in top down approach which keeps track of the amount.
    for(int amount=0; amount<=targetAmount; amount++){
        // Inner Loop is used because for each amount there will be coins.size() number of possible choices of coin.
        for(auto coinVal : coins){
            // To avoid int overflow when dp[amount-coinval] = INT_MAX becuase we do 1+dp[amount-coinval] and also to if amount-coinVal is less than zero array index cannot be accessed.
            if((amount-coinVal >= 0) && (dp[amount-coinVal] != INT_MAX)){
                dp[amount] = min(dp[amount],1+dp[amount-coinVal]);
            }
        }
    }
    return dp[targetAmount];
}

int main()
{
    int n;
    cout<<"Enter the number of coin choices"<<endl;
    cin>>n;

    vector<int> coins(n);
    cout<<"Enter available coin choices"<<endl;
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int targetAmount;
    cout<<"Enter the target amount"<<endl;
    cin>>targetAmount;

    // Recursive Solution.
    // int ans1 = solveRecursive(coins, targetAmount);

    // Top Down Memoization Approach.
    // vector<int> dp(targetAmount+1, -1);
    // int ans2 = solveTopDownMemo(coins, targetAmount, dp);

    // Bottom Up Approach.
    int ans3 = solveBottomUp(coins, targetAmount, n);


    if(ans3 != INT_MAX){
        cout<<"Minimum number of coins requires is : "<<ans3<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }

    return 0;
}