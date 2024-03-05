// Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.
// In other words, you have to iterate over the array, and after each index, determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. An array will be formed for each iteration and stored in an array of arrays. If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. If two numbers have equal frequency, place the smaller number first in the array.
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

    bool compare(pair<int,int> &a, pair<int,int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }

vector<vector<int>> topKNums(vector<int> &nums, int &n, int k){
    map<int,int> mp;
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        mp[nums[i]]++;

        vector<pair<int,int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), compare);
        vector<int> temp;

        int j = 0;
        while(j < v.size() && j < k){
            temp.push_back(v[j].first);
            j++;
        }
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    int n,k;
    cout<<"Enter the size of the array and value of k"<<endl;
    cin>>n>>k; // 5, 4.
    
    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 5 2 1 3 2.
    }

    vector<vector<int>> ans = topKNums(nums, n, k);

    // Printing ans.
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}