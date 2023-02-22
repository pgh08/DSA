#include<iostream>
using namespace std;

int arraySum(int arr[], int n, int index){
    //Base case.
    if(index >= n){
        return 0;
    }
    int ans = arr[index] + arraySum(arr, n, index+1);
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,3,4,5};

    int index = 0;
    int ans = arraySum(arr, n, index);

    cout<<"Sum of an Array is : "<<ans<<endl;

    return 0;
}