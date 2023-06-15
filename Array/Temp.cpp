#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the array elements seperated by space"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> left(n), right(n), ans(n);
    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++){
        left[i] = left[i-1] * nums[i-1];
    }

    for(int i=n-2; i>=0; i--){
        right[i] = right[i+1] * nums[i+1];
    }

    for(int i=0; i<n; i++){
        ans[i] = left[i] * right[i];
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}