//Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//Return the sorted array.
/* Algorithm : 
   1. Store all the values in map.
   2. Make a vector of pair type and store array element and their respective frequency.
   3. Sort the vector using comparator as third parameter in sort function.
   4. Time complexity : O(n) and Space complexity : O(n).
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Value must be static.
static bool compare(pair<int,int> &a, pair<int,int> &b){
    //If frequency is equal compare based on element value(decreasing).
    if(a.second == b.second){
        return a.first > b.first;
    }   
    return a.second < b.second;
}

int main()
{
    vector<int> num = {1,1,2,2,2,3};
    int n = num.size();

    //Number to frequency map.
    map<int,int> NumToFreq;
    
    for(int i=0; i<n; i++){
        NumToFreq[num[i]]++;
    }

    //Vector for storing pairs of data from map.
    vector<pair<int,int>> ans;
    for(auto pr: NumToFreq){
        ans.push_back(pr);
    }

    sort(ans.begin(),ans.end(),compare);
    
    int size = ans.size();

    for(int j=0; j<size; j++){
        int i = 0;
        while(i < ans[j].second){
            cout<<ans[j].first<<" ";
            i++;
        }
    }
    cout<<endl;

    return 0;
}