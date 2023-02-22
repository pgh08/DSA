#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int size, int count){
    //Base case.
    if(count == size/2){
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    //Recursive call.
    solve(st, size, count+1);
    st.push(num);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);

    int n = 5;
    int count = 0;

    solve(st, n, count);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}