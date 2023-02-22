//You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
//For each index i, names[i] and heights[i] denote the name and height of the ith person.
//Return names sorted in descending order by the people's heights.
/* Algorithm : 
   1. Store all the height values in map (height as key and name as value).
   2. Make a vector of pair type and store heights and their respective names.
   3. Sort the vector using comparator as third parameter in sort function.
   4. Time complexity : O(n) and Space complexity : O(n).
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Value must be static.
static bool compare(pair<int,string> &a, pair<int,string> &b){
    return a.first > b.first;
}

int main()
{
    vector<string> names = {"Alice","Bob","Bob"};
    vector<int> heights = {155,185,150};
    int n = names.size();
    //Ordered map with key as height and name as value.
    map<int,string> HeightToName;

    for(int i=0; i<n; i++){
        HeightToName[heights[i]] = names[i];
    }

    //Vector for sorting.
    vector<pair<int,string>> ans;

    for(auto it: HeightToName){
        ans.push_back(it);
    }
    sort(ans.begin(),ans.end(),compare);
    
    int size = ans.size();

    for(int i=0; i<size; i++){
        cout<<ans[i].second<<" ";
    }
    cout<<endl;

    return 0;
}