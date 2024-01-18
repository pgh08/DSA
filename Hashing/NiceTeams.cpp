// Given an integer array find the pairs which has their difference greater than of equal to given difference.
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
    int n, minDiff;
    cout<<"Enter the size of the array and minDiff"<<endl;
    cin>>n>>minDiff; // 6 3.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 4 5 2 1 1 3.
    }

    // Solution.
    map<int,bool> mp;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int diff = nums[i] - nums[j];
            if(diff >= minDiff && !mp[nums[i]] && !mp[nums[j]]){
                ans++;
                mp[nums[i]] = mp[nums[j]] = true;
            }
        }
    }

    cout<<"Maximum possible pairs are : "<<ans<<endl;

    return 0;
}