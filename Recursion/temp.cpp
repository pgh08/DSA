#include<iostream>
#include<vector>
using namespace std;

void getPermutationResult(string str, int index, int ansIndex, int n, vector<string> &ans){
    // Base Case.
    if(index >= n){
        int num = stoi(str);
        if(num%8 == 0){
            ans[ansIndex] = "YES";
        }
        return;
    }

    for(int i=index; i<n; i++){
        swap(str[i], str[index]);

        getPermutationResult(str, index+1, ansIndex, n, ans);

        swap(str[i], str[index]);
    }
}

int main()
{
    vector<string> s(5);
    for(int i=0; i<5; i++){
        cin>>s[i];
    }

    vector<string> ans(5, "NO");

    for(int i=0; i<5; i++){
        string str = s[i];
        int n = str.length();
        int index = 0;
        int ansIndex = i;
        getPermutationResult(str, index, ansIndex, n, ans);
    }

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}