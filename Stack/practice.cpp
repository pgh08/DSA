#include<iostream>
#include<stack>
using namespace std;

bool isRedundant(string s){
    stack<char> st;
    int size = s.length();

    for(int i=0; i<size; i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool redundant = true;

                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*'){
                        redundant = false;
                    }
                    st.pop();
                }
                if(redundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}

int main()
{
    string s;
    cin>>s;

    if(isRedundant(s)){
        cout<<"Redundant brackets present"<<endl;
    }
    else{
        cout<<"No redundant brackets"<<endl;
    }

    return 0;
}