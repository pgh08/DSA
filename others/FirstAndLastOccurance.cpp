#include<iostream>
using namespace std;

int FirstOcc(int arr[], int n, int target)
{
    int s = 0, e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == target){
            ans = mid;
            e = mid-1;
        }
        if (arr[mid] > target)
        {
            e = mid-1;
        }
        if (arr[mid] < target)
        {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int LastOccur(int arr[], int n, int target)
{
    int s = 0, e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;
    while (s<=e){
        if(arr[mid] == target){
            ans = mid;
            s = mid+1;
        }
        if (arr[mid] > target)
        {
            e = mid-1;
        }
        if (arr[mid] < target)
        {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    int arr[10] = {1,2,3,3,3,3,4,5,6,7};
    pair<int,int> p;
    p.first = FirstOcc(arr, 10, 3);
    p.second = LastOccur(arr, 10, 3);
    cout<<p.first<<" "<<p.second;
}