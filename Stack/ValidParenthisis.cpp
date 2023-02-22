#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(st.empty()){
                return false;
            }
            if((s[i] == '}' && st.top() == '{') || (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            st.push(s[i]);
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;

    if(isValid(s)){
        cout<<"Valid Parentheses"<<endl;
    }
    else{
        cout<<"Not a Valid Parentheses"<<endl;
    }

    return 0;
}