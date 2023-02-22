#include<bits/stdc++.h>
using namespace std;

void findBinary(int *arr, int s, int e, int key, int &ans){
    int mid = s + (e-s)/2;
    while(s <= e){
        if(arr[mid] == key){
            ans = mid;
            return;
        }
        if(arr[mid] >= key){
            ans = min(ans,mid);
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
}

int main()
{
    int arr[5] = {1,2,3,5,8};
    int ans = 5-1;
    int threshold = 4;
    
    if(threshold+arr[0] > arr[4]){
        return 5;
    }

    int key = threshold + arr[0];
    
    findBinary(arr, 0, 4, key, ans);

    cout<<ans<<endl;

    return 0;
}