// GFG Problem : Given an array of integers of size n and an integer k, compute answer such that difference between maximum and minimum
// of the array after removing subarray of size k is minimized.
/* Approach : 
        1. Brute Force : 
                        --> Use 2 loop and find difference between minimum and maximum after each iteration.
                        --> Minimize the difference.
                        --> Time Complexity : O(n^2), Space Complexity : O(1).

        2. Using Hashing :
                        --> Use 4 arrays to store 2 for left computation and 2 for right computation.
                        --> For left computation minimum till current index array and maximum till current index array.
                        --> For right computation minimum till current index array and maximum till current index array iterating in reverse.
                        --> Now Use another loop to iterate till n-k and find difference between maximum and minimum using above 2 array.
                        --> Time Complexity : O(n), Space Complexity : O(n).
 */
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int bruteForce(vector<int> &nums, int &n, int &k){
    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int j=0; j<n; j++){
            if(!(j >= i && j < i+k)){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
            }
        }
        cout<<mini<<" "<<maxi<<endl;
        ans = min(ans, maxi-mini);
    }

    return ans;
}

int minimizeDiff(vector<int> &nums, int &n, int &k){
    int ans = INT_MAX;

    vector<int> maxLeft(n, 0), minLeft(n, 0);
    maxLeft[0] = minLeft[0] = nums[0];
    // Computing Left maxium and minimum till current index.
    for(int i=1; i<n; i++){
        minLeft[i] = min(minLeft[i-1], nums[i]);
        maxLeft[i] = max(maxLeft[i-1], nums[i]);
    }

    vector<int> maxRight(n, 0), minRight(n, 0);
    maxRight[n-1] = minRight[n-1] = nums[n-1];
    // Computing right maxium and minimum till current index.
    for(int i=n-2; i>=0; i--){
        minRight[i] = min(minRight[i+1], nums[i]);
        maxRight[i] = max(maxRight[i+1], nums[i]);
    }

    for(int i=0; i<=n-k; i++){
        int leftIndex = i-1;
        int rightIndex = i+k;
        int mini = INT_MAX, maxi = INT_MIN;

        if(leftIndex >= 0){
            mini = min(minLeft[leftIndex], mini);
            maxi = max(maxLeft[leftIndex], maxi);
        }
        if(rightIndex < n){
            mini = min(minRight[rightIndex], mini);
            maxi = max(maxRight[rightIndex], maxi);
        }

        ans = min(ans, maxi-mini);
    }

    return ans;
}

int main()
{
    int n, k;
    cout<<"Enter the size of the array and value of k"<<endl;
    cin>>n>>k; // 6, 3.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 2 3 1 4 6 7.
    }

    // int ans = bruteForce(nums, n, k);

    int ans = minimizeDiff(nums, n, k);

    cout<<"Minimum difference is : "<<ans<<endl; // 2.

    return 0;
}