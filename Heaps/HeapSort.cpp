//Time complexity : O(n*log(n)).
#include<iostream>
using namespace std;

void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size){
    for(int i=size/2-1; i>=0; i--){
        heapify(arr, size, i);
    }
    
    int n = size-1;
    while(n > 0){
        swap(arr[0],arr[n]);
        
        heapify(arr, n, 0);
        n--;
    }
}

int main()
{
    int arr[10] = {12,12,-1,0,-23,123,0,5457,3,2};

    heapSort(arr, 10);

    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}