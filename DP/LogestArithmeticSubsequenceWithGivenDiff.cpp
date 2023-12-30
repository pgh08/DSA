// Given an array of integers and difference find the length of longest Arithmetic Progression array with given difference.
// Dynamic Programming : Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n, diff;
    cout<<"Enter the size of the array and common difference"<<endl;
    cin>>n>>diff; // 9 -2.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 1 5 7 8 5 3 4 2 1.
    }

    unordered_map<int,int> dp;
    int ans = 0;

    for(int i=0; i<n; i++){
        int temp = nums[i] - diff;
        int tempAns = 0;

        if(dp.count(temp)){
            tempAns = dp[temp];
        }
        dp[nums[i]] = 1 + tempAns;

        ans = max(ans, dp[nums[i]]);
    }

    cout<<"Longest Arithmetic Subsequence length is : "<<ans<<endl;

    return 0;
}