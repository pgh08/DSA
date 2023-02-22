#include<iostream>
using namespace std;

bool isSorted(int *arr, int n){
    if(n <= 1){
        return true;
    }
    return isSorted(arr, n-1)&(arr[n-1]>=arr[n-2]);
}

int main()
{
    int n = 10;
    int arr[n] = {1,2,3,4,5,6,7,8,9,10};

    if(isSorted(arr, n)){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}