#include<iostream>
#include<vector>
using namespace std;

void permutation(string str, int index, int size, vector<string> &ans, int ansIndex){
    //Base case.
    if(index >= size){
        int num = stoi(str);
        if(num%8 == 0){
            ans[ansIndex] = "YES";
        }
        return;
    }
    for(int i=index; i<size; i++){
        swap(str[i], str[index]);
        permutation(str, index+1, size, ans, ansIndex);
        //Backtracking.
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

    for(int i=0; i<s.size(); i++){
        string str = s[i];
        int index = 0;
        int size = str.size();
        int ansIndex = i;
        permutation(str, index, size, ans, ansIndex);
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}