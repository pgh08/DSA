// Given the integers in an array find the next smallest palindrome.
// Time Complexity : O(n).
// Space Complexity : O(1).
#include<iostream>
using namespace std;

bool isAll9s(int *num, int &n){
    for(int i=0; i<n; i++){
        if(num[i] != 9){
            return false;
        }
    }

    return true;
}

int main()
{   
    int n = 11;

    int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};

    // Check whether all the elements are 9.
    if(isAll9s(num, n)){
        cout<<"1 ";
        for(int i=1; i<n; i++){
            cout<<"0 ";
        }
        cout<<"1"<<endl;
        return 0;
    }

    int mid = n/2;
    int i = mid-1;
    int j = (n%2) ? mid+1 : mid;
    bool leftSmaller = false;

    while(i >= 0 && num[i] == num[j]){
        i--;
        j++;
    }

    if(i < 0 || num[i] < num[j]){
        leftSmaller = true;
    }

    while(i >= 0){
        num[j] = num[i];
        i--;
        j++;
    }

    if(leftSmaller){
        int carry = 1;
        i = mid - 1;

        if(n%2 == 1){
            num[mid] += carry;
            carry = num[mid]/10;
            num[mid] %= 10;
            j = mid+1;
        }
        else{
            j = mid;
        }

        while(i >= 0){
            num[i] += carry;
            carry = num[i]/10;
            num[i] %= 10;

            num[j++] = num[i--];
        }
    }

    for(int i=0; i<n; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    return 0;
}