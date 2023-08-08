#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

//  Copy value.
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }
//  Merge 2 sorted arrays.
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
//  If first array is larger in size.
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
//  If second array is larger in size.
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void mergesort(int arr[], int s, int e){
//  Base case.
    if(s >= e){
        return;
    }
    int mid = s + (e-s)/2;
//  Left part sort.
    mergesort(arr, s, mid);
//  Right part sort.
    mergesort(arr, mid+1, e);
//  Merge.
    merge(arr, s, e);
}

int main()
{
    int arr[6] = {29,1,4,23,231,2};

    mergesort(arr, 0, 6-1);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}