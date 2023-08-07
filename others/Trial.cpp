#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {20,32,323,2,1,435,5,32,43,50};
    int minIndex;
    for(int i=0; i<10; i++){
        minIndex = i;
        for(int j=i+1; j<10; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}