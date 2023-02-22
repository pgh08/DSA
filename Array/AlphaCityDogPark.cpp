//Given a park of N dog houses and Ith transfer index transfer all the dogs to that index and return number of steps required.
#include<iostream>
using namespace std;

int main()
{
    int N = 3;
    int I = 3;
    int ans = 0;
    int arr[3] = {1,1,0}; 

    for(int i=0; i<N; i++){
        ans = ans + abs(I-i-1)*arr[i];
    }

    cout<<ans<<endl;

    return 0;
}