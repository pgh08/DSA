//Coding Ninja's Problem.
#include<bits/stdc++.h>
using namespace std;

void solution(string str, vector<string>& res, string output, int index){
//  Base case.
    if(index >= str.size()){
        res.push_back(output);
        return;
    }
//  Excluded.
    solution(str, res, output, index+1);
//  Included.
    char element = str[index];
    output.push_back(element);
    solution(str, res, output, index+1);
}

vector<string> subsequence(string str){
    vector<string> res;
    string output;
    int index = 0;
    solution(str, res, output, index);
    return res; 
}

int main()
{
    string str = "abc";

    vector<string> ans = subsequence(str);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}