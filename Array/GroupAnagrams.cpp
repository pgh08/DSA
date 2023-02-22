#include<bits/stdc++.h>
using namespace std;

string getkey(string s){
    vector<int> count(26);
    for(int i=0; i<s.size(); i++){
        count[s[i] - 'a']++;
    }
    string key = "";
    for(int i=0; i<26; i++){
        key.append(to_string(count[i]) + 'a');
    }
    cout<<key<<endl;
    return key;
}

int main()
{
    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    map<string, vector<string>> m;

    for(int i=0; i<str.size(); i++){
        string key = getkey(str[i]);
        m[key].push_back(str[i]);
    }

    vector<vector<string>> ans;

    for(auto pr: m){
        ans.push_back(pr.second);
    }

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}