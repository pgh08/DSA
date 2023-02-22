//Given an array of elements heapify it.
/*
Algorithm : 
    1. Leave all the leaf nodes because they are already heapified.
    2. So for loop runs from n/2 to 0.
    3. In heapify function it swaps largest element with index i for each for loop run.
    4. Time Complexity : O(n), Space complexity : O(log(n)).
*/
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2+1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n = 6-1;

    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"Array after heapifying"<<endl;

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}