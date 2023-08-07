// Given the string find its all the permutation.
// Recursive Solution : Time Complexity : O(n*n!), Space Complexity : O(R-L).
#include<iostream>
#include<vector>
using namespace std;

void getPermutations(string s, int index, int n, vector<string> &ans){
    // Base Case.
    if(index >= n){
        ans.push_back(s);
        return;
    }

    for(int i=index; i<n; i++){
        swap(s[i], s[index]);

        getPermutations(s, index+1, n, ans);

        swap(s[i], s[index]);
    }
}

int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
    int n = s.length();

    vector<string> ans;

    getPermutations(s, 0, n, ans);

    cout<<"All the permuation of "<<s<<" are : "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}