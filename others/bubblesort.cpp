#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {321,23,1,4,3123,342,78567,1,66,2};
    int temp;
    for(int i=0; i<10-1; i++){
        for(int j=0; j<10-i-1; j++){
            if(arr[j] > arr[j+1]){
                /*temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;*/
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}