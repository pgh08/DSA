#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int signum(int a, int b){
    if(a == b){
        return 0;
    }
    if(a > b){
        return 1;
    }
    return -1;
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    
    switch(signum(maxHeap.size(), minHeap.size())){
        
        case 0: if(element > median){
                    minHeap.push(element);
                    median = minHeap.top();
                }
                else{
                    maxHeap.push(element);
                    median = maxHeap.top();
                }
            break;

        case 1: if(element > median){
                    minHeap.push(element);
                    median = (minHeap.top() + maxHeap.top())/2;
                }
                else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                    median = (minHeap.top() + maxHeap.top())/2;
                }
            break;
        
        case -1: if(element > median){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);
                    median = (minHeap.top() + maxHeap.top())/2;
                }
                else{
                    maxHeap.push(element);
                    median = (minHeap.top() + maxHeap.top())/2;
                }
            break;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;

    for(int i=0; i<n; i++){
        callMedian(nums[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    cout<<"Median after insertion of each elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}