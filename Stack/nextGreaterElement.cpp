#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        while(st.top() != -1 && st.top() < nums[i]){
            st.pop();
        }

        ans[i] = st.top();
        st.push(nums[i]);
    }

    cout<<"Next greater elements are : "<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}