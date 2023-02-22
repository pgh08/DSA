#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    vector<char> st;
    int n = s.length();

    for(int i=0; i<n; i++){
        if(!st.empty() && abs(st.back()-s[i]) == 32){
            st.pop_back();
        }
        else{
            st.push_back(s[i]);
        }
    }
    string ans(st.begin(), st.end());

    cout<<ans<<endl;

    return 0;
}