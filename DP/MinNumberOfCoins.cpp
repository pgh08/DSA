// Recursive Solution : Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursive(vector<int> &coins, int n, int targetAmount){
    // Base Case.
    if(targetAmount == 0){
        return 0;
    }
    if(targetAmount < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(auto val : coins){
        int ans = solveRecursive(coins, n, targetAmount-val);

        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
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

    int ans1 = solveRecursive(coins, n, targetAmount);

    cout<<"Minimum number of coins requires is : "<<ans1<<endl;

    return 0;
}