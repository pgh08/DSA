//Finding largest sum continuous subarray.
#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSumSoFar = INT_MIN, maxEndingHere = 0;
    int s = 0, start = 0, end = 0;

    for(int i=0; i<n; i++){
        maxEndingHere += arr[i];

        if(maxSumSoFar < maxEndingHere){
            maxSumSoFar = maxEndingHere;
            start = s;
            end = i;
        }
        if(maxEndingHere < 0){
            maxEndingHere = 0;
            s = i+1;
        }
    }

    cout<<"Maximum possible sum is : "<<maxSumSoFar<<endl;
    cout<<"Start position is : "<<start<<" End position is : "<<end<<endl;

    return 0;
}