// Given two integer array of different size. Find elements which are present in array 1 and missing in array 2.
// Time Complexity : O(m+n), Space Complexity : O(m).
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> getMissingNumbers(vector<int> &nums1, vector<int> &nums2, int &n, int &m){
    vector<int> ans;
    unordered_set<int> uset(nums2.begin(), nums2.end());

    for(int i=0; i<n; i++){
        if(!uset.count(nums1[i])){
            ans.push_back(nums1[i]);
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cout<<"Enter the size of first and second array"<<endl;
    cin>>n>>m; // 6 5.

    vector<int> nums1(n, 0), nums2(m, 0);
    cout<<"Enter the elements of array 1"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums1[i]; // 1 2 3 4 5 10.
    }

    cout<<"Enter the elements of array 2"<<endl;
    for(int i=0; i<m; i++){
        cin>>nums2[i]; // 2 3 1 0 5.
    }

    vector<int> ans = getMissingNumbers(nums1, nums2, n, m);

    cout<<"Missing elements are : "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}