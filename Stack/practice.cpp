#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

void findNextSmaller(vector<int> &heights, int n, vector<int> &next){
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=n-1; i--){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();
        }
        next[i] = st.top();
        st.push(i);
    }
}

void findPreviousSmaller(vector<int> &heights, int n, vector<int> &prev){
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of bars are there in histogram"<<endl;
    cin>>n;

    vector<int> heights(n);
    cout<<"Enter the heights of the histogram bars"<<endl;
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }

    vector<int> next(n);

    findNextSmaller(heights, n, next);

    vector<int> prev(n);

    findPreviousSmaller(heights, n, prev);

    int area = INT_MIN;
    for(int i=0; i<n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        int eachArea = length*breadth;
        area = max(eachArea, area);
    }

    cout<<"Largest area in histogram is : "<<area<<endl;

    return 0;
}