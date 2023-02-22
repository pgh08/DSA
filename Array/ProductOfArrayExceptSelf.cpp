//Given an array of integers, construct a product array such that product[index] is equal to product of all elements except itself.
/*
Algorithm :
    1. Using 2 tempary arrays : 
       --> Use left array for storing arr[i-1] * left[i-1] value.
       --> Use right array for storing arr[i+1] * right[i+1] value.
       --> Now store the product of left and right arrays in product array.
       --> Time Complexity : O(n), Space Complexity : O(n).

    2. Using Single product array : 
       --> Use a variable product to store the product of all variable.
       --> Count the number of zeros in the given array if the value of zeros is more than 1 then all the elements of the product array is zero.
       --> If only one element is zero then product for only that element exists.
       --> Time Complexity : O(n), Space Complexity : O(1).
*/
#include<iostream>
#include<vector>
using namespace std;

void getProduct(int n, vector<int> &nums, vector<int> &ans){
    //Without using division operator.

    vector<int> left(n), right(n);
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

    /* int zeroCount = 0;
    int product = 1;
    
    //Getting number of zeros present in the array.
    for(int i=0; i<n; i++){
        if(nums[i] != 0){
            product *= nums[i];
        }
        else{
            zeroCount++;
        }
    }

    //Computing ans array.
    for(int i=0; i<n; i++){
        if(zeroCount > 1){
            ans[i] = 0;
        }
        else if(zeroCount == 1 && nums[i] == 0){
            ans[i] = product;
        }
        else if(zeroCount == 0){
            ans[i] = product/nums[i];
        }
        else{
            ans[i] = 0;
        }
    } */

}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;

    //Taking user input.
    vector<int> nums(n);
    
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> ans(n);
    getProduct(n ,nums, ans);

    cout<<"Product array except self is :"<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}