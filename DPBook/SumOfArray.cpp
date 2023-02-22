#include<bits/stdc++.h>
using namespace std;

void prefixSumArray(int *arr, int n, int index){
    //Base case.
    if(index == n){
        return;
    }
    arr[index] += arr[index-1];
    prefixSumArray(arr, n, index+1);
}

int main()
{
    int arr[6] = {1,2,3,4,5,6};

    prefixSumArray(arr, 6, 1);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}