//Given two heaps merge those two heaps.
/*
Algorithm : 
    1. Merge those to heaps to form a single array.
    2. heapify the above resulting array.
    3. Time Complexity : O(m+n), Space complexity : O(m+n).
*/
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &ans, int n, int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && ans[left] > ans[largest]){
        largest = left;
    }
    if(right < n && ans[right] > ans[largest]){
        largest = right;
    }

    if(largest != index){
        swap(ans[largest],ans[index]);
        heapify(ans, n, largest);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of heap array 1"<<endl;
    cin>>n;
    vector<int> num1(n);
    cout<<"Enter the heap array 1 "<<endl;
    for(int i=0; i<n; i++){
        cin>>num1[i];
    }

    int m;
    cout<<"Enter the size of heap array 2"<<endl;
    cin>>m;
    vector<int> num2(m);
    cout<<"Enter the heap array 2 "<<endl;
    for(int i=0; i<m; i++){
        cin>>num2[i];
    }
    
    //Merged array.
    vector<int> ans;

    for(auto i: num1){
        ans.push_back(i);
    }
    for(auto j: num2){
        ans.push_back(j);
    }

    //Heapifing.
    int size = ans.size();

    for(int i=size/2-1; i>=0; i--){
        heapify(ans, size, i);
    }

    for(int i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}