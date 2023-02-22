#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[3] = {10,15,20};
    int one = 0;
    int two = 0;
    for(int i=2; i<=3; i++){
        int temp = one;
        one = min(one+arr[i-1], two+arr[i-2]);
        two = temp;
    }
    cout<<"Minimum cost is "<<one<<endl;

    return 0;
}