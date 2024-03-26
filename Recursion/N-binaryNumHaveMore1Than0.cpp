// Given a integer n find all possible binary combination of n-bit having prefix as 1 and number of ones in the combination is greater than zero for any prefix of zero.
#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

void solve(string temp, vector<string> &ans, int n, int oneCount, int zeroCount){
    // Base Case.
    if(n <= 0){
        ans.push_back(temp);
        return;
    }

    // Take one.
    solve(temp+"1", ans, n-1, oneCount+1, zeroCount);

    // Take zero.
    if(oneCount > zeroCount){
        solve(temp+"0", ans, n-1, oneCount, zeroCount+1);
    }
}

int main()
{
    int n;
    cout<<"Enter the value of the integer"<<endl;
    cin>>n;

    vector<string> ans;
    string temp = "1";

    // Start time.
    auto start = high_resolution_clock::now();

    solve(temp, ans, n-1, 1, 0);

    // End time.
    auto end = high_resolution_clock::now();

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    // Calculate duration of the function.
    auto duration = duration_cast<microseconds> (end-start);

    cout<<"Time taken by solve function is : "<<duration.count()<<" microseconds"<<endl;

    return 0;
}