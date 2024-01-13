// Minimum Number of Steps to Make Two Strings Anagram.
// You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
// Return the minimum number of steps to make t an anagram of s.
// An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

// Time Complexity : O(n), Space Complexity : O(n).
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    string s, t;
    cout<<"Enter the value of s and t"<<endl;
    cin>>s>>t;

    // Step1 : Store all the characters of s with their respective count.
    unordered_map<char,int> charToCount;
    for(auto i : s){
        charToCount[i]++;
    }

    // Step2 : Decrement count of the characters which are common between s and t.
    for(auto i : t){
        if(charToCount[i] != 0){
            charToCount[i]--;
        }
    }

    // Step3 : Count the frequency of the remaining characters.
    int ans = 0;
    for(auto pr : charToCount){
        ans += pr.second;
    }

    cout<<"Minimum number of operation required is : "<<ans<<endl;

    return 0;
}