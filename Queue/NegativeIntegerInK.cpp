#include<bits/stdc++.h>
using namespace std;

vector<int> negativeInK(vector<int> nums, int n, int k){
    deque<int> dq;
    vector<int> res;

    for(int i=0; i<k; i++){
        if(nums[i] < 0){
            dq.push_back(i);
        }
    }
    //processing first k size window.
    if(dq.size() > 0){
        res.push_back(nums[dq.front()]);
    }
    else{
        res.push_back(0);
    }
    //Similarly for other windows.
    for(int i=k; i<n; i++){
        //Removal.
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }
        //Addition.
        if(nums[i] < 0){
            dq.push_back(i);
        }
        //Storing answer.
        if(dq.size() > 0){
            res.push_back(nums[dq.front()]);
        }
        else{
            res.push_back(0);
        }
    }
    // cout<<dq.front()<<endl;
    return res;
}

int main()
{
    vector<int> nums = {-8,2,3,-6,10}; // ans : -8, 0, -6, -6.
    int k;
    cout<<"Enter the value of K"<<endl;
    cin>>k;

    vector<int> ans = negativeInK(nums, 5, k);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";

    }
    cout<<endl;

    return 0;
}