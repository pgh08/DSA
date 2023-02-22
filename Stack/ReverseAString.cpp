#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s = "Prajwal";
    string ans = "";

    stack<char> st;

    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout<<ans<<endl;

    return 0;
}