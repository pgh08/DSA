#include<iostream>
using namespace std;

int main()
{
    int arr[6] = {16,17,4,3,5,2};
    int maxi = arr[6-1];
    cout<<maxi<<" ";
    for(int i=6-2; i>=0; i--){
        if(maxi <= arr[i]){
            maxi = arr[i];
            cout<<maxi<<" ";
        }
    }
    return 0; 
}