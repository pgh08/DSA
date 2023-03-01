#include<iostream>
#include<stack>
using namespace std;

void removeMiddle(stack<int> &st, int index, int n){
    //Base case.
    if(index >= n){
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();

    removeMiddle(st, index+1, n);
    st.push(num);
}

void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    cout<<"Stack before deleting middle element"<<endl;
    print(st);

    int index = 0;
    int n = st.size()/2;
    removeMiddle(st, index, n);

    cout<<"Stack before deleting middle element"<<endl;
    print(st);

    return 0;
}