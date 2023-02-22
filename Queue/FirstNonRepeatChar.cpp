#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string value"<<endl;
    cin>>s;

    unordered_map<char,int> count;
    queue<char> q;
    string ans = "";
    for(int i=0; i<s.length(); i++){
        count[s[i]]++;

        q.push(s[i]);

        while(!q.empty()){
            if(count[q.front()] > 1){
                q.pop();
            }
            else{
                ans += q.front();
                break;
            }
        }
        if(q.empty()){
            ans += '#';
        }
    }
    cout<<"Answer is : "<<ans<<endl;

    return 0;
}