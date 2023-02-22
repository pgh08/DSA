#include<iostream>
using namespace std;

bool palindrome(string str, int i, int j){
//  Base case.
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    else{
        return palindrome(str, i+1, j-1);
    }
}

int main()
{
    string input = "ABBcA";

    bool ans = palindrome(input, 0, 3);
    if(ans){
        cout<<"It is Palindrome"<<endl;
    }
    else{
        cout<<"Not a Palindrome"<<endl;
    }

    return 0;
}