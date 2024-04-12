// Given an array of integers find the sum of bitwise and of all possible pairs.
/* Approach :
        1. Brute Force :
           --> Use 2 for loop for iterating all possible pairs.
           --> Get bitwise AND of all pairs and add it to the sum. 
           --> Time Complexity : O(n^2), Space Complexity : O(1).

        2. Using Permutation :
           --> Since every array element is 32 bit use outer loop to iterate through all the 32 bit elements.
           --> For k set bits their are kC2 = k*(k-1)/2 possible pairs.
           --> Each pair adds 2^i to the sum.
           --> Using above points we can conclude that sum = sum + (2^i)*(k*(k-1)/2);
           --> Time Complexity : O(n), Space Complexity : O(1).          
*/
#include<iostream>
using namespace std;

int solveBruteForce(int &n, int *arr){
    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum += arr[i]&arr[j];
        }
    }

    return sum;
}

int solvePermutation(int *arr, int &n){
    int sum = 0;

    for(int i=0; i<32; i++){
        int k = 0;
        for(int j=0; j<n; j++){
            if(arr[j] & (1<<i)){
                k++;
            }
        }

        sum += (1<<i)*(k*(k-1)/2);
    }

    return sum;
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n; // 5.

    int *arr = new int[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i]; // 5 10 15.
    }

    // int sum = solveBruteForce(n, arr);

    int sum = solvePermutation(arr, n);

    cout<<"Sum of all possible bitwise AND pairs is : "<<sum<<endl; // 15.

    return 0;
}