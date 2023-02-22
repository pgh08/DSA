#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

string infixToPostfix(string expression){
    stack<char> st;
    string result;

    int size = expression.length();

    for(int i=0; i<size; i++){
        char c = expression[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <='9')){
            result += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && (precedence(c) <= precedence(st.top()))){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    //If stack is not empty yet.
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string expression;
    cout<<"Enter the infix expression"<<endl;
    //a+b*(c^d-e)^(f+g*h)-i.
    cin>>expression;

    string ans;

    ans = infixToPostfix(expression);

    cout<<"Postfix expression is : "<<ans<<endl;

    return 0;
}