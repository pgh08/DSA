// Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.The given num does not contain any leading zero.
// Time Complexity : O(n), Space Complexity : O(n);
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeKDigits(string s, int k){
    stack<char> st;
    int n = s.length();

    // Step 1 : Keep only smallest digits in stack.
    for(int i=0; i<n; i++){
        char ch = s[i];

        while(!st.empty() && k != 0 && st.top() > s[i]){
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // Step 2 : Check whether k is zero or not.
    while(k--){
        st.pop();
    }

    // Step 3 : Store stack's content in a string and reverse it.
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    // Step 4 : Check for leading zero's.
    int index = 0;
    while(ans[index] == '0'){
        index++;
    }

    // Step 5 : Create substring from index till end.
    return index == ans.length() ? "0" : ans.substr(index);
}

int main()
{
    string s;
    cout<<"Enter the value of string"<<endl;
    cin>>s; // 1002991.

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k; // 3.

    string ans = removeKDigits(s, k);

    cout<<"Minimum possible number is : "<<ans<<endl; // 21.

    return 0;
}