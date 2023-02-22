//Sort even indices of an array in increasing order.
//Sort odd indices of an array in decreasing order.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{   
    vector<int> nums = {4,1,2,3};
    int n = nums.size();
    
    vector<int> even;
    vector<int> odd;

    for(int i=0; i<n; i++){
        if(nums[i] % 2 != 0){
            odd.push_back(nums[i]);
        }
        else{
            even.push_back(nums[i]);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());

    int evenIndex = 0, oddIndex = 0;
    int i = 0;
    
    while(evenIndex < even.size() || oddIndex < odd.size()){
        if(evenIndex < even.size()){
            nums[i++] = even[evenIndex++];
        }
        if(oddIndex < odd.size()){
            nums[i++] = odd[oddIndex++];
        }
    }

    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}