//Given the mathemetical expression tell whether it has redundant brackets or not.
/*
Algorithm : 
    1. Use stack to keep track of previous opening brackets.
    2. Whenever we encounter open brack or any sign we push it into the stack.
    3. When we encounter closing bracket we keep a flag to check whether any sign is present between those brackets, if sign is present inside the brackets we make that flag false.
    4. Outside side the loop if flag is still true, then redundant brackets are present else redunsant bracket still haven't encountered.
    5. Time complexity : O(n), Space complexity : O(n).
*/
#include<iostream>
#include<stack>
using namespace std;

bool redundant(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;

                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
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
    cout<<"Enter the expression"<<endl;
    cin>>s;

    if(redundant(s)){
        cout<<"There are redundant brackets"<<endl;
    }
    else{
        cout<<"There are no redundant brackets"<<endl;
    }

    return 0;
}