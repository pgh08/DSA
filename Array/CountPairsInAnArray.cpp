// Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.
/* 
    Approach : 1. Construct array of i*arr[i].
               2. Use Merge Sort to count the number of times place of an integer in an array is changed before getting sorted.
               3. Time Complexity : O(n*log(n)), Space Complexity : O(n).
*/
#include<iostream>
using namespace std;

int merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    int firstLen = mid-s+1, secondLen = e-mid;
    int *first = new int[firstLen], *second = new int[secondLen];
    int index = s;

    for(int i=0; i<firstLen; i++){
        first[i] = arr[index++];
    }
    for(int i=0; i<secondLen; i++){
        second[i] = arr[index++];
    }

    index = s;
    int firstIndex = 0, secondIndex = 0;
    int count = 0;

    while(firstIndex < firstLen && secondIndex < secondLen){
        if(first[firstIndex] <= second[secondIndex]){
            arr[index++] = first[firstIndex++];
        }
        else{
            count += (firstLen-firstIndex);
            arr[index++] = second[secondIndex++];
        }
    }

    while(firstIndex < firstLen){
        arr[index++] = first[firstIndex++];
    }
    while(secondIndex < secondLen){
        arr[index++] = second[secondIndex++];
    }

    delete []first;
    delete []second;

    return count;
}

int mergeSort(int *arr, int s, int e){
    // Base Case.
    if(s >= e){
        return 0;
    }

    int ans = 0;
    int mid = s + (e-s)/2;

    ans += mergeSort(arr, s, mid);
    ans += mergeSort(arr, mid+1, e);
    ans += merge(arr, s, e);

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 7.

    int *arr = new int[n];
    cout<<"Enter the values of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i]; // 5 0 10 2 4 1 6.
    }

    // Step 1 : Construct i*arr[i] array.
    for(int i=0; i<n; i++){
        arr[i] *= i;
    }

    int ans = mergeSort(arr, 0, n-1);

    cout<<"Number of pairs are : "<<ans<<endl; // 5.

    return 0;
}