//Given a url and parameters find string after '=' symbol if given paramter is not present return '-1'. 
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(string s, vector<string> &ans, string find){
    int n = s.length();
    int i = s.find(find)+find.size()+1;
    int j= 0;
    string res = "";
    while(s[i] != '&' && i < n){
        res += s[i];
        i++;
    }
    ans.push_back(res);
}

int main()
{
    string s;
    cin>>s;

    int N;
    cin>>N;
    vector<string> arr(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    int j = 0;
    int n = s.length();
    vector<string> ans;
    for(int i=0; i<N; i++){
        cout<<s.find(arr[i])<<endl;
        if(s.find(arr[i]) > INT_MAX){
            ans.push_back("-1");
        }
        else{
            solve(s, ans, arr[i]);
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }

    return 0;
}