#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string value"<<endl;
    cin>>s;

    unordered_map<char,pair<int,int>> umap;
    int n = s.length();

    for(int i=0; i<n; i++){
        umap[s[i]].first++;
        umap[s[i]].second = i;
    }

    int res = n+1;

    for(auto pr : umap){
        if(pr.second.first == 1){
            res = min(pr.second.second, res);
        }
    }

    if(res < n){
        cout<<s[res]<<endl;
    }
    else{
        cout<<'#'<<endl;
    }

    return 0;
}