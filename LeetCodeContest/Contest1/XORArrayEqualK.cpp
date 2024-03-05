// You are given a 0-indexed integer array nums and a positive integer k.
// You can apply the following operation on the array any number of times:
//    -> Choose any element of the array and flip a bit in its binary representation. Flipping a bit means changing a 0 to 1 or vice versa.
// Return the minimum number of operations required to make the bitwise XOR of all elements of the final array equal to k.
// Note that you can flip leading zero bits in the binary representation of elements. For example, for the number (101)2 you can flip the fourth bit and obtain (1101)2.
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter the size of array and value of k"<<endl;
    cin>>n>>k; // 4 1.

    vector<int> nums(n, 0);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i]; // 2 1 3 4.
    }

    // Step 1 : Make XOR of all elements of array.
    int ans = nums[0];
    for(int i=1; i<n; i++){
        ans ^= nums[i];
    }

    // Step 2 : Check how many bits are different than k. (XOR of different bits will be one).
    ans ^= k;

    // Step 3 : Check how many bits are set now.
    ans = __popcount(ans);
    
    cout<<"Minimum number of flips required to make xor of array equal to k is : "<<ans<<endl;

    return 0;
}