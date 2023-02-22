#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums = {{10,20,30},{5,10,20},{2,4,6}};
    vector<vector<int>> ans(nums.size(), vector<int>(nums[0].size(), 0));
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            if(i == 0 && j == 0){
                ans[i][j] = nums[i][j];
            }
            else if(i == 0 && j > 0){
                ans[i][j] = ans[i][j-1] + nums[i][j];
            }
            else if(i > 0 && j == 0){
                ans[i][j] = ans[i-1][j] + nums[i][j];
            }
            else{
                ans[i][j] = ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1] + nums[i][j];
            }
        }
    }

    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}