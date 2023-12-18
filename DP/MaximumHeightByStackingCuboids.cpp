// Given the cuboids find the maximum height by stacking one cuboid on another, 
// you can stack only if width,legth and height of base cuboid is larger than top cuboid. (A variant of LIS).
// Time Complexity : O(n^2), Space Complexity : O(n).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int> &base, vector<int> &top){
    if(base[0] >= top[0] && base[1] >= top[1] && base[2] >= top[2]){
        return true;
    }

    return false;
}

int solveLIS(vector<vector<int>> &cuboids, int &n){
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int index=n-1; index>=0; index--){
        for(int prevIndex=index-1; prevIndex>=-1; prevIndex--){
            int take = 0;

            if(prevIndex == -1 || check(cuboids[index], cuboids[prevIndex])){
                take = cuboids[index][2] + next[index+1];
            }

            int notTake = 0 + next[prevIndex+1];

            curr[prevIndex+1] = max(take, notTake);
        }
        next = curr;
    }

    return next[0];
}

int main()
{
    int n; // 3.
    cout<<"Enter the number of cuboids"<<endl;
    cin>>n;

    vector<vector<int>> cuboids(n, vector<int> (3, 0)); // [[50,45,20],[95,37,53],[45,23,12]].
    cout<<"Enter the dimensions of the cuboids"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>cuboids[i][j];
        }
    }

    // Step 1 : Sort each row.
    for(auto &a : cuboids){
        sort(a.begin(), a.end());
    }

    // Step 2 : Sort cuboids.
    sort(cuboids.begin(), cuboids.end());

    // Step 3 : Apply LIS Logic.
    int ans = solveLIS(cuboids, n);

    cout<<"Maximum height after stacking cuboids is : "<<ans<<endl;

    return 0;
}