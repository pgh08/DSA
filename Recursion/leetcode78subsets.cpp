#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> a, int index, vector<int> output, vector<vector<int>>& result){
//  Base case.
    if(index >= a.size()){
        result.push_back(output);
        return;
    }
//  Exclude.
    solve(a, index+1, output, result);
//  Include.
    int element = a[index];
    output.push_back(element);
    solve(a, index+1, output, result);
    
}

vector<vector<int>> subsets(vector<int> a){
    vector<vector<int>> result;
    vector<int> output;
    int index = 0;
    solve(a, index, output, result);
    return result; 
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int>> ans = subsets(arr);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}