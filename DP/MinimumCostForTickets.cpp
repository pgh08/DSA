// Given the days (1-365) of travel and costs of 1, 7 and 30 day pass, find the minimum cost require to travel all the days.
// Recursive Approach : Time Complexity : O(n^3), Space Complexity : O(n).
// Top Down Memoization Approach : Time Complexity : O(1), Space Complexity : O(n) + O(n).
// Bottom Up Approach : Time Complexity : O(n), Space Complexity : O(n).
// Space Optimization Approach : Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int solveRecursively(int n, vector<int> &days, vector<int> &costs, int index){
    // Base Case.
    if(index >= n){
        return 0;
    }

    // 1 Day Pass.
    int option1 = costs[0] + solveRecursively(n, days, costs, index+1);

    // 7 Day Pass.
    int i;
    for(i=index; (i<n && days[i] < days[index] + 7); i++);
    int option2 = costs[1] + solveRecursively(n, days, costs, i);

    // 30 Day Pass.
    for(i=index; (i<n && days[i] < days[index] + 30); i++);
    int option3 = costs[2] + solveRecursively(n, days, costs, i);

    return min(option1, min(option2,option3));
}

int solveTopDownMemo(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
    // Base Case.
    if(index >= n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }

    // 1 Day Pass.
    int option1 = costs[0] + solveTopDownMemo(n, days, costs, index+1, dp);

    // 7 Day Pass.
    int i;
    for(i=index; (i<n && days[i] < days[index] + 7); i++);
    int option2 = costs[1] + solveTopDownMemo(n, days, costs, i, dp);

    // 30 Day Pass.
    for(i=index; (i<n && days[i] < days[index] + 30); i++);
    int option3 = costs[2] + solveTopDownMemo(n, days, costs, i, dp);

    return dp[index] = min(option1, min(option2,option3));
}

int solveBottomUp(int n, vector<int> &days, vector<int> &costs){
    // Initialization of dp array.
    vector<int> dp(n+1, INT_MAX);

    // Initialization of base case.
    dp[n] = 0;

    for(int k=n-1; k>=0; k--){

        // 1 Day Pass.
        int option1 = costs[0] + dp[k+1];

        // 7 Day Pass.
        int i;
        for(i=k; (i<n && days[i] < days[k] + 7); i++);
        int option2 = costs[1] + dp[i];

        // 30 Day Pass.
        for(i=k; (i<n && days[i] < days[k] + 30); i++);
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2,option3));
    }
    return dp[0];
}

int solveSpaceOptimized(int n, vector<int> &days, vector<int> &costs){
    int ans = 0;

    // Use Queue for storing Montly and Weekly track of days and respective costs.
    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;

    for(auto day : days){

        // Step 1 : Remove Expired Days.
        while(!monthly.empty() && monthly.front().first + 30 <= day){
            monthly.pop();
        } 
        while(!weekly.empty() && weekly.front().first + 7 <= day){
            weekly.pop();
        }

        // Step 2 : Add days and respective costs.
        monthly.push({day, ans+costs[2]});
        weekly.push({day, ans+costs[1]});

        // Step 3 : Update ans.
        ans = min(ans+costs[0], min(monthly.front().second, weekly.front().second));
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the days array"<<endl;
    cin>>n; // 6.

    vector<int> days(n), costs(3);

    cout<<"Enter the days of travel"<<endl;
    for(int i=0; i<n; i++){
        cin>>days[i]; // 1 4 6 7 8 20.
    }

    cout<<"Enter the cost for 1 Day, 7 Day and 30 Day Pass"<<endl;
    for(int i=0; i<3; i++){
        cin>>costs[i]; // 2 7 15.
    }

    // Recursive Approach.
    // int ans = solveRecursively(n, days, costs, 0); // 11.

    // Top Down Memoization Approach.
    // vector<int> dp(n+1, -1);
    // int ans = solveTopDownMemo(n, days, costs, 0, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(n, days, costs);

    // Space Optimized Approach.
    int ans = solveSpaceOptimized(n, days, costs);

    cout<<"Minimum cost required for travel is : "<<ans<<endl; 

    return 0;
}