#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0;
    string s;
    cin>>s;

    if(s.length()%2 != 0){
        cout<<"Not possible"<<endl;
        return 0;
    }
    stack<int> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        
        if(ch == '{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top() == '}'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            if(st.top() == '{'){
                b++;
            }
            else{
                a++;
            }
            st.pop();
        }
    }
    int ans = ((a+1)/2) + ((b+1)/2);

    cout<<ans<<endl;

    return 0;
}