// Given a string find the first non repeating character in the string.
#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;

    unordered_map<char,pair<int,int>> umap;
    int n = s.length();

    for(int i=0; i<n; i++){
        umap[s[i]].first++;
        umap[s[i]].second = i;
    }

    int res = INT_MAX;

    for(auto pr : umap){
        if(pr.second.first == 1){
            res = min(res, pr.second.second);
        }
    }

    cout<<(res == INT_MAX ? 'All are repeating characters' : s[res])<<endl;

    return 0;
}