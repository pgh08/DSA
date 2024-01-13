// Smallest Missing Integer Greater Than Sequential Prefix Sum

// You are given a 0-indexed array of integers nums.
// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.
// Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

// Hashing Approach : Time Complexity : O(n), Space Complexity : O(n).
// Sorting Approach : Time Complexity : O(n*log(n)), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int getMinMissingIntegerHash(vector<int> &nums, int &n){
    // Step1 : Store sum until array is sequential.
    int sum = nums[0];
    int i = 1;
    while(i<n && nums[i] == nums[i-1]+1){
        sum += nums[i];
        i++;
    }

    // Step2 : Store array elements in a set.
    unordered_set<int> numStore(nums.begin(), nums.end());

    // Step3 : Increment sum until sum is not found in set.
    while(numStore.count(sum)){
        sum++;
    }
    
    return sum;
}

int getMinMissingIntegerSort(vector<int> &nums, int &n){
    // Step1 : Store sum until array is sequential.
    int sum = nums[0];
    int i = 1;
    while(i<n && nums[i] == nums[i-1]+1){
        sum += nums[i];
        i++;
    }

    // Step2 : Sort the array.
    sort(begin(nums), end(nums));

    // Step3 : If sum is equal to array element increment sum.
    for(int i=0; i<n; i++){
        if(nums[i] == sum){
            sum++;
        }
    }

    return sum;
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 7.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 3 4 5 1 12 14 13.
    }

    // Hashing Approach.
    // int ans = getMinMissingIntegerHash(nums, n);

    // Sorting Approach.
    int ans = getMinMissingIntegerSort(nums, n);

    cout<<"Smallest Missing Integer is : "<<ans<<endl; // 15.

    return 0;
}