#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> getNegativeInK(vector<int> &nums, int k, int n){
    deque<int> dq;
    vector<int> res;

    for(int i=0; i<k; i++){
        if(nums[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        res.push_back(nums[dq.front()]);
    }
    else{
        res.push_back(0);
    }

    for(int i=k; i<n; i++){
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        if(nums[i] < 0){
            dq.push_back(i);
        }

        if(dq.size() > 0){
            res.push_back(nums[dq.front()]);
        }
        else{
            res.push_back(0);
        }
    }
    return res;
}

int main()
{   
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    int k; 
    cout<<"Enter the value of K :"<<endl;
    cin>>k;

    vector<int> ans = getNegativeInK(nums, k, n);
    int len = ans.size();

    for(int i=0; i<len; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}