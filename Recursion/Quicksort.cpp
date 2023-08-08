#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
//  Placing element at its right position.
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        
    //  Checking whether their is an element in the left part of the pivot.
        while(arr[i] <= pivot){
            i++;
        }
    //  Checking whether their is an element in the left part of the pivot.
        while(arr[j] > pivot){
            j--;
        }
    //  If any element present swap those 2 elements.
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quicksort(int *arr, int s, int e){
//  Base condition.
    if(s >= e){
        return;
    }
//  Creating a partion.
    int p = partition(arr, s, e);
//  Sorting left part.
    quicksort(arr, s, p-1);
//  Sorting right part.
    quicksort(arr, p+1, e);
}

int main()
{
    int arr[10] = {2,4,1,6,9,212321,-1,232,2,123};
    int n = 10;

    quicksort(arr, 0 ,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}