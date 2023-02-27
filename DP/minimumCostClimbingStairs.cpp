#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &cost, int n){
    //Base case.
    if(n <= 1){
        return cost[n];
    }
    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of stairs"<<endl;
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter the cost for climbing each stairs"<<endl;
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }

    int recursiveSolution = min(solve(cost, n-1), solve(cost, n-2));


    cout<<"Minimum cost to climb the stairs is : "<<recursiveSolution<<endl;

    return 0;
}