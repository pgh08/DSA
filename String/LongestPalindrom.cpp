#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){
    while(l < r){
        if(s[l++] != s[r--]){
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin>>s;

    unordered_set<char> uset;
    int left = 0, right = 0;
    int size = s.length();
    int ans = 1;
    string temp = s;
    reverse(temp.begin(), temp.end());

    if(s == temp){
        cout<<"Longest Palindrome is "<<size<<endl;
        return 0;
    }

    while(left < size && right < size){
        if(uset.find(s[right]) == uset.end()){
            uset.insert(s[right]);
            ans = max(ans, right-left+1);
            right++;
        }
        else{
            if(isPalindrome(s, left, right)){
                ans = max(ans, right-left+1);
            }
            else{
                uset.erase(s[left]);
                left++;
            }
        }
    }
    cout<<"Longest Palindrome is "<<ans<<endl;

    return 0;
}