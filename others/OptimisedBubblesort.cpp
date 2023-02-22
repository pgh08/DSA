//Bubble sort using recursion.
/*#include<bits/stdc++.h>
using namespace std;

void Bubblesort(int arr[], int n)
{
    if(n == 0 || n == 1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    Bubblesort(arr,n-1);
}

int main()
{
    int arr[10] = {10,2,349,3,39,423,1,34,3453,1};
    Bubblesort(arr,10);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/

//Using Boolean swap variable(let's say array is already sorted in ith round).
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {10,2,349,3,39,423,1,34,3453,1};
    bool swapped;
    for(int i=0; i<9; i++){
        swapped = false;
        for(int j=0; j<10-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}