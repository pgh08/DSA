//Given a array of elements find the Kth smallest element.
/*
Algorithm  : 
    1. Sort the array and find the 3rd smallest element using linear search. Time complexity : O(nlog(n)), Space complexity : O(1).
    2. Using the Max Heap (Priority Queue). 
    3. Step 1: Push 'K' elements of an array into priority queue.
    4. Step 2: If next element of the array is less than priority queue's top then pop that top and push that element of the array.
    5. The resulting queue will have size = K and top of the queue will be the answer. Time complexity : O(klog(k)+(n-k)log(k)), Space complexity : O(K).
*/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//Approach 1 : By sorting.
/* int kthSmallestBySort(int arr[], int k, int n){
    sort(arr,arr+n);

    //Performing linear search.
    int ans = 0;
    int count = 1;
    for(int i=0; i<n-1; i++){
        if(count == k){
            ans = arr[i];
            break;
        }
        if(arr[i] != arr[i+1]){
            count++;
        }
    }
    if(ans == 0){
        ans = arr[n-1];
    }
    return ans;
} */

//Approach 2 : Using Heap.
int kthSmallestBySort(int *arr, int k, int n){
    priority_queue<int> pq;

    //Step 1 : 
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    //Step 2 :
    int ans = 0;
    for(int i=k; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    //Step 3 :
    ans = pq.top();
    return ans;
}

int main()
{
    int n = 6;
    int arr[6] = {7,7,20,10,3,15};

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    int ans = kthSmallestBySort(arr, k, n);

    cout<<"Kth smallest element is : "<<ans<<endl;

    return 0;
}