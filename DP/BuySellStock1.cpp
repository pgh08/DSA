// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Time Complexity : O(n), Space Complexity : O(1).
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 6.

    int *prices = new int[n];
    for(int i=0; i<n; i++){
        cin>>prices[i]; // [7,1,5,3,6,4].
    }

    int profit = 0;
    int mini = prices[0];
    
    for(int i=0; i<n; i++){
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }

    cout<<"Maximum achievable profit is : "<<profit<<endl; // 5.

    return 0;
}