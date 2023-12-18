#include<iostream>
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

    int zeroCount = 0;
    int product = 1;
    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            zeroCount++;
        }
        else{
            product *= nums[i];
        }
    }

    for(int i=0; i<n; i++){
        if(zeroCount > 1){
            cout<<"0 ";
        }
        else if(zeroCount == 1 && nums[i] == 0){
            cout<<product<<" ";
        }
        else if(zeroCount == 0){
            cout<<product/nums[i]<<" ";
        }
        else{
            cout<<"0 ";
        }
    }

    cout<<endl;

    return 0;
}