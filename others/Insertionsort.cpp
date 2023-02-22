#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {321,23,1,4,3123,342,78567,1,66,2};
    int temp;
    for(int i=1; i<10; i++){
        temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}