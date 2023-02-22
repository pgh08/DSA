//Given a array of numbers find the next smaller elements of that array, if not present append -1 in that place.
/*
Algorithm : 
    1. Brute force : 
        -->For each element traverse through whole array and find the minimum element.
        -->Time complexity : O(n^2), Space complexity : O(n).

    2. Using Stack : 
        -->Declare stack and push -1 to it.
        -->Traverse array from end to begining and compare top of the stack with the current element of the array.
        -->If stack's top is greater then pop the stack until current element is greater than top of stack.
        -->Assign ans array's particular position to stack's top after performing above operation.
        -->Push current element to stack.
        -->Time complexity : O(n), Space complexity : O(n).
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void bruteForce(int *arr, int n, vector<int> &ans){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }
}

void nextSmallestNumber(int arr[], int ans[], int n){
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
}

int main()
{ 
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cout<<"Enter the data"<<endl;
        cin>>arr[i];
    }

    //vector<int> ans(n, -1);
    //bruteForce(arr, n, ans);
    int ans[n];

    nextSmallestNumber(arr, ans, n);

    cout<<"Next smaller element of the array are : "<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}