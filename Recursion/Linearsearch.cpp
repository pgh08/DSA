#include<iostream>
using namespace std;

pair<bool,int> findElement(int arr[], int n, const int key){
    //Base case.
    if(n < 0){
        return {false, -1};
    }
    if(arr[n] == key){
        return {true, n+1};
    }
    return findElement(arr, n-1, key);
}

int main()
{
    int n = 10;
    int arr[n] = {1,2,3,4,5,6,7,8,9,10};

    int k;
    cout<<"Enter element to be found"<<endl;
    cin>>k;

    if(findElement(arr, n-1, k).first){
        cout<<"Element found at position : "<<findElement(arr, n-1, k).second<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    return 0;
}