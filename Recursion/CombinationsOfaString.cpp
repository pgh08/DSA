//Given a string find all possible combination of that string i.e powerset of that string.
/*
Algorithm:
1. Bit manipulation : 
    -->(1 << n) gives us the 2 power 'n' combination.
    -->num & (1 << i) will help us to include the particular character of the string.
    -->Time Complexity : O(2^n * n), Space Complexity : O(1).

2. Optimized method (Recursion and Backtracking):
    -->Time Complexity : O(2^n), Space Complexity : O(n).
*/

/* #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> allPossibleCombination(string s){
    int n = s.length();
    vector<string> ans;
    for(int num=0; num<(1<<n); num++){
        string sub = "";
        for(int i=0; i<n; i++){
            if(num & (1<<i)){
                sub += s[i];
            }
        }
        ans.push_back(sub);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "ABC";

    vector<string> ans = allPossibleCombination(s);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
} */

#include<iostream>
#include<vector>
using namespace std;

void combinations(string s, int index, string temp, vector<string> &ans, int size){
    //Base case.
    if(index >= size){
        ans.push_back(temp);
        return;
    }
    //Exclude.
    combinations(s, index+1, temp, ans, size);
    //Include.
    char element = s[index];
    temp += element;
    combinations(s, index+1, temp, ans, size);
}

int main()
{
    string s = "ABC";
    int size = s.size();

    vector<string> ans;
    string temp = "";

    int index = 0;

    combinations(s, index, temp, ans, size);

    int n = ans.size();

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}