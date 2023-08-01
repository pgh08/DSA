#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{
    vector<int> num = {1,1,2,2,2,3};
    int n = num.size();

    map<int,int> om;

    for(int i=0; i<n; i++){
        om[num[i]]++;
    }

    vector<pair<int,int>> ans;

    for(auto pr : om){
        ans.push_back(pr);
    }

    sort(ans.begin(), ans.end(), compare);

    for(auto i : ans){
        cout<<i.first<<" ";
    }
    cout<<endl;

    return 0;
}