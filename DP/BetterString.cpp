#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int solve(string s, int i, int &n, vector<int> &dp, unordered_set<string> &uset, string temp){
    // Base Case.
    if(i >= n){
        uset.insert(temp);
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    int exclude = 0 + solve(s, i+1, n, dp, uset, temp);
    
    int include = 0;
    temp += s[i];
    if(uset.find(temp) == uset.end()){
        include = 1 + solve(s, i+1, n, dp, uset, temp);
    }

    return dp[i] = exclude+include;
}

int main()
{
    string s1 = "", s2 = "";
    cout<<"Enter the string"<<endl;
    cin>>s1>>s2;

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> dp(n1+1, -1);
    unordered_set<string> uset;
        
    int count1 = solve(s1, 0, n1, dp, uset, "");

    cout<<"Total possible string count is : "<<count1<<endl;

    return 0;
}