#include<bits/stdc++.h>
using namespace std;

string binary_search(int arr[],int key,int n)
{
    int start=0,end;
    end = n;

    while (start<=end)     
    {   
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return "Found";
        }
        if(arr[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    } 
    return "Not Found";
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
//    sort(arr,arr+n);
    int key;
    cin>>key;
    cout<<binary_search(arr,key,n);
    return 0;
}