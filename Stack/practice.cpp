#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == ')' || ch == '}' || ch == ']'){
            if(st.empty()){
                return false;
            }
            if((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            st.push(ch);
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