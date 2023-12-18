#include<iostream>
using namespace std;

void allCombinations(string &s, int index, string temp, int &n){
    // Base Case.
    if(index >= n){
        cout<<temp<<" ";
        return;
    }

    // Include.
    temp += s[index];
    allCombinations(s, index+1, temp, n);
    temp.pop_back();

    // Exclude.
    allCombinations(s, index+1, temp, n);
}

int main()
{
    string s = "ABC";
    int n = s.length();
    string temp = "";

    allCombinations(s, 0, temp, n);
    
    cout<<endl;

    return 0;
}