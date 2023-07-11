//Given the array find the K'th largest sum of the sub array.
/*
Approach : 
    1. Brute Force : 
        -->Store sum of each sub array using 2 loops.
        -->Sort the sum array.
        -->Return the k'th element. Time complexity : O(n^2log(n)), Space complexity : O(n^2).
    2. Using Min Heap :
        -->Use same for loop but optimize space using priority queue.
        -->Use same logic as K'th greatest element. Time complexity : O(n^2log(k)), Space complexity : O(k).
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void makeSum(vector<int> nums, vector<int> &Sumstore, int n){
    for(int i=0; i<n; i++){
        Sumstore.push_back(nums[i]);
        int sum = nums[i];
        for(int j=i+1; j<n; j++){
            sum += nums[j];
            Sumstore.push_back(sum);
        }
    }
}

int main()
{
    int n;
    vector<int> nums(n);
    cout<<"Enter the array length"<<endl;
    cin>>n;

    cout<<"Enter the data"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    /* vector<int> Sumstore;
    //Step 1 :
    makeSum(nums, Sumstore, n);*/

    int K;
    cout<<"Enter the value of K"<<endl;
    cin>>K;

    /*//Step 2 :
    sort(Sumstore.begin(),Sumstore.end());
    cout<<"K'th largest sum is : "<<Sumstore[K-1]<<endl; */

    priority_queue<int, vector<int>, greater<int>> mini;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(mini.size() < K){
                mini.push(sum);
            }
            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    cout<<"K'th largest sum is : "<<mini.top()<<endl; 

    return 0;
}