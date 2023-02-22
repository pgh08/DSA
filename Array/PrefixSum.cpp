#include<iostream>
using namespace std;

int main()
{
    int arr[] = {10,20,10,5,15};
    int prefixSum[5];
    prefixSum[0] = arr[0];

    cout<<prefixSum[0]<<" ";
    
    for(int i=1; i<5; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
        cout<<prefixSum[i]<<" ";
    }
    return 0;
}