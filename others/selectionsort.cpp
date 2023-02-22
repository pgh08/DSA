#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {20,32,323,2,1,435,5,32,43,50};
    int minindex;
    for(int i=0; i<9; i++){
        minindex = i;
        for (int j = i+1; j < 10; j++)
        {
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
    for (int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}