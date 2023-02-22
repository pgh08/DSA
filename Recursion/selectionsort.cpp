#include<iostream>
using namespace std;

int minimumIndex(int *arr, int i, int j){
    if(i == j){
        return i;
    }
    int k = minimumIndex(arr, i+1, j);

    return (arr[i] < arr[k])? i : k;
}

void selectionSort(int *arr, int n, int index = 0){
    if(index == n){
        return;
    }
    int k = minimumIndex(arr, index, n-1);

    if(k != index){
        swap(arr[index],arr[k]);
    }
    selectionSort(arr, n, index+1);
}

int main()
{
    int arr[5] = {6,1,20,12,3};

    selectionSort(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}