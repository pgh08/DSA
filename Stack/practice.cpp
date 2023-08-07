#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerHeight(vector<int> &heights, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerHeight(vector<int> &heights, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    cout<<"Enter the heights"<<endl;
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }

    vector<int> next = nextSmallerHeight(heights, n);
    vector<int> prev = prevSmallerHeight(heights, n);

    int area = 0;

    for(int i=0; i<n; i++){
        int length = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;
        int eachArea = length*breadth;

        area = max(eachArea, area);
    }

    cout<<"Max area is : "<<area<<endl;

    return 0;
}