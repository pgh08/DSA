#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of an array :"<<endl;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> ans(n);
    ans[0] = nums[0];

    for(int i=1; i<n; i++){
        ans[i] = ans[i-1] + nums[i]; 
    }

    for(int j=0; j<n; j++){
        cout<<ans.at(j)<<" ";
    }
    cout<<endl;

    return 0;
}