#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    vector<int> nums = {1, 2, 2, 4, 4, 3, 10, 4, 5};
    map<int,int> omap;

    for(int i=0; i<nums.size(); i++){
        omap[nums[i]]++;
    }

    vector<pair<int,int>> ans;

    for(auto pr: omap){
        ans.push_back(pr);
    }

    sort(ans.begin(), ans.end(), compare);

    for(int i=0; i<ans.size(); i++){
        int j = 0;

        while(j < ans[i].second){
            cout<<ans[i].first<<" ";
            j++;
        }
    }
    cout<<endl;

    return 0;
}