// Given a 2D array of height and width find all which can fit into another envelopes.
// To fit both height and width of one envelope must be greater than another envelope.
// DP + Binary search Approach : Time Complexity : O(n*log(n)), Space Complexity : O(1).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> &v1, vector<int> &v2){
    // If height of the envelopes are equal sort them descending based on their height.
    if(v1[0] == v2[0]){
        return v1[1] > v2[1];
    }

    // If height of envelopes are not equal sort them asecnding based on their width.
    return v1[0] < v2[0];
}

int LISDPBinarySearch(vector<vector<int>> &envelopes, int &n){
    if(n == 0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(envelopes[0][1]);

    for(int i=1; i<n; i++){
        int num = envelopes[i][1];

        if(num > ans.back()){
            ans.push_back(num);
        }
        else{
            int index = lower_bound(ans.begin(), ans.end(), num) - ans.begin();

            ans[index] = num;
        }
    }

    return ans.size();
}

int main()
{
    int n; // 4
    cout<<"Enter the size of the 2D matrix"<<endl;
    cin>>n;

    vector<vector<int>> envelopes(n, vector<int> (2, 0)); // [[5,4],[6,4],[6,7],[2,3]].
    cout<<"Enter the height and width of the envelopes"<<endl;
    for(int i=0; i<n; i++){
        cin>>envelopes[i][0]; // Width.
        cin>>envelopes[i][1]; // Height.
    }

    // Step 1 : Sort the envelopes based on their width, if same width sort them in decreasing order of their height.
    sort(envelopes.begin(), envelopes.end(), compare);
    
    // Step 2 : Apply Longest Increasing Subsequence (LIS) on the heights of the above envelopes.
    // Applying Optimized approach. (DP + Binary Search).

    int ans = LISDPBinarySearch(envelopes, n);

    cout<<"Number of envelopes which can be fit into another envelopes are : "<<ans<<endl;

    return 0;
}