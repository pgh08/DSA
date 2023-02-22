//Longest Substring without repeating character.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<char> uset;
    int ans = 0;
    string s;
    cin>>s;
    int r=0,l=0;
    int n = s.length();
    while (l < n && r < n){
        if(uset.find(s[r]) == uset.end()){
            ans = max(ans,r-l+1);
            uset.insert(s[r]);
            r++;
        }
        else{
            uset.erase(s[l]);
            l++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}