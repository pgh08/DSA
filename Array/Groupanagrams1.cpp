#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> str = {"ate", "tan", "bat", "tae", "nat", "eta"};
    int n = str.size();
    map<string, vector<string>> m;

    for(int i=0; i<n; i++){
        string s = str[i];
        sort(s.begin(),s.end());
        m[s].push_back(str[i]);
    }
    vector<vector<string>> result;
    for(auto pr: m){
        result.push_back(pr.second);
    }

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}