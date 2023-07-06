// Given the number of items 'n' and maximum weight a theif can carry 'capacity' and value of each item with weight, find the maximum value of items which can be stolen within the knapsack weight.
// Recursive Approach : Time Complexity : O((n*capacity)^2), Space Complexity : O(n*capacity).
// Top Down Memoization Approach : Time Complexity : O(n*capacity), Space Complexity : O(n*capacity) + O(n*capacity).
// Bottom Up Approach : Time Complexity : O(n*capacity), Space Complexity : O(n*capacity).
// Space Optimized Approach : Time Complexity : O(n*capacity), Space Complexity : O(2*capacity).
// More Optimized(Single Array) Approach : Time Complexity : O(n*capacity), Space Complexity : O(capacity);
#include<iostream>
#include<vector>
using namespace std;

int solveRecursively(vector<int> &weight, vector<int> &value, int index, int capacity){
    // Base Case.
    if(index == 0){
        if(capacity >= weight[index]){
            return value[0];
        }
        else{
            return 0;
        }
    }

    // Include.
    int Include = 0;
    if(capacity >= weight[index]){
        Include = value[index] + solveRecursively(weight, value, index-1, capacity-weight[index]);
    }

    // Exclude.
    int Exclude = 0 + solveRecursively(weight, value, index-1, capacity);

    int ans = max(Include, Exclude);

    return ans;
}

int solveTopDownMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
    // Base Case.
    if(index == 0){
        if(capacity >= weight[0]){
            dp[0][capacity] = value[0];
        }
        else{
            dp[0][capacity] = 0;
        }
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    // Include.
    int Include = 0;
    if(capacity >= weight[index]){
        Include = value[index] + solveTopDownMemo(weight, value, index-1, capacity-weight[index], dp);
    }

    // Exclude.
    int Exclude = 0 + solveTopDownMemo(weight, value, index-1, capacity, dp);

    dp[index][capacity] = max(Include, Exclude);

    return dp[index][capacity];
}

int solveBottomUp(vector<int> &weight, vector<int> &value, int n, int capacity){
    // Vector intialization.
    vector<vector<int>> dp(n, vector<int> (capacity+1, 0));

    // Base Case Initialization.
    for(int w=weight[0]; w<=capacity; w++){
        if(capacity >= weight[0]){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    // Using for loop instead of recursion.
    for(int index=1; index<n; index++){
        for(int w=0; w<=capacity; w++){
            
            int Include = 0;
            if(w >= weight[index]){
                Include = value[index] + dp[index-1][w-weight[index]];
            }

            int Exclude = 0 + dp[index-1][w];

            dp[index][w] = max(Include,Exclude);
        }
    }

    return dp[n-1][capacity];
}

int solveSpaceOptimized(vector<int> &weight, vector<int> &value, int n, int capacity){
    // Prev and Curr vector Initialization.
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    // Base Case Intialization for prev vector.
    for(int w=weight[0]; w<=capacity; w++){
        if(capacity >= weight[0]){
            prev[w] = value[0];
        }
        else{
            prev[w] = 0;
        }
    }

    for(int index=1; index<n; index++){
        for(int w=0; w<=capacity; w++){

            int Include = 0;
            if(w >= weight[index]){
                Include = value[index] + prev[w-weight[index]];
            }

            int Exclude = 0 + prev[w];

            curr[w] = max(Include,Exclude);
        }

        prev = curr;
    }

    return prev[capacity];
}

int solveMoreOptimized(vector<int> &weight, vector<int> &value, int n, int capacity){
    // Curr vector Initialization.
    vector<int> curr(capacity+1, 0);

    // Base Case Intialization for prev vector.
    for(int w=weight[0]; w<=capacity; w++){
        if(capacity >= weight[0]){
            curr[w] = value[0];
        }
        else{
            curr[w] = 0;
        }
    }

    for(int index=1; index<n; index++){
        // Traversing from right to left to avoid corruption of value from before.
        for(int w=0; w<=capacity; w++){

            int Include = 0;
            if(w >= weight[index]){
                Include = value[index] + curr[w-weight[index]];
            }

            int Exclude = 0 + curr[w];

            curr[w] = max(Include,Exclude);
        }
    }

    return curr[capacity];
}

int main()
{
    int n, capacity; // 4, 5.
    cout<<"Enter the number of items available and maximum weight of knapkack"<<endl;
    cin>>n>>capacity;

    vector<int> weight(n), value(n);
    cout<<"Enter the weights of each item"<<endl;
    for(int i=0; i<n; i++){
        cin>>weight[i]; // 1 2 4 5.
    }

    cout<<"Enter the value od each item"<<endl;
    for(int i=0; i<n; i++){
        cin>>value[i]; // 5 4 8 6.
    }

    // Recursive Approach.
    // int ans = solveRecursively(weight, value, n-1, capacity);

    // Top Down Memoization Approach.
    // vector<vector<int>> dp(n+1, vector<int> (capacity+1, -1));

    // int ans = solveTopDownMemo(weight, value, n-1, capacity, dp);

    // Bottom Up Approach.
    // int ans = solveBottomUp(weight, value, n, capacity);

    // Space Optimized Approach.
    // int ans = solveSpaceOptimized(weight, value, n, capacity);

    // More Optimized(Single Array) Approach.
    int ans = solveMoreOptimized(weight, value, n, capacity);

    cout<<"Maximum value which can fit into knapsack is : "<<ans<<endl; // 13.

    return 0;
}