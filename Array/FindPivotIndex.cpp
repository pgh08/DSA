#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int sum = 0;
    int leftsum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }
    for(int i=0; i<n; i++){
        if(leftsum == sum-leftsum-nums[i]){
            cout<<i<<endl;
            return 0;
        }
        leftsum += nums[i];
    }
    cout<<-1<<endl;
    return 0;
}