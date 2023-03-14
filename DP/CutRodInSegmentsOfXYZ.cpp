#include<iostream>
#include<limits.h>
using namespace std;

int solveRecursively(int rodLength, int x, int y, int z){
    // Base Case.
    if(rodLength == 0){
        return 0;
    }
    if(rodLength < 0){
        return INT_MIN;
    }

    int a = solveRecursively(rodLength-x, x, y, z) + 1;
    int b = solveRecursively(rodLength-y, x, y, z) + 1;
    int c = solveRecursively(rodLength-z, x, y, z) + 1;

    int ans = max(a, max(b, c));

    return ans;
}

int main()
{
    int rodLength;
    cout<<"Enter the rod Length"<<endl;
    cin>>rodLength;

    int x, y, z;
    cout<<"Enter the length of segments X, Y and Z"<<endl;
    cin>>x>>y>>z;

    int ans = solveRecursively(rodLength, x, y, z);

    cout<<"Maximum number of cuts is : "<<ans<<endl;

    return 0;
}