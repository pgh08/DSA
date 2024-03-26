// Given the string, reverse it the string by word, i.e last word is present in first and so on in ans.
// Approach 1 : Reverse string word by word iterating from last. Time Complexity : O(n^2), Space Complexity : O(1).
// Approach 2 : Using Stack. Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string reverseWord(string &s){
    string ans = "";
    string temp = "";
    int n = s.length();

    for(int i=n-1; i>=0; i--){
        if(s[i] == ' '){
            reverse(temp.begin(), temp.end());
            ans += temp + " ";
            temp = "";
        }
        else{
            temp += s[i];
        }
    }

    reverse(temp.begin(), temp.end());
    ans += temp;

    return ans;
}

string reverseWordUsingStack(string &s){
    string ans = "";
    string temp = "";
    stack<string> st;
    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            st.push(temp);
            st.push(" ");
            temp = "";
        }
        else{
            temp += s[i];
        }
    }

    st.push(temp);

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s;
    cout<<"Enter the value of string"<<endl;
    getline(cin, s);

    // string ans = reverseWord(s);

    string ans = reverseWordUsingStack(s);

    cout<<"String after reversing word by word is "<<ans<<endl;

    return 0;
}